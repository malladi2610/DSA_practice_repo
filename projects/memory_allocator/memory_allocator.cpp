/*Creating a custom dynamic memory allocator */


#include <cstddef> /*What is this library ?*/
#include<iostream>
using namespace std;

class MemoryAllocator{
private:
    struct Block{
        size_t size;
        bool free;
        Block* next;

    };
    Block* head;
    static const size_t pool_size = 1024;
    char memoryPool[pool_size];

public:

    /*MemoryAllocator() sets up the memory pool with the head block 
    marked as free and with the entire pool size available.*/
    MemoryAllocator() : head(nullptr) {
        /*This cast interprets the start of memoryPool as a Block*, allowing us to treat the memory pool as a list of blocks. 
        It sets head to the beginning of memoryPool, enabling us to access the metadata and manage memory blocks.*/             
        head = reinterpret_cast<Block*>(memoryPool);
        head->size = pool_size - sizeof(Block);
        head->free = true;
        head->next = nullptr;

    }
    void* allocate(size_t size);
    void free(void* ptr);
    void displayPool();

};


void* MemoryAllocator::allocate(size_t size){
    Block* current = head;

    while (current != nullptr) {
        if(current->free && current->size >= size) { //Check for a free block
            size_t remainingSize = current->size - size - sizeof(Block); // How it this operation happening ?(Understand with a dry run)

            if(remainingSize > 0){
                Block* newBlock = reinterpret_cast<Block*>(
                    reinterpret_cast<char*>(current) + sizeof(Block) + size
                );
                newBlock->size = remainingSize;
                newBlock->free = true;
                newBlock->next = current->next;
                current->next = newBlock;
                current->size = size;
            }

            current->free = false;
            return reinterpret_cast<char*>(current) + sizeof(Block);
        }
        current = current->next;
    }

    cerr<< "Memeory allocation failed: No sufficient space available" <<std::endl;
    return nullptr;
}

void MemoryAllocator::free(void* ptr) {
    if(!ptr) return;

    Block* blockToFree = reinterpret_cast<Block*>(reinterpret_cast<char*>(ptr) - sizeof(Block));
    blockToFree->free = true;

    // Coalescing: Merge adjacent free blocks
    Block* current = head;
    while (current != nullptr){
        if(current->free && current->next && current->next->free){
            current->size += sizeof(Block) + current->next->size;
            current->next = current->next->next;
        }else{
            current = current->next;
        }
    }
}

void MemoryAllocator::displayPool() {
    Block* current = head;
    int blockNumber = 1;

    std::cout << "Memory Pool Status:\n";
    while (current != nullptr) {
        std::cout << "Block " << blockNumber << ": "
                  << "Size = " << current->size << " bytes, "
                  << (current->free ? "Free" : "Allocated") << "\n";
        current = current->next;
        blockNumber++;
    }
}


int main() {
    MemoryAllocator allocator;

    std::cout << "Initial memory pool status:\n";
    allocator.displayPool();

    // Test Case 1: Allocate a block of memory
    void* ptr1 = allocator.allocate(100);
    std::cout << "\nAfter allocating 100 bytes:\n";
    allocator.displayPool();

    // Test Case 2: Allocate another block of memory
    void* ptr2 = allocator.allocate(200);
    std::cout << "\nAfter allocating 200 bytes:\n";
    allocator.displayPool();

    // Test Case 3: Free the first block
    allocator.free(ptr1);
    cout << "\nAfter freeing the first 100-byte block:\n";
    allocator.displayPool();

    // Test Case 4: Allocate a block of 50 bytes (smaller than the freed block)
    void* ptr3 = allocator.allocate(50);
    std::cout << "\nAfter allocating 50 bytes:\n";
    allocator.displayPool();

    // Test Case 5: Free the second and third blocks
    allocator.free(ptr2);
    allocator.free(ptr3);
    cout << "\nAfter freeing the 200-byte and 50-byte blocks:\n";
    allocator.displayPool();

    return 0;
}





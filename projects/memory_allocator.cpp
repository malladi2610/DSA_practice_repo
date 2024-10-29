#include<cstdef> /*What is this library*/
#include<iostream>

class memoryAllocator{
private:
    struct Block{
        size_t size;
        bool free;
        Block* next;

    };
    Block* head;
    static const size_t pool_size = 1024;
    char memoryPool[poolSize];

public:

    /*What the hect is memory allocator() is it a  constructor*/
    MemoryAllocator() : head(nullptr) {             
        head = reinterpret_cast<Block*>(memoryPool); /*What ia this fucntion doing ?*/
        head->size = poolSize - sizeof(Block)
        head->free = true;
        head->next = nullptr;

    }
    void* allocate(size_t size);
    void free(void* ptr);
    void displayPool();
;
}

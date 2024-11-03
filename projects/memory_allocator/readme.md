
/*Why I am doing this ? - Why not ;) */

/*Goals to be achieved for this project are*/

- Implementation  of functionality of malloc and free for dynamic memory allocation

- Manage the fixed pool of the memory that is to be allocated into the smaller block whenever needed

- Track each block's size and availabiltiy status

- Minimize fragmentation by reusing freed blocks and potentially merging adjacent free blocks.



## Understanding the working of allocator

This line creates a new block in memory by shifting the pointer from the current block by `sizeof(Block) + size` bytes. Here’s how this operation works, step-by-step:

### Code Breakdown
```cpp
Block* newBlock = reinterpret_cast<Block*>(
    reinterpret_cast<char*>(current) + sizeof(Block) + size);
```

1. **`reinterpret_cast<char*>(current)`**: 
   - `current` is a pointer to the current block (`Block*` type).
   - Casting it to `char*` allows us to perform pointer arithmetic in terms of bytes.
   
2. **`reinterpret_cast<char*>(current) + sizeof(Block) + size`**:
   - By adding `sizeof(Block)`, we skip over the metadata section of the current block.
   - Adding `size` shifts the pointer further by the size of the allocated memory.
   - This total shift places `newBlock` at the next available position in `memoryPool`, directly after the memory allocated for the current block.

3. **`reinterpret_cast<Block*>(...)`**:
   - Finally, we cast the result back to `Block*`, interpreting this position as the start of a new block in memory.

### Dry Run Example
Assume:
- `memoryPool` starts at address `1000`.
- `head` is set to the start of `memoryPool`.
- `current` points to a block of `Block` size `16` bytes (metadata) and an allocated `size` of `100` bytes.

#### Step-by-Step Dry Run:
1. **`current` points to address `1000`**.
2. **`reinterpret_cast<char*>(current)`**: Converts `current` to a `char*`, so pointer arithmetic works in single bytes.
3. **`sizeof(Block)`**: Assume `sizeof(Block)` is `16` bytes (for the metadata).
4. **`size`**: Requested allocation size is `100` bytes.

So:
```cpp
newBlock = reinterpret_cast<Block*>(1000 + 16 + 100);
```
Calculating this:
- `1000 + 16` gives `1016` (end of metadata for `current`).
- `1016 + 100` gives `1116` (end of allocated memory).

Thus, `newBlock` is positioned at **address `1116`**.

### Summary
This line efficiently positions `newBlock` after `current`’s metadata and allocated space, ready for use as a new memory block.


Certainly! The line:

```cpp
size_t remainingSize = current->size - size - sizeof(Block);
```

calculates the leftover space in `current` after an allocation request. It helps decide if the block can be split into two: one part for the requested size and another part as a free block with the remaining space.

### Dry Run Example

Let's assume:
- `current` points to a block with:
  - `current->size = 200` bytes.
  - `size` = 100 bytes (requested allocation size).
  - `sizeof(Block)` = 16 bytes (metadata size for each block).

#### Step-by-Step Calculation

1. **`current->size`**: 
   - The total size of `current`, which is **200 bytes**.
   
2. **Subtracting `size`**: 
   - This leaves **200 - 100 = 100 bytes**, the space remaining if we allocate 100 bytes.
   
3. **Subtracting `sizeof(Block)`**:
   - **100 - 16 = 84 bytes**.
   - This final result, `84`, is the leftover size after reserving memory for the requested allocation (`size`) and leaving enough space for metadata of the next block (`sizeof(Block)`).

Thus:
```cpp
remainingSize = 200 - 100 - 16 = 84
```

### Why Calculate `remainingSize`?

If `remainingSize` is greater than `0`, it means we have enough space left in `current` to split it into two parts:
1. A block of **100 bytes** (for the allocation request).
2. A **new free block** of **84 bytes** (with `16` bytes reserved for its metadata and `remainingSize` for usable memory).

This approach helps minimize fragmentation by creating smaller free blocks from larger blocks when possible.


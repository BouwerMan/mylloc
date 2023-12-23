#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/mman.h>

const size_t PAGE_SIZE = 4096;

typedef struct heapchunk
{
    size_t size;
    bool inUse;
} heapchunk_t;

typedef struct heapinfo
{
    heapchunk_t* start;
    heapchunk_t* next;
    uint32_t avail;
} heapinfo_t;

heapinfo_t* heap = { 0 };

int initHeap()
{
    void* start = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

    // Wilderness chunk
    heapchunk_t* first = (heapchunk_t*)(start);

    first->size = PAGE_SIZE - sizeof(heapchunk_t);
    first->inUse = false;

    heap->start = first;
    heap->avail = PAGE_SIZE;
    // heap->next = heap;

    return 1;
}

// Using some magic numbers here to align properly
// 8 should be size of word on 64 bit machines
size_t align(size_t size)
{
    return (size + sizeof(int*) - 1) & ~(sizeof(int*) - 1);
}

void* mylloc(size_t size)
{
    //? Need to align?
    size = align(size);
    heapchunk_t* chunk;
    chunk->size = size;
    chunk->inUse = true;

    return (void*)(-1);
}

int main(void)
{
    printf("%zu\n", align(3));
    printf("%zu\n", align(8));
    printf("%zu\n", align(12));
    printf("%zu\n", align(16));
    // char* test = mylloc(16);
    printf("sizeof: %zu\n", sizeof(int*));
    return 0;
}

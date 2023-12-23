#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/mman.h>

const size_t pageSize = 4096;

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

int initHeap(heapinfo_t* heap)
{
    void* start = mmap(NULL, pageSize, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

    // Wilderness chunk
    heapchunk_t* first = (heapchunk_t*)(start);

    first->size = pageSize - sizeof(heapchunk_t);
    first->inUse = false;

    heap->start = first;
    heap->next = heap;

    return 1;
}

// Using some magic numbers here to align properly
// 8 should be size of word on 64 bit machines
size_t align(size_t size)
{
    return (size + 8 - 1) & ~(8 - 1);
}

void* mylloc(size_t size)
{
    size = align(size);
    return (NULL);
}

int main(void)
{
    printf("%d\n", align(3));
    printf("%d\n", align(8));
    printf("%d\n", align(12));
    printf("%d\n", align(16));
    // char* test = mylloc(16);
    return 0;
}

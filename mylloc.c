#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/mman.h>

const size_t PAGE_SIZE = 4096;

typedef struct heapchunk
{
    struct heapchunk* begin;
    size_t size;
    int free;
} heapchunk_t;

typedef struct heapinfo
{
    heapchunk_t* first;
    heapchunk_t* next;
    size_t size;
    int avail;
} heapinfo_t;

static heapinfo_t heap;

void initHeap()
{
    void* start = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    heap.first = (heapchunk_t*)start;
    heap.next = heap.first;
    heap.size = PAGE_SIZE; // Currently hardcoding to one page for simplicity
    heap.avail = PAGE_SIZE; // Currently hardcoding to one page for simplicity
}

void* mylloc(size_t size)
{
    if (!heap.size)
    {
        printf("Heap not found, initializing.\n");
        initHeap(); // Initialize heap if it does not exist
    }

    void* beginning = heap.next;

    return (void*)(-1);
}

int main(void)
{
    printf("HEllo world\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/heap_file.h"
#include "../include/slotted_page.h"

HeapFile* create_heap_file(int pages_num) {
    HeapFile *heap = (HeapFile *)malloc(sizeof(HeapFile));
    heap->num_pages = pages_num;
    heap->pages = (SlottedPage **)malloc(pages_num * sizeof(SlottedPage *));

    for (int i = 0; i < pages_num; i++) {
        heap->pages[i] = create_page();
    }
    return heap;
}


int insert_record(HeapFile *heap, const char *record) {
    for (int i = 0; i < heap->num_pages; i++) {
        int result = insert_into_page(heap->pages[i], record); // looping over pages to find a free slot
        if (result == 0) {
            return 0; 
        }
    }
    return -1; // no free space 
}

int delete_record(HeapFile *heap, int page_num, int slot_num) {
    if (page_num >= heap->num_pages) {
        printf("Error: Invalid page number.\n");
        return -1;
    }
    int result = delete_from_page(heap->pages[page_num], slot_num);
    if (result == 0) {
        compact_heap(heap);  // Call compaction after deletion
    }
    return result;
}


void compact_heap(HeapFile *heap) {
    for (int i = 0; i < heap->num_pages; i++) {
        compact_page(heap->pages[i]);
    }
    printf("Heap file compacted successfully.\n");
}

void display_heap_file(HeapFile *heap) {
    printf("--- Heap File ---\n");
    for (int i = 0; i < heap->num_pages; i++) {
        printf("Page %d:\n", i);
        display_page(heap->pages[i]);
    }
}

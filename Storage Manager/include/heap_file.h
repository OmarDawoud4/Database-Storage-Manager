#ifndef HEAP_FILE_H
#define HEAP_FILE_H

#include "slotted_page.h"

typedef struct {
    int num_pages;
    SlottedPage **pages; 
} HeapFile;


HeapFile* create_heap_file(int num_pages);
int insert_record(HeapFile *heap_file, const char *record);
int delete_record(HeapFile *heap_file, int page_num, int slot_num);
void compact_heap(HeapFile *heap_file);
void display_heap_file(HeapFile *heap_file);

#endif

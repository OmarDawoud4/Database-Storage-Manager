#ifndef SLOTTED_PAGE_H
#define SLOTTED_PAGE_H

#define PAGE_SIZE 4096
#define MAX_RECORD_SIZE 256

typedef struct {
    int num_records;
    int free_space_offset;
    int slots[PAGE_SIZE / MAX_RECORD_SIZE]; // header directory 
    char data[PAGE_SIZE];
} SlottedPage;


SlottedPage* create_page();
int insert_into_page(SlottedPage *page, const char *record);
int delete_from_page(SlottedPage *page, int slot_num);
void display_page(SlottedPage *page);
void compact_page(SlottedPage *page);

#endif

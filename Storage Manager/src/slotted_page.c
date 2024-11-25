#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/slotted_page.h"


SlottedPage* create_page() {
    SlottedPage *page = (SlottedPage *)malloc(sizeof(SlottedPage));
    page->num_records = 0;
    page->free_space_offset = 0;
    for (int i = 0; i < PAGE_SIZE / MAX_RECORD_SIZE; i++) {
        page->slots[i] = -1; 
    }
    return page;
}


int insert_into_page(SlottedPage *page, const char *record) {
    if (page->free_space_offset + strlen(record) + 1 > PAGE_SIZE) {
        return -1; // no enough space 
    }
    int slot = page->num_records; // offset 
    page->slots[slot] = page->free_space_offset;
    strcpy(page->data + page->free_space_offset, record);
    page->free_space_offset += strlen(record) + 1;
    page->num_records++;
    return 0; 
}


int delete_from_page(SlottedPage *page, int slot_num) {
    if (slot_num < 0 || slot_num >= page->num_records || page->slots[slot_num] == -1) {
        return -1; // Invalid slot number
    }
    page->slots[slot_num] = -1; 
    page->num_records--;
    return 0; 
}


void display_page(SlottedPage *page) {
    for (int i = 0; i < page->num_records; i++) {
        if (page->slots[i] != -1) {
            printf("  Slot %d: %s\n", i, page->data + page->slots[i]);
        } else {
            printf("  Slot %d: [Deleted]\n", i);
        }
    }
}

void compact_page(SlottedPage *page) {
    int j = 0;  // to be placed record 
    for (int i = 0; i < page->num_records; i++) {
        if (page->slots[i] != -1) {  
            if (i != j) { 
                
                memcpy(page->data + page->slots[j], page->data + page->slots[i], strlen(page->data + page->slots[i]) + 1);
                page->slots[j] = page->slots[i];
            }
            j++;  
        }
    }
    page->num_records = j;  
    page->free_space_offset = page->slots[j - 1] + strlen(page->data + page->slots[j - 1]) + 1;
}

#include <stdio.h>
#include <stdlib.h>
#include "../include/heap_file.h"

int main() {
 
    HeapFile *heap = create_heap_file(3);
    
    insert_record(heap, "first record ");
    insert_record(heap, "second record ");
    insert_record(heap, "third record ");


    display_heap_file(heap);

 
    printf("Deleting record from Page 0, Slot 1..\n");
    delete_record(heap, 0, 1); // internally calls compaction function 

   
    display_heap_file(heap);

    free(heap);
    
}

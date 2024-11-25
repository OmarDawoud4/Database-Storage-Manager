
## Heap File Storage with Slotted Pages
This project simulates how records are stored, deleted, and managed efficiently in a page-based system, while also providing a mechanism for handling fragmentation through compaction.

Heap file organization with slotted pages stores records in pages, divided into:
Slot Directory: Maps records to positions in the data area.
Data Area: Stores the actual records.
The free space offset tracks available space, and compaction reorganizes the page to remove deleted records and optimize space.
![Screenshot 2024-11-25 143317](https://github.com/user-attachments/assets/6bddeb2b-f0a8-46db-ae91-a0c809b8d683)

##Features
Heap File Creation:
Create a heap file with a fixed number of pages, each acting as a slotted page for record storage.

Record Insertion:
Insert records into the first available page with enough free space.

Record Deletion:
Mark records as deleted, leaving space for future reuse.

Compaction:
Reorganize the records on a page to eliminate fragmentation and consolidate free space.

Display Functionality:
View the contents of the heap file, including slots and deleted records.

## Compaction
Compaction is automatically triggered after a record is deleted.
This process rearranges the records on each page, making the storage more efficient and reducing fragmentation.

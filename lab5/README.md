## Lab 5
- Command to compile required files for exercise 2: `make compile`
- Command to run executable file created: `make run`
  - The executable takes the number of input files as an input
  - The recursive insertion sort sometimes causes a segmentation error for records in the range of 10^6, so it is advisable to limit the number of input files to 4 or 5
  - These 5 files corresponds to input files with 10, 100, 1000, 10000 and 100000 records.
- The executable will generate 3 files:
  - `readTime.txt` -> Measurements of time required for reading records
  - `insertionTime.txt` -> Measurements of time required for insertion sort
  - `insertionSpace.txt` -> Measurement of space required for insertion sort
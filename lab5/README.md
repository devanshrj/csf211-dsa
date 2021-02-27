## Lab 5
- Command to compile required files for exercise 2: `make compile`
- Command to run executable file created: `make run`
  - The executable performs sort on 9 files, corresponding to input files with 10, 100, 1000, 5000, 10000, 25000, 50000, 75000 and 100000 records.
- The executable will generate 3 files:
  - `readTime.txt` -> Measurements of time required for reading records
  - `insertionTime.txt` -> Measurements of time required for insertion sort
  - `insertionSpace.txt` -> Measurement of space required for insertion sort
- `readtime.txt` also contains the time required to read 1,000,000 records. This was done in a different iteration. Further, the input file for this has not been attached with the submission because of its size.
## Lab 5
- Command to compile required files for exercise 2: `make compile`
- Command to run executable file created: `make run`
  - The executable performs sort on 9 files, corresponding to input files with 10, 100, 1000, 5000, 10000, 25000, 50000, 75000 and 100000 records.
- The executable will generate 3 files:
  - `readTime.txt` -> Measurements of time required for reading records
  - `insertionTime.txt` -> Measurements of time required for insertion sort
  - `insertionSpace.txt` -> Measurement of space required for insertion sort
- `readtime.txt` also contains the time required to read 1,000,000 records. The input file for this has not been attached with the submission because of its size.

### Observations
- The file `observations.pdf` contains graphs on time and space measurements.
- The graph of time measurements for reading records is linear.
  - This is expected since we have a loop that performs constant operations in every iteration.
  - So, theoretically, it has a time complexity of O(n).
- The graph of time measurements for insertion sort is quadratic.
  - This is expected since insertion sort has a time complexity of O(n^2).
- The graph of space measurements for insertion sort is linear.
  - This is expected since insertion sort has a worst case space complexity of O(n).
  - Further, recursive implementation also has overheads associated with it, leading to higher memory requirements.
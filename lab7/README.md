## Lab 7
- Command to compile required files for exercise 2: `make compile`
  - This will generate an executable `exe`
- Command to run the executable: `./exe <input_file> <output_file>`
  - The code assumes that the input files are stored in a separate directory `input`
  - The command creates a new file `output_file` that contains data from `input_file` sorted by `empID`
  - The command also appends the time taken to sort the file as well as the cutoff for size to a file `results.txt`
- Input values till 100000 have been used since my laptop was unable to process larger files.

### Observations
- The file `observations.pdf` contains graphs on time and cutoff measurements.
- The graph of time measurements for sorting is parabolic/quadratic.
- The graph of cutoff measurements shows that cutoff happens in a close range (200-400 elements)
  - This implies that insertion sort is faster when N < 400 (roughly)
  - Quick sort is faster when N > 400
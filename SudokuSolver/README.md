# Sudoku Solver (C++ - Dancing Links)

A fast, robust, and feature-rich Sudoku solver using Donald Knuth's Algorithm X (Dancing Links) in C++. This project demonstrates advanced algorithmic techniques and clean C++ programming, suitable for inclusion in your CV and as a GitHub portfolio project.

## Project Description
This project is a command-line Sudoku solver that can handle any standard 9x9 Sudoku puzzle, including those with multiple solutions. It supports both interactive and batch (file) modes, provides pretty-printed output, validates input, and measures solving time. The code is well-documented and user-friendly, making it a great showcase for your programming and algorithmic skills.

## Features
- **Solves any 9x9 Sudoku puzzle** (even very hard or nearly empty ones)
- **Finds all possible solutions** (optional in interactive mode)
- **Efficient Algorithm X (DLX) implementation**
- **Pretty-printed Sudoku grid output**
- **Input validation** (checks for invalid numbers and format)
- **Timing information** (see how fast your puzzle is solved)
- **Flexible input/output**:
  - Read puzzle(s) from a file or standard input
  - Write solution(s) to a file or standard output
- **Batch mode**: Solve multiple puzzles from a single file
- **Interactive mode**: User-friendly prompts and output
- **Command-line options** for easy automation
- **Well-commented code** for learning and extension

## Usage
### Compile
```
g++ -O2 -std=c++11 -o sudokusolver main.cpp
```

### Run (Interactive Input)
```
./sudokusolver
```
You will be prompted to enter 9 rows of 9 numbers (0 for empty cells). After entering the puzzle, you can choose to find all solutions or just one.

### Run (File Input)
```
./sudokusolver input.txt
```
Where `input.txt` contains one or more puzzles, each as 9 lines of 9 numbers (0-9), separated by blank lines.

### Run (File Input & Output)
```
./sudokusolver input.txt output.txt
```
All solutions for each puzzle will be written to `output.txt`.

## Example Input (input.txt)
```
0 0 8 0 1 0 0 0 9
6 0 1 0 9 0 3 2 0
0 4 0 0 3 7 0 0 5
0 3 5 0 0 8 2 0 0
0 0 2 6 5 0 8 0 0
0 0 4 0 0 1 7 5 0
5 0 0 3 4 0 0 8 0
0 9 7 0 8 0 5 0 6
1 0 0 0 6 0 9 0 0

# (Add more puzzles here, separated by blank lines)
```

## Example Output (interactive mode)
```
==============================
Sudoku Solver - Interactive Mode
==============================
Enter the Sudoku puzzle (0 for empty cells):
(Enter 9 lines, each with 9 numbers separated by spaces)
Row 1: 0 0 8 0 1 0 0 0 9
Row 2: 6 0 1 0 9 0 3 2 0
... (rest of input)

Find all possible solutions? (y/n): y

Solving the puzzle...

==============================
Solution 1:
3 5 8 | 2 1 6 | 4 7 9 
6 7 1 | 5 9 4 | 3 2 8 
2 4 9 | 8 3 7 | 6 1 5 
------+-------+------
9 3 5 | 4 7 8 | 2 6 1 
7 1 2 | 6 5 3 | 8 9 4 
8 6 4 | 9 2 1 | 7 5 3 
------+-------+------
5 2 6 | 3 4 9 | 1 8 7 
4 9 7 | 1 8 2 | 5 3 6 
1 8 3 | 7 6 5 | 9 4 2 

1 solution found!
Solved in 0.00123 seconds.
==============================
```

## Example Output (batch mode, output.txt)
```
Puzzle 1:
Solution 1:
3 5 8 | 2 1 6 | 4 7 9 
6 7 1 | 5 9 4 | 3 2 8 
2 4 9 | 8 3 7 | 6 1 5 
------+-------+------
9 3 5 | 4 7 8 | 2 6 1 
7 1 2 | 6 5 3 | 8 9 4 
8 6 4 | 9 2 1 | 7 5 3 
------+-------+------
5 2 6 | 3 4 9 | 1 8 7 
4 9 7 | 1 8 2 | 5 3 6 
1 8 3 | 7 6 5 | 9 4 2 

1 solution found
Solved in 0.00123 seconds.

Puzzle 2:
No Solution Exists
Solved in 0.00045 seconds.

...
```

## Project Structure
- `main.cpp` — Main source code
- `README.md` — This file
- `sample.txt` — Example input file

## Author
- Manvitha Bheemavarapu
- [My GitHub Profile](https://github.com/Manvi1670)

---

**Feel free to fork, use, and extend this project!**

```
 

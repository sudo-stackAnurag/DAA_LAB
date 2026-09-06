<h1 align="center">Design and Analysis of Algorithms</h1>

<p align="center">
  <strong>DAA Laboratory Assignments — IIIT Bhubaneswar</strong>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-A8B9CC?style=flat-square&logo=c&logoColor=white" alt="C" />
  <img src="https://img.shields.io/badge/Compiler-GCC-FE7A16?style=flat-square&logo=gnu&logoColor=white" alt="GCC" />
  <img src="https://img.shields.io/badge/Platform-Windows-0078D4?style=flat-square&logo=windows&logoColor=white" alt="Platform" />
</p>

---

## Introduction

This repository contains my solutions for the **Design and Analysis of Algorithms (DAA) Laboratory**. Each lab has its own folder, with individual questions and their corresponding C source files, generated data, and supporting files where applicable.

---

## Student Information

| Field | Details |
|---|---|
| Name | Anurag Samal |
| Student ID | B525009 |
| Branch | Computer Engineering (CE) |
| Institute | IIIT Bhubaneswar |
| Course | Design and Analysis of Algorithms Laboratory |
| Semester | B.Tech 3rd Semester |
| Instructor | Dr. Ajaya Kumar Dash |

---

## Repository Structure

```text
DAA_LAB/
│
├── README.md
├── LAB_1/   # Growth analysis and basic algorithms
├── LAB_2/   # Merge sort and dictionary operations
├── LAB_3/   # Divide and conquer algorithms
├── LAB_4/   # Applications of sorting
├── LAB_5/   # Selection, heap sort and quicksort
└── LAB_6/   # Array, matrix, convolution and reversal operations
```

---

## Lab Index

| Lab | Topic | Questions | Folder |
|---|---|---:|---|
| Lab 01 | Growth of functions, empirical analysis and recursion | 6 | [LAB_1](LAB_1) |
| Lab 02 | Dictionary operations, merge sort and k-way merging | 3 | [LAB_2](LAB_2) |
| Lab 03 | Divide and conquer algorithms and loop invariants | 6 | [LAB_3](LAB_3) |
| Lab 04 | Applications of sorting | 6 | [LAB_4](LAB_4) |
| Lab 05 | Selection algorithms, heap sort and quicksort | 4 | [LAB_5](LAB_5) |
| Lab 06 | Array operations, matrix operations, convolution and reversal sorting | 4 | [LAB_6](LAB_6) |

---

# LAB_1

> Growth rates, randomised simulation, sorting, recursion, and algorithm analysis.

| # | Question | File |
|---|---|---|
| 1 | Put them in Order | [growth.c](LAB_1/1.%20Put%20them%20in%20Order/growth.c) |
| 2 | Fair vs Biased Coin | [coin.c](LAB_1/2.%20Fair%20vs%20Biased%20coin/coin.c) |
| 3 | Performance Analysis of Bubble Sort | [bubble.c](LAB_1/3.%20Performance%20analysis%20of%20bubble%20sort/bubble.c) |
| 4 | Towers of Hanoi | [TOH.c](LAB_1/4.%20Towers%20of%20Hanoi/TOH.c) |
| 5 | Find the Partition Point | [partition.c](LAB_1/5.%20Find%20the%20partition%20point/partition.c) |
| 6 | Element Uniqueness | [unique.c](LAB_1/6.%20Element%20uniqueness/unique.c) |

---

# LAB_2

> Dictionary operations, merge sort variants, and merging sorted arrays.

| # | Question | File |
|---|---|---|
| 1 | Dictionary Operations | [dictionary_growth.c](LAB_2/1.%20Dictionary%20Operations/dictionary_growth.c) |
| 2 | Merge Sort vs Modified Merge Sort | [merge_sort.c](LAB_2/2.%20Merge%20sort%20vs%20Modified%20merge%20sort/merge_sort.c) |
| 3 | Merging k Sorted Arrays | [merging_k_arrays.c](LAB_2/3.%20Merging%20k%20sorted%20arrays/merging_k_arrays.c) |

---

# LAB_3

> Divide and conquer algorithms, searching, matrix multiplication, and loop invariants.

| # | Question | File |
|---|---|---|
| 1 | Binary vs Ternary Search | [BTsearch.c](LAB_3/1.%20Binary%20vs%20Ternary%20Search/BTsearch.c) |
| 2 | Search the Defective Coin | [Dcoin.c](LAB_3/2.%20Search%20the%20Defective%20Coin/Dcoin.c) |
| 3 | Max and Min using D&C Approach | [minmax.c](LAB_3/3.%20Max%20and%20Min%20using%20D%26C%20Approach/minmax.c) |
| 4 | Matrix Multiplication using D&C Approach | [strassen.c](LAB_3/4.%20Matrix%20Multiplication%20using%20D%26C%20Approach/strassen.c) |
| 5 | Special-Pattern Matrix Multiplication | [specialmat.c](LAB_3/5.%20Multiply%20special-pattern%20square%20matrices%20using%20D%26C%20approach/specialmat.c) |
| 6 | Use of Loop Invariants in Sorting | [loopsorting.c](LAB_3/6.%20Use%20of%20loop%20invariants%20in%20sorting/loopsorting.c) |

---

# LAB_4

> Applications of sorting: colour sorting, pair sums, event processing and interval problems.

| # | Question | File |
|---|---|---|
| 1 | Application of Sorting-I | [color_sort.c](LAB_4/1.%20Application%20of%20sorting-I/color_sort.c) |
| 2 | Application of Sorting-II | [add_pair_sort.c](LAB_4/2.%20Application%20of%20sorting-II/add_pair_sort.c) |
| 3 | Application of Sorting-III | [add_upto_T.c](LAB_4/3.%20Application%20of%20sorting-III/add_upto_T.c) |
| 4 | Application of Sorting-IV | [door_tracks.c](LAB_4/4.%20Application%20of%20sorting-IV/door_tracks.c) |
| 5 | Application of Sorting-V | [overlapping_set.c](LAB_4/5.%20Application%20of%20sorting-V/overlapping_set.c) |
| 6 | Application of Sorting-VI | [common_point.c](LAB_4/6.%20Application%20of%20sorting-VI/common_point.c) |

---

# LAB_5

> Selection algorithms and comparison-based sorting techniques.

| # | Question | Description | File |
|---|---|---|---|
| 1 | Median of Elements | Finds the median using a QuickSelect-based approach. | [median.c](LAB_5/Q1/median.c) |
| 2 | K-th Smallest Element | Finds the K-th smallest element using QuickSelect. | [k_element.c](LAB_5/Q2/k_element.c) |
| 3 | Heap Sort | Generates elements, sorts them using heap sort, and stores input and output in files. | [heapsort.c](LAB_5/Q3/heapsort.c) |
| 4 | Quick Sort | Generates elements, sorts them using quicksort, and stores input and output in files. | [quicksort.c](LAB_5/Q4/quicksort.c) |

### LAB_5 Files

```text
LAB_5/
├── Q1/
│   ├── median.c
│   └── median.exe
├── Q2/
│   ├── k_element.c
│   └── k_element.exe
├── Q3/
│   ├── heapsort.c
│   ├── input2.txt
│   └── sorted2.txt
└── Q4/
    ├── quicksort.c
    ├── input.txt
    └── sorted.txt
```

---

# LAB_6

> Array and matrix operations, FFT-based convolution, and sorting through reversal operations.

| # | Question | Description | File |
|---|---|---|---|
| 1 | 1D Array Operations and Complexities | Performs maximum, largest elements, mean, median, standard deviation, mode, duplicate removal, reversal, and partitioning operations. | [1Darray.c](LAB_6/1.%201D%20array%20operations%20and%20their%20complexities/1Darray.c) |
| 2 | 2D Square Matrix Operations and Complexities | Performs matrix addition, multiplication, zero/symmetry checks, determinant calculation, transpose, and dominant eigenvalue/eigenvector computation. | [2Dmatrix.c](LAB_6/2.%202D%20square%20matrix%20operations%20and%20their%20complexities/2Dmatrix.c) |
| 3 | Convolution Operation on Vectors of Size n | Computes vector convolution using an FFT-based approach. | [FTT.c](LAB_6/3.%20Convolution%20operation%20on%20vectors%20of%20size%20n/FTT.c) |
| 4 | Sorting via Reversal Procedure | Sorts a permutation using recursive stable partitioning and reversal operations. | [reversal.c](LAB_6/4.%20Sorting%20via%20reversal%20procedure/reversal.c) |

### LAB_6 Files

```text
LAB_6/
├── 1. 1D array operations and their complexities/
│   └── 1Darray.c
├── 2. 2D square matrix operations and their complexities/
│   └── 2Dmatrix.c
├── 3. Convolution operation on vectors of size n/
│   └── FTT.c
└── 4. Sorting via reversal procedure/
    └── reversal.c
```

---

## Complexity Summary

| Lab | Algorithm / Topic | Typical Time Complexity |
|---|---|---|
| LAB_1 | Bubble Sort | O(n²) |
| LAB_1 | Towers of Hanoi | O(2ⁿ) |
| LAB_2 | Merge Sort | O(n log n) |
| LAB_3 | Binary Search | O(log n) |
| LAB_3 | Strassen's Matrix Multiplication | O(n^2.807) |
| LAB_4 | Sorting-based applications | Usually O(n log n) |
| LAB_5 | QuickSelect | O(n) average |
| LAB_5 | Heap Sort | O(n log n) |
| LAB_5 | Quick Sort | O(n log n) average |
| LAB_6 | FFT-based convolution | O(n log n) |
| LAB_6 | Reversal-based sorting | Depends on reversal operations and recursive partitioning |

---

## Topics Covered

### Algorithm Analysis
- Asymptotic notation — O, Ω and Θ
- Growth of functions
- Best-case and worst-case analysis
- Empirical performance analysis

### Searching and Sorting
- Bubble Sort
- Merge Sort
- Binary Search
- Ternary Search
- Heap Sort
- Quick Sort
- QuickSelect
- Sorting applications

### Divide and Conquer
- Towers of Hanoi
- Defective Coin Problem
- Maximum and Minimum
- Strassen's Matrix Multiplication
- Special-pattern matrices

### Advanced Applications
- Interval merging and overlap detection
- Event processing
- K-th smallest element
- Median selection
- Matrix operations
- FFT-based convolution
- Sorting through reversal procedures

---

## Compilation and Execution

Compile individual programs using GCC:

```bash
gcc filename.c -o program
./program
```

Some programs require the math library:

```bash
gcc filename.c -o program -lm
./program
```

### Examples

```bash
# LAB_5
cd LAB_5/Q1
gcc median.c -o median
./median

# LAB_6
cd "LAB_6/1. 1D array operations and their complexities"
gcc 1Darray.c -o 1Darray -lm
./1Darray
```

On Windows with MinGW:

```bash
gcc filename.c -o program.exe
program.exe
```

---

## Technologies Used

| Tool | Purpose |
|---|---|
| C | Implementation language |
| GCC | Compilation |
| C Standard Library | Core program functionality |
| Gnuplot | Plot generation where applicable |
| Git and GitHub | Version control and repository hosting |

---

## License

Coursework, published for reference and learning. Feel free to read and learn from the code, but please do not submit it as your own.

---

<p align="center">
  Maintained by <strong>Anurag Samal</strong> · CE, IIIT Bhubaneswar
</p>
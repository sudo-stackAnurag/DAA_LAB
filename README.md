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

# LAB_5 — Selection and Sorting Algorithms

This lab contains C implementations of selection algorithms and comparison-based sorting algorithms.

## Requirements

- C compiler such as GCC
- Standard C library
- Terminal/Command Prompt

Compile a program using:

```bash
gcc program.c -o program
```

Run it using:

```bash
./program
```

On Windows:

```bash
program.exe
```

---

# Application I — Median of Elements

## Problem

Given `n` unsorted elements, find their median without completely sorting the array.

For an odd number of elements, the median is the middle element in sorted order. For an even number of elements, the median is the average of the two middle elements.

## Algorithm

The program uses the **QuickSelect** approach:

1. Choose the last element as a pivot.
2. Partition the array so that elements less than or equal to the pivot are placed before it.
3. If the pivot reaches the required index, return it.
4. Otherwise, recursively continue in the appropriate partition.

For an even-sized array, the program finds both middle elements. Since QuickSelect modifies the array, the original array is restored before finding the second middle element.

## Complexity

```text
Average Time: O(n)
Worst Case:   O(n²)
Space:        O(log n) recursion stack on average
```

## Example

```text
Input:
1 7 3 9 5

Sorted order:
1 3 5 7 9

Median = 5
```

For an even-sized input:

```text
Input:
1 7 3 9

Sorted order:
1 3 7 9

Median = (3 + 7) / 2 = 5.00
```

---

# Application II — K-th Smallest Element

## Problem

Given an unsorted array containing `n` elements and an integer `k`, find the `k`-th smallest element.

The valid range is:

```text
1 <= k <= n
```

## Algorithm

The program uses **QuickSelect**:

1. Partition the array around a pivot.
2. Determine the pivot's final position.
3. If the pivot position is `k - 1`, the required element has been found.
4. Otherwise, recursively search the left or right partition.

## Complexity

```text
Average Time: O(n)
Worst Case:   O(n²)
```

## Example

```text
Array = {7, 10, 4, 3, 20, 15}
k = 3
```

Sorted order:

```text
3 4 7 10 15 20
```

Therefore:

```text
3rd smallest element = 7
```

## Validation

The program validates that:

```text
1 <= k <= n
```

If `k` is outside this range, the program prints:

```text
Invalid value of K
```

---

# Application III — Heap Sort

## Problem

Generate `n` random integers, store them in a file, read them into an array, and sort them using **Heap Sort**.

The program stores:

```text
Original random elements → input2.txt
Sorted elements          → sorted2.txt
```

## Algorithm

1. Build a **Max Heap** from the array.
2. Swap the root with the last element.
3. Reduce the heap size.
4. Restore the Max Heap property using `heapify`.
5. Repeat until the array is sorted.

## Complexity

```text
Build Heap: O(n)
Heap Sort:  O(n log n)
Total:      O(n log n)
Space:      O(1) auxiliary space
```

## Example

```text
Original elements:
42 15 87 23 9
```

After Heap Sort:

```text
9 15 23 42 87
```

The exact elements may differ because the program generates random values.

---

# Application IV — Quick Sort

## Problem

Generate `n` random integers, store them in a file, read them into an array, and sort them using **Quick Sort**.

The program stores:

```text
Original random elements → input.txt
Sorted elements          → sorted.txt
```

## Algorithm

1. Select the last element as the pivot.
2. Partition the array around the pivot.
3. Recursively sort the left partition.
4. Recursively sort the right partition.

## Complexity

```text
Best / Average Case: O(n log n)
Worst Case:          O(n²)
Average Space:       O(log n) recursion stack
```

## Example

```text
Original elements:
64 21 8 93 45
```

After Quick Sort:

```text
8 21 45 64 93
```

The exact elements may differ because the program generates random values.

---

# LAB_5 Summary

| Application | Main Technique | Time Complexity |
|---|---|---|
| I. Median of Elements | QuickSelect | Average **O(n)** |
| II. K-th Smallest Element | QuickSelect | Average **O(n)** |
| III. Heap Sort | Heap construction + Heapify | **O(n log n)** |
| IV. Quick Sort | Partition + Recursion | Average **O(n log n)** |

---

# LAB_6 — Array, Matrix and Advanced Operations

This lab contains implementations of one-dimensional array operations, two-dimensional matrix operations, convolution using the Fast Fourier Transform, and sorting through reversal procedures.

## Requirements

- C compiler such as GCC
- Standard C library
- Math library for programs using mathematical functions
- Terminal/Command Prompt

Compile programs requiring the math library using:

```bash
gcc program.c -o program -lm
```

Run using:

```bash
./program
```

---

# Application I — 1D Array Operations and Their Complexities

## Problem

Given an unsorted one-dimensional array, perform the following operations:

```text
(i)   Find the maximum element
(ii)  Find the first and second largest elements
(iii) Calculate the mean
(iv)  Calculate the median
(v)   Calculate the standard deviation
(vi)  Find the mode
(vii) Remove duplicates
(viii) Reverse the array
(ix)  Partition the array using a pivot
```

## Algorithm

The program uses different techniques for each operation:

- A linear scan for the maximum element.
- A single traversal for the largest and second-largest elements.
- Summation for the mean.
- A copied array and sorting for the median.
- The population standard deviation formula.
- Nested loops to count occurrences for the mode.
- Linear duplicate checking to remove repeated values.
- Two pointers to reverse the array.
- Two pointers to partition the array around a pivot.

## Complexity

| Operation | Time Complexity |
|---|---|
| Maximum | **O(n)** |
| Largest Two | **O(n)** |
| Mean | **O(n)** |
| Median | **O(n log n)** due to sorting |
| Standard Deviation | **O(n)** |
| Mode | **O(n²)** |
| Remove Duplicates | **O(n²)** |
| Reverse Array | **O(n)** |
| Partition | **O(n)** |

## Example

```text
Array = {4, 2, 7, 2, 9, 4}

Maximum = 9
First Largest = 9
Second Largest = 7
Mean = 4.67
Median = 4.00
Mode = 4 or 2 depending on first maximum frequency encountered
```

After removing duplicates:

```text
4 2 7 9
```

After reversing:

```text
9 7 2 4
```

---

# Application II — 2D Square Matrix Operations and Their Complexities

## Problem

Given two square matrices `A` and `B` of order `n`, perform the following operations:

```text
(i)   Matrix Addition
(ii)  Matrix Multiplication
(iii) Check whether Matrix A is a Zero Matrix
(iv)  Check whether matrices are Symmetric
(v)   Find the Determinant of Matrix A
(vi)  Find the Transpose of Matrix A
(vii) Find the Dominant Eigenvalue and Eigenvector of Matrix B
```

## Algorithm

The program uses:

- Nested loops for matrix addition and multiplication.
- Element scanning to check for a zero matrix.
- Comparison across the main diagonal to check symmetry.
- Gaussian elimination with pivoting for the determinant.
- In-place swapping across the main diagonal for the transpose.
- An iterative power-method style calculation for the dominant eigenvalue and eigenvector.

## Complexity

| Operation | Time Complexity |
|---|---|
| Matrix Addition | **O(n²)** |
| Matrix Multiplication | **O(n³)** |
| Zero Matrix Check | **O(n²)** |
| Symmetry Check | **O(n²)** |
| Determinant | **O(n³)** |
| Transpose | **O(n²)** |
| Dominant Eigenvalue/Eigenvector | **O(ITER × n²)** |

## Example

```text
A = [1 2]
    [3 4]

B = [5 6]
    [7 8]
```

Matrix addition:

```text
6  8
10 12
```

Matrix multiplication:

```text
19 22
43 50
```

---

# Application III — Convolution Operation on Vectors of Size n

## Problem

Given two vectors `A` and `B`, compute their convolution efficiently.

The program requires:

```text
size(A) <= size(B)
```

The resulting convolution contains:

```text
m + n - 1
```

elements, where `m` and `n` are the sizes of the two vectors.

## Algorithm

The program uses the **Fast Fourier Transform (FFT)**:

1. Find the next power of two greater than or equal to `m + n - 1`.
2. Pad both vectors with zeros.
3. Apply FFT to both vectors.
4. Multiply corresponding complex values.
5. Apply the inverse FFT.
6. Print the resulting convolution values.

## Complexity

```text
FFT of each vector: O(N log N)
Pointwise multiply:  O(N)
Inverse FFT:         O(N log N)

Total: O(N log N)
```

where `N` is the next power of two greater than or equal to the convolution size.

## Example

```text
A = {1, 2, 3}
B = {4, 5, 6}
```

Convolution:

```text
4 13 28 27 18
```

---

# Application IV — Sorting via Reversal Procedure

## Problem

Given a permutation of integers from `1` to `n`, sort the permutation using reversal operations.

The program also reports:

```text
Number of reversals
Total reversal cost
```

## Algorithm

The program recursively divides the value range using a pivot.

For each recursive step:

1. Stably partition the permutation into elements less than or equal to the pivot and elements greater than the pivot.
2. Use reversals to rotate the required subarrays.
3. Recursively sort the two resulting partitions.

The stable partition operation transforms:

```text
L1 H1 L2 H2
```

into:

```text
L1 L2 H1 H2
```

using three reversals when both groups are present.

## Complexity

The implementation tracks the number and total cost of reversal operations. The exact running time depends on the recursive partitions and the lengths of the reversals performed.

## Example

```text
Original permutation:
3 1 4 2
```

After sorting:

```text
1 2 3 4
```

The program additionally displays the number of reversals and the total reversal cost for the given input.

---

# LAB_6 Summary

| Application | Main Technique | Typical Time Complexity |
|---|---|---|
| I. 1D Array Operations | Linear scans, sorting and nested loops | Varies by operation |
| II. 2D Matrix Operations | Matrix algorithms and iterative methods | Varies from **O(n²)** to **O(n³)** |
| III. Vector Convolution | Fast Fourier Transform | **O(N log N)** |
| IV. Sorting by Reversal | Recursive stable partitioning | Depends on reversal operations |

---

# Common Implementation Details

The LAB_5 and LAB_6 programs use arrays, recursion, structures, pointers, dynamic memory allocation, and standard C library functions where required.

### QuickSelect

Used in LAB_5 Applications I and II:

```text
Partition
   ↓
Locate pivot position
   ↓
Search required partition
```

### Heap Sort

Used in LAB_5 Application III:

```text
Build Max Heap
   ↓
Move maximum to the end
   ↓
Heapify remaining elements
```

### FFT

Used in LAB_6 Application III:

```text
Divide into even and odd terms
   ↓
Recursively compute FFT
   ↓
Combine results
```

### Reversal

Used in LAB_6 Application IV to rearrange subarrays while performing stable partitioning.

---

# Validation and Conditions

The programs include conditions and checks appropriate to their implementations, such as:

- `1 <= k <= n` for the K-th smallest element problem.
- LAB_6 convolution requires the first vector size to be less than or equal to the second vector size.
- LAB_6 reversal sorting expects a permutation of values from `1` to `n`.
- File operations in Heap Sort and Quick Sort are checked for file-opening errors.

---

# Overall Complexity Summary

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

# Conclusion

The DAA laboratory assignments in this repository demonstrate a variety of fundamental algorithmic techniques.

The major techniques used include:

```text
LAB_1
→ Growth analysis and basic algorithms

LAB_2
→ Merge Sort and dictionary operations

LAB_3
→ Divide and Conquer

LAB_4
→ Sorting-based applications

LAB_5
→ Selection, Heap Sort and Quick Sort

LAB_6
→ Array and matrix operations, FFT, and reversal-based sorting
```

Together, these laboratory assignments demonstrate how appropriate data representations and algorithmic techniques can be used to solve a wide range of computational problems efficiently.

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
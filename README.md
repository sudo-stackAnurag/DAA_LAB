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

# Introduction

This repository contains C implementations and analyses of problems completed as part of the **Design and Analysis of Algorithms (DAA) Laboratory**. The repository covers fundamental algorithmic ideas including growth analysis, searching, sorting, divide and conquer, selection algorithms, matrix operations, convolution, and reversal-based algorithms.

Each laboratory section follows a consistent structure containing:

- Problem statement
- Algorithm or approach
- Complexity analysis
- Example or expected behaviour
- Relevant source-code links

---

# Student Information

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

# Requirements

The programs in this repository require:

- A C compiler such as GCC
- Standard C library
- Math library for programs using mathematical functions
- Terminal or Command Prompt

### Compilation

```bash
gcc filename.c -o program
./program
```

For programs using the math library:

```bash
gcc filename.c -o program -lm
./program
```

On Windows:

```bash
gcc filename.c -o program.exe
program.exe
```

---

# Repository Structure

```text
DAA_LAB/
│
├── README.md
├── LAB_1/   # Growth analysis and basic algorithms
├── LAB_2/   # Dictionary operations and merging
├── LAB_3/   # Divide and conquer algorithms
├── LAB_4/   # Applications of sorting
├── LAB_5/   # Selection, heap sort and quicksort
└── LAB_6/   # Array, matrix, convolution and reversal operations
```

---

# Lab Index

| Lab | Main Topic | Questions | Folder |
|---|---|---:|---|
| Lab 01 | Growth analysis and basic algorithms | 6 | [LAB_1](LAB_1) |
| Lab 02 | Dictionary operations and merge-based algorithms | 3 | [LAB_2](LAB_2) |
| Lab 03 | Divide and conquer | 6 | [LAB_3](LAB_3) |
| Lab 04 | Applications of sorting | 6 | [LAB_4](LAB_4) |
| Lab 05 | Selection and sorting algorithms | 4 | [LAB_5](LAB_5) |
| Lab 06 | Arrays, matrices, convolution and reversals | 4 | [LAB_6](LAB_6) |

---

# LAB_1 — Growth Analysis and Basic Algorithms

This lab introduces fundamental algorithm analysis concepts, empirical comparison, recursion, and basic problem-solving techniques.

## Application I — Put Them in Order

### Problem
Arrange and compare functions according to their rates of growth.

### Algorithm / Approach
Functions are analysed using asymptotic growth rates and arranged from slower-growing to faster-growing functions.

### Complexity Concept
The exercise focuses on common growth classes such as:

```text
O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(2ⁿ) < O(n!)
```

### Source Code
[Open growth.c](LAB_1/1.%20Put%20them%20in%20Order/growth.c)

---

## Application II — Fair vs Biased Coin

### Problem
Simulate coin tosses and compare fair and biased probability distributions.

### Algorithm / Approach
Random values are generated repeatedly and classified as heads or tails according to the required probability model.

### Complexity
For `n` tosses:

```text
Time: O(n)
Space: O(1)
```

### Source Code
[Open coin.c](LAB_1/2.%20Fair%20vs%20Biased%20coin/coin.c)

---

## Application III — Performance Analysis of Bubble Sort

### Problem
Sort elements using Bubble Sort and analyse its performance.

### Algorithm
Repeatedly compare adjacent elements and swap them when they are in the wrong order.

### Complexity

```text
Best Case:    O(n)
Average Case: O(n²)
Worst Case:   O(n²)
```

### Source Code
[Open bubble.c](LAB_1/3.%20Performance%20analysis%20of%20bubble%20sort/bubble.c)

---

## Application IV — Towers of Hanoi

### Problem
Move `n` disks from a source rod to a destination rod using an auxiliary rod.

### Algorithm

```text
Move n - 1 disks to auxiliary
Move largest disk to destination
Move n - 1 disks to destination
```

### Complexity

```text
Time: O(2ⁿ)
Minimum moves: 2ⁿ - 1
```

### Source Code
[Open TOH.c](LAB_1/4.%20Towers%20of%20Hanoi/TOH.c)

---

## Application V — Find the Partition Point

### Problem
Determine the point at which an ordered or structured input changes from one condition to another.

### Algorithm / Approach
The implementation searches for the required partition condition in the input.

### Complexity
Depends on the search strategy used by the implementation.

### Source Code
[Open partition.c](LAB_1/5.%20Find%20the%20partition%20point/partition.c)

---

## Application VI — Element Uniqueness

### Problem
Determine whether all elements in an array are unique.

### Algorithm
Compare elements to detect duplicate values.

### Complexity
A direct comparison-based implementation typically requires:

```text
Time: O(n²)
Space: O(1)
```

### Source Code
[Open unique.c](LAB_1/6.%20Element%20uniqueness/unique.c)

---

# LAB_1 Summary

| Application | Main Technique | Typical Complexity |
|---|---|---|
| Put Them in Order | Growth analysis | Conceptual analysis |
| Fair vs Biased Coin | Random simulation | O(n) |
| Bubble Sort | Comparison sorting | O(n²) |
| Towers of Hanoi | Recursion | O(2ⁿ) |
| Partition Point | Searching | Input dependent |
| Element Uniqueness | Duplicate detection | O(n²) |

---

# LAB_2 — Dictionary and Merge-Based Algorithms

This lab focuses on dictionary operations, Merge Sort variants, and combining multiple sorted arrays.

## Application I — Dictionary Operations

### Problem
Perform operations on a dictionary-like collection and analyse the growth of the data structure.

### Algorithm / Approach
The implementation performs the required insertion, searching, deletion, or related dictionary operations.

### Complexity
The complexity depends on the underlying representation and operation being performed.

### Source Code
[Open dictionary_growth.c](LAB_2/1.%20Dictionary%20Operations/dictionary_growth.c)

---

## Application II — Merge Sort vs Modified Merge Sort

### Problem
Compare the standard Merge Sort algorithm with a modified implementation.

### Algorithm

```text
Divide the array into smaller halves
Recursively sort each half
Merge the sorted halves
```

### Complexity

```text
Time: O(n log n)
Auxiliary Space: O(n)
```

### Source Code
[Open merge_sort.c](LAB_2/2.%20Merge%20sort%20vs%20Modified%20merge%20sort/merge_sort.c)

---

## Application III — Merging k Sorted Arrays

### Problem
Merge multiple individually sorted arrays into a single sorted sequence.

### Algorithm / Approach
The sorted arrays are combined while preserving the overall ordering.

### Complexity
The exact complexity depends on the merging strategy and number of arrays.

### Source Code
[Open merging_k_arrays.c](LAB_2/3.%20Merging%20k%20sorted%20arrays/merging_k_arrays.c)

---

# LAB_2 Summary

| Application | Main Technique | Typical Complexity |
|---|---|---|
| Dictionary Operations | Data operations | Representation dependent |
| Merge Sort Comparison | Divide and conquer | O(n log n) |
| Merging k Arrays | Multiway merging | Strategy dependent |

---

# LAB_3 — Divide and Conquer

This lab demonstrates how problems can be divided into smaller subproblems, solved recursively, and combined to obtain the final solution.

## Application I — Binary vs Ternary Search

### Problem
Compare Binary Search and Ternary Search for locating an element in a sorted array.

### Algorithm

Binary Search divides the search range into two parts, while Ternary Search divides it into three parts.

### Complexity

```text
Binary Search:  O(log n)
Ternary Search: O(log₃ n)
```

### Source Code
[Open BTsearch.c](LAB_3/1.%20Binary%20vs%20Ternary%20Search/BTsearch.c)

---

## Application II — Search the Defective Coin

### Problem
Identify a defective coin using balance comparisons.

### Algorithm
Divide the coins into groups, compare their weights, and recursively search the group containing the defective coin.

### Complexity
A divide-and-conquer solution typically reduces the search space at every weighing.

### Source Code
[Open Dcoin.c](LAB_3/2.%20Search%20the%20Defective%20Coin/Dcoin.c)

---

## Application III — Maximum and Minimum Using Divide and Conquer

### Problem
Find both the maximum and minimum elements of an array efficiently.

### Algorithm
Split the array into two halves, recursively determine local maxima and minima, and combine the results.

### Complexity

```text
Time: O(n)
Comparisons: approximately 3n/2
```

### Source Code
[Open minmax.c](LAB_3/3.%20Max%20and%20Min%20using%20D%26C%20Approach/minmax.c)

---

## Application IV — Matrix Multiplication Using Divide and Conquer

### Problem
Multiply square matrices using a divide-and-conquer approach.

### Algorithm
The implementation uses a recursive matrix multiplication strategy based on Strassen's method.

### Complexity

```text
O(n^2.807)
```

### Source Code
[Open strassen.c](LAB_3/4.%20Matrix%20Multiplication%20using%20D%26C%20Approach/strassen.c)

---

## Application V — Special-Pattern Matrix Multiplication

### Problem
Multiply recursively structured square matrices efficiently.

### Algorithm / Approach
Exploit the special matrix pattern to reduce unnecessary calculations.

### Complexity
The intended specialised approach improves upon general matrix multiplication for the given structure.

### Source Code
[Open specialmat.c](LAB_3/5.%20Multiply%20special-pattern%20square%20matrices%20using%20D%26C%20approach/specialmat.c)

---

## Application VI — Loop Invariants in Sorting

### Problem
Use loop invariants to demonstrate the correctness of a sorting algorithm.

### Algorithm / Approach
The invariant is established before the loop, maintained during every iteration, and used to prove correctness at termination.

### Source Code
[Open loopsorting.c](LAB_3/6.%20Use%20of%20loop%20invariants%20in%20sorting/loopsorting.c)

---

# LAB_3 Summary

| Application | Main Technique | Typical Complexity |
|---|---|---|
| Binary vs Ternary Search | Searching | O(log n) |
| Defective Coin | Divide and conquer | Logarithmic reductions |
| Max and Min | Divide and conquer | O(n) |
| Strassen Multiplication | Divide and conquer | O(n^2.807) |
| Special Matrix | Structure exploitation | Problem dependent |
| Loop Invariants | Correctness proof | Analysis technique |

---

# LAB_4 — Applications of Sorting

This lab demonstrates how sorting can be used as a preprocessing step to solve different computational problems efficiently.

## Application I — Application of Sorting-I

### Problem
Sort paired items according to the required ordering criterion.

### Algorithm / Approach
Sorting groups related items into an appropriate order so that the required property can be processed efficiently.

### Source Code
[Open color_sort.c](LAB_4/1.%20Application%20of%20sorting-I/color_sort.c)

---

## Application II — Application of Sorting-II

### Problem
Given two sets and a target value, determine whether a pair of elements adds up to the target.

### Algorithm
Sort the input and search for complementary values using an efficient scanning strategy.

### Complexity

```text
Sorting: O(n log n)
Searching: O(n)
Total: O(n log n)
```

### Source Code
[Open add_pair_sort.c](LAB_4/2.%20Application%20of%20sorting-II/add_pair_sort.c)

---

## Application III — Application of Sorting-III

### Problem
Use sorting to identify elements or combinations satisfying a target sum condition.

### Algorithm / Approach
Sort the values and efficiently search for valid combinations.

### Source Code
[Open add_upto_T.c](LAB_4/3.%20Application%20of%20sorting-III/add_upto_T.c)

---

## Application IV — Application of Sorting-IV

### Problem
Process ordered events or intervals using sorting.

### Algorithm / Approach
Sort relevant positions or events and traverse them to obtain the required result.

### Source Code
[Open door_tracks.c](LAB_4/4.%20Application%20of%20sorting-IV/door_tracks.c)

---

## Application V — Application of Sorting-V

### Problem
Detect and process overlapping sets or intervals.

### Algorithm
Sort intervals according to their boundaries and compare neighbouring intervals.

### Complexity

```text
Sorting: O(n log n)
Traversal: O(n)
Total: O(n log n)
```

### Source Code
[Open overlapping_set.c](LAB_4/5.%20Application%20of%20sorting-V/overlapping_set.c)

---

## Application VI — Application of Sorting-VI

### Problem
Determine a common point or relationship among ordered intervals.

### Algorithm / Approach
Sort the interval boundaries and process them to determine the required common condition.

### Source Code
[Open common_point.c](LAB_4/6.%20Application%20of%20sorting-VI/common_point.c)

---

# LAB_4 Summary

| Application | Main Technique | Typical Complexity |
|---|---|---|
| I | Sorting paired items | Usually O(n log n) |
| II | Pair-sum search | O(n log n) |
| III | Target-based search | Usually O(n log n) or higher |
| IV | Event processing | Usually O(n log n) |
| V | Interval overlap | O(n log n) |
| VI | Interval/common-point processing | Usually O(n log n) |

---

# LAB_5 — Selection and Sorting Algorithms

This lab contains C implementations of selection algorithms and comparison-based sorting techniques.

## Application I — Median of Elements

### Problem
Given `n` unsorted elements, find their median without completely sorting the array.

### Algorithm
The program uses **QuickSelect**:

1. Select a pivot.
2. Partition the array.
3. Check the pivot's final position.
4. Continue in the required partition.

### Complexity

```text
Average Time: O(n)
Worst Case:   O(n²)
```

### Example

```text
Input: 1 7 3 9 5
Median: 5
```

### Source Code
[Open median.c](LAB_5/Q1/median.c)

---

## Application II — K-th Smallest Element

### Problem
Find the `k`-th smallest element of an unsorted array.

### Algorithm
Use QuickSelect and recursively search only the partition containing the required element.

### Complexity

```text
Average Time: O(n)
Worst Case:   O(n²)
```

### Example

```text
Array: 7 10 4 3 20 15
k = 3
3rd smallest = 7
```

### Validation

```text
1 <= k <= n
```

### Source Code
[Open k_element.c](LAB_5/Q2/k_element.c)

---

## Application III — Heap Sort

### Problem
Generate, store, and sort elements using Heap Sort.

### Algorithm

```text
Build Max Heap
        ↓
Move maximum to the end
        ↓
Heapify the remaining elements
```

### Complexity

```text
Time: O(n log n)
Auxiliary Space: O(1)
```

### Files

```text
Random input  → input2.txt
Sorted output → sorted2.txt
```

### Source Code
[Open heapsort.c](LAB_5/Q3/heapsort.c)

---

## Application IV — Quick Sort

### Problem
Generate, store, and sort elements using Quick Sort.

### Algorithm
Select a pivot, partition the array, and recursively sort both partitions.

### Complexity

```text
Best / Average: O(n log n)
Worst:          O(n²)
```

### Files

```text
Random input  → input.txt
Sorted output → sorted.txt
```

### Source Code
[Open quicksort.c](LAB_5/Q4/quicksort.c)

---

# LAB_5 Summary

| Application | Main Technique | Time Complexity |
|---|---|---|
| Median | QuickSelect | Average O(n) |
| K-th Smallest | QuickSelect | Average O(n) |
| Heap Sort | Heapify | O(n log n) |
| Quick Sort | Partition and recursion | Average O(n log n) |

---

# LAB_6 — Array, Matrix and Advanced Operations

This lab covers one-dimensional array operations, square-matrix operations, FFT-based convolution, and sorting through reversal procedures.

## Application I — 1D Array Operations

### Problem
Perform multiple operations on an unsorted one-dimensional array.

### Operations

```text
(i)   Maximum element
(ii)  First and second largest elements
(iii) Mean
(iv)  Median
(v)   Standard deviation
(vi)  Mode
(vii) Remove duplicates
(viii) Reverse the array
(ix)  Partition around a pivot
```

### Complexity

| Operation | Time Complexity |
|---|---|
| Maximum | O(n) |
| Largest Two | O(n) |
| Mean | O(n) |
| Median | O(n log n) |
| Standard Deviation | O(n) |
| Mode | O(n²) |
| Remove Duplicates | O(n²) |
| Reverse | O(n) |
| Partition | O(n) |

### Source Code
[Open 1Darray.c](LAB_6/1.%201D%20array%20operations%20and%20their%20complexities/1Darray.c)

---

## Application II — 2D Square Matrix Operations

### Problem
Perform mathematical operations on square matrices.

### Operations

```text
Matrix addition
Matrix multiplication
Zero matrix check
Symmetry check
Determinant
Transpose
Dominant eigenvalue and eigenvector
```

### Complexity

| Operation | Time Complexity |
|---|---|
| Addition | O(n²) |
| Multiplication | O(n³) |
| Zero Check | O(n²) |
| Symmetry Check | O(n²) |
| Determinant | O(n³) |
| Transpose | O(n²) |
| Eigen Computation | Iteration dependent |

### Source Code
[Open 2Dmatrix.c](LAB_6/2.%202D%20square%20matrix%20operations%20and%20their%20complexities/2Dmatrix.c)

---

## Application III — Convolution of Vectors

### Problem
Compute the convolution of two vectors efficiently.

### Algorithm
The program uses the **Fast Fourier Transform (FFT)**:

```text
Zero-pad vectors
      ↓
Compute FFT
      ↓
Multiply pointwise
      ↓
Compute inverse FFT
```

### Complexity

```text
Time: O(N log N)
```

where `N` is the padded power-of-two size.

### Example

```text
A = {1, 2, 3}
B = {4, 5, 6}

Convolution = {4, 13, 28, 27, 18}
```

### Source Code
[Open FTT.c](LAB_6/3.%20Convolution%20operation%20on%20vectors%20of%20size%20n/FTT.c)

---

## Application IV — Sorting via Reversal Procedure

### Problem
Sort a permutation using reversal operations.

### Algorithm
The program recursively partitions the values and uses reversals to rearrange subarrays while preserving the required ordering.

### Approach

```text
Divide the value range
        ↓
Partition elements
        ↓
Reverse required subarrays
        ↓
Recursively process both groups
```

### Output Information
The program reports the sorted permutation along with:

```text
Number of reversals
Total reversal cost
```

### Source Code
[Open reversal.c](LAB_6/4.%20Sorting%20via%20reversal%20procedure/reversal.c)

---

# LAB_6 Summary

| Application | Main Technique | Typical Complexity |
|---|---|---|
| 1D Array Operations | Scanning and sorting | Operation dependent |
| 2D Matrix Operations | Matrix algorithms | O(n²) to O(n³) |
| Vector Convolution | FFT | O(N log N) |
| Reversal Sorting | Recursive partitioning | Reversal dependent |

---

# Common Implementation Details

The programs throughout this repository demonstrate several recurring algorithmic techniques.

### Divide and Conquer

```text
Divide problem
     ↓
Solve smaller subproblems
     ↓
Combine results
```

Used in searching, matrix multiplication, recursion, and several sorting-related problems.

### Sorting as Preprocessing

```text
Unsorted Input
      ↓
Sort
      ↓
Efficient Scan / Search
```

Used extensively in LAB_4.

### Recursive Algorithms

Used in:

- Towers of Hanoi
- Divide-and-conquer problems
- Quick Sort
- QuickSelect
- FFT
- Reversal-based sorting

---

# Overall Complexity Summary

| Topic | Typical Time Complexity |
|---|---|
| Bubble Sort | O(n²) |
| Towers of Hanoi | O(2ⁿ) |
| Merge Sort | O(n log n) |
| Binary Search | O(log n) |
| Strassen's Multiplication | O(n^2.807) |
| QuickSelect | Average O(n) |
| Heap Sort | O(n log n) |
| Quick Sort | Average O(n log n) |
| Matrix Multiplication | O(n³) |
| FFT Convolution | O(N log N) |

---

# Conclusion

This repository provides practical implementations of major concepts from **Design and Analysis of Algorithms**.

The six laboratory assignments collectively cover:

```text
LAB_1 → Growth analysis and basic algorithms
LAB_2 → Dictionary and merge-based algorithms
LAB_3 → Divide and conquer
LAB_4 → Applications of sorting
LAB_5 → Selection and efficient sorting
LAB_6 → Arrays, matrices, FFT and reversal algorithms
```

Together, these programs demonstrate how selecting the appropriate algorithmic strategy and data representation can significantly improve problem-solving efficiency.

---

# Technologies Used

| Tool | Purpose |
|---|---|
| C | Implementation language |
| GCC | Compilation |
| C Standard Library | Core functionality |
| Gnuplot | Plot generation where applicable |
| Git and GitHub | Version control and repository hosting |

---

# License

This repository contains academic coursework and is published for reference and learning purposes. Please do not submit the code as your own work.

---

<p align="center">
  Maintained by <strong>Anurag Samal</strong> · CE, IIIT Bhubaneswar
</p>
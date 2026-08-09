# Design and Analysis of Algorithms

```{=html}
<p align="center">
```
`<strong>`{=html}DAA Laboratory Assignments --- Lab 01 & Lab
02`</strong>`{=html}
```{=html}
</p>
```
```{=html}
<p align="center">
```
`<img src="https://img.shields.io/badge/Language-C-A8B9CC?style=flat-square&logo=c&logoColor=white" />`{=html}
`<img src="https://img.shields.io/badge/Compiler-GCC-FE7A16?style=flat-square&logo=gnu&logoColor=white" />`{=html}
`<img src="https://img.shields.io/badge/Analysis-Asymptotic%20%2B%20Empirical-6E4AFF?style=flat-square" />`{=html}
`<img src="https://img.shields.io/badge/Plots-CSV%20%2B%20GNUPlot-1D9E5E?style=flat-square" />`{=html}
```{=html}
</p>
```

------------------------------------------------------------------------

## Introduction

This repository contains my solutions for the Design and Analysis of
Algorithms Laboratory. Each lab has its own folder and each question has
a separate folder containing its C source code and generated
experimental data or plots.

The programs combine algorithm implementation with theoretical and
empirical analysis. Where required, they count operations or measure
execution time and use the results to validate the expected order of
growth.

## Student Information

  Field        Details
  ------------ ----------------------------------------------
  Name         Anurag Samal
  Student ID   B525009
  Branch       Computer Engineering (CE)
  Institute    IIIT Bhubaneswar
  Course       Design and Analysis of Algorithms Laboratory
  Semester     B.Tech 3rd Semester
  Instructor   Dr. Ajaya Kumar Dash

## Repository Structure

``` text
DAA_Lab/
├── README.md
├── DAA_Lab_01/
│   ├── Q1_Putting_them_in_order/
│   ├── Q2_Fair_vs_Biased_Coin/
│   ├── Q3_Performance_Analysis_of_bubble_sort/
│   ├── Q4_Tower_of_Hanoi/
│   ├── Q5_Find_the_partition_point/
│   └── Q6_Element_uniqueness/
└── DAA_Lab_02/
    ├── Q1_Dictionary_Operations/
    ├── Q2_Merge_Sort_vs_Modified_Merge_Sort/
    └── Q3_Merging_k_Sorted_Arrays/
```

------------------------------------------------------------------------

# Lab Index

  ------------------------------------------------------------------------
  Lab                   Topic                                    Questions
  --------------------- --------------------- ----------------------------
  Lab 01                Growth of functions,                             6
                        empirical analysis,   
                        recurrences           

  Lab 02                Dictionary                                       3
                        operations,           
                        merge-sort variants,  
                        k-way merging         
  ------------------------------------------------------------------------

------------------------------------------------------------------------

# DAA Lab 01

> Growth rates, randomised simulation, and counting the work an
> algorithm actually does.

## Q1 --- Put Them in Order

Arrange the 12 given functions in increasing order of growth for
sufficiently large `n`.

The program compares `log2(f(n))` instead of raw function values to
avoid overflow while preserving ordering.

For `n = 10^6`, the obtained order is:

``` text
1/n < log2(n) < n^0.51 < 12*sqrt(n) < 50*sqrt(n) < n*log2(n)
< n^2-324 < 100n^2+6n < 2^32*n < 2n^3 < n^(log2 n) < 3^n
```

Important observation:

``` text
2^32 * n = Θ(n)
```

because `2^32` is a constant.

**Artifacts**

-   `Q1_order_of_growth.c`
-   `growth_order_data.csv`
-   `Q1_growth_order_plot.png`
-   `Q1_growth_order_linechart.png`

The plot uses `log2(f(n))` and a symlog y-axis so both very small and
extremely large values remain readable.

## Q2 --- Fair vs Biased Coin

Simulate coin tosses, verify that the fair-coin probability of heads
approaches `0.5`, and compare fair and biased coins.

Recorded experiment for 1,000,000 tosses:

-   Fair coin: **0.50038**
-   Coin with `p = 0.7`: **0.69989**

Complexity:

-   Time: `Θ(n)`
-   Space: `Θ(1)`

Program:

``` text
Q2_coin_toss.c
```

## Q3 --- Bubble Sort Performance

Compare:

1.  Bubble sort with early termination.
2.  Bubble sort that always performs all `n−1` passes.

  Version             Best Case   Worst Case   Space
  ------------------- ----------- ------------ -------
  Early termination   Ω(n)        O(n²)        Θ(1)
  Full passes         Θ(n²)       Θ(n²)        Θ(1)

For random data at `n = 2000`, the recorded comparison counts were
1,997,824 for early termination and 1,999,000 for full passes.

For sorted data, early termination required only 1,999 comparisons
versus 1,999,000 for the full-pass version.

**Artifacts**

-   `Q3_bubble_sort.c`
-   `bubble_sort_data.csv`
-   `bubble_sort_sorted_data.csv`
-   `Q3_bubble_sort_random_plot.png`
-   `Q3_bubble_sort_sorted_plot.png`

## Q4 --- Towers of Hanoi

The recurrence is:

``` text
T(n) = 2T(n−1) + 1
```

and its closed form is:

``` text
T(n) = 2^n − 1
```

For 20 discs:

``` text
1,048,575 moves
```

Complexity:

-   Time: `Θ(2^n)`
-   Recursion depth: `Θ(n)`

**Artifacts**

-   `Q4_tower_of_hanoi.c`
-   `hanoi_data.csv`
-   `Q4_hanoi_plot.png`
-   `Q4_hanoi_plot_logscale.png`

## Q5 --- Find the Partition Point

Given an array of 0s followed by 1s, find the transition index.

  Method          Time       Space
  --------------- ---------- -------
  Linear scan     Θ(n)       Θ(1)
  Binary search   Θ(log n)   Θ(1)

For a 1,000,000-element array with the boundary at index 333,333, the
recorded comparison counts were 333,334 for linear search and 20 for
binary search.

Program:

``` text
Q5_partition_point.c
```

## Q6 --- Element Uniqueness

Determine whether all `n` elements are distinct.

  Method          Time           Space
  --------------- -------------- -------
  Brute force     O(n²)          Θ(1)
  Sort and scan   Θ(n log n)     Θ(n)
  Hashing         Θ(n) average   Θ(n)

Program:

``` text
Q6_element_uniqueness.c
```

## Lab 01 Complexity Summary

  Q   Algorithm                       Time                     Space
  --- ------------------------------- ------------------------ ----------------
  1   Growth ordering using `qsort`   Θ(F log F), F=12         Θ(F)
  2   Coin toss simulation            Θ(n)                     Θ(1)
  3   Early-exit bubble sort          Ω(n) best, O(n²) worst   Θ(1)
  3   Full-pass bubble sort           Θ(n²)                    Θ(1)
  4   Towers of Hanoi                 Θ(2\^n)                  Θ(n) recursion
  5   Linear partition search         Θ(n)                     Θ(1)
  5   Binary partition search         Θ(log n)                 Θ(1)
  6   Brute-force uniqueness          O(n²)                    Θ(1)
  6   Sort and scan                   Θ(n log n)               Θ(n)
  6   Hashing                         Θ(n) average             Θ(n)

------------------------------------------------------------------------

# DAA Lab 02

> Dictionary operations, merge-sort variants, and efficient merging of
> multiple sorted arrays.

## Q1 --- Dictionary Operations

Analyse these seven dictionary operations:

-   Search
-   Insert
-   Delete
-   Maximum
-   Minimum
-   Predecessor
-   Successor

for:

-   Unsorted array
-   Sorted array
-   Singly linked unsorted list
-   Singly linked sorted list
-   Doubly linked unsorted list
-   Doubly linked sorted list

### Complexity Summary

  ----------------------------------------------------------------------------
  Data              Search       Insert       Delete    Min / Max      Pred. /
  Structure                                                              Succ.
  ----------- ------------ ------------ ------------ ------------ ------------
  Unsorted            O(n)         O(1)         O(n)         O(n)         O(n)
  Array                                                           

  Sorted          O(log n)         O(n)         O(n)         O(1)         O(1)
  Array                                                           

  Singly              O(n)         O(1)         O(n)         O(n)         O(n)
  Linked                                                          
  Unsorted                                                        

  Singly              O(n)         O(n)         O(n)  O(1) / O(n)         O(n)
  Linked                                                          
  Sorted                                                          

  Doubly              O(n)         O(1)         O(n)         O(n)         O(n)
  Linked                                                          
  Unsorted                                                        

  Doubly              O(n)         O(n)         O(n)  O(1) / O(n)         O(n)
  Linked                                                          
  Sorted                                                          
  ----------------------------------------------------------------------------

The exact linked-list complexity depends on implementation details and
maintained references; the table reflects the straightforward
implementations used for the lab.

**Files**

``` text
dictionary.c
dictionary.dat
dictionary.gnu
dictionary_complexity.png
```

## Q2 --- Merge Sort vs Modified Merge Sort

### Standard Merge Sort

The array is divided into two parts:

``` text
T(n) = 2T(n/2) + O(n)
```

Therefore:

``` text
O(n log2 n)
```

### Modified Three-Way Merge Sort

The assignment specifies:

1.  Divide the array into three parts.
2.  Recursively sort each third.
3.  Combine the results using a three-way merge.

Recurrence:

``` text
T(n) = 3T(n/3) + O(n)
```

Therefore:

``` text
O(n log3 n)
```

Since changing the logarithm base changes only a constant factor:

``` text
O(n log3 n) = O(n log n)
```

Thus, both algorithms have the same asymptotic complexity, although
their measured execution times can differ.

The C program:

-   Generates random input.
-   Gives both algorithms equivalent input.
-   Runs standard Merge Sort.
-   Runs modified three-way Merge Sort.
-   Measures time using `clock()`.
-   Writes results to `merge.dat`.

**Files**

``` text
merge.c
merge.dat
merge.gnu
merge_sort_comparison.png
```

## Q3 --- Merging `k` Sorted Arrays

Assume there are `k` sorted arrays, each containing `n` elements.

### Method 1 --- Sequential Merge

Merge the first two arrays, then merge the result with the third, and
continue.

Work:

``` text
2n + 3n + ... + kn
```

Therefore:

``` text
O(nk²)
```

### Method 2 --- Pairwise Merge

Merge arrays in pairs and repeat:

``` text
A1 + A2    A3 + A4    A5 + A6    A7 + A8
    ↓          ↓          ↓          ↓
       A12 + A34       A56 + A78
              ↓             ↓
             A1234 + A5678
                    ↓
               Final Array
```

Each level processes all `kn` elements and there are approximately
`log2(k)` levels.

Therefore:

``` text
O(nk log k)
```

  Method     Strategy               Worst-Case Time
  ---------- -------------------- -----------------
  Method 1   Sequential merging              O(nk²)
  Method 2   Pairwise merging           O(nk log k)

Method 2 becomes increasingly advantageous as `k` grows.

**Files**

``` text
merging_k_arrays.c
merging_k.dat
merging_k.gnu
merging_k_comparison.png
```

## Lab 02 Complexity Summary

  ---------------------------------------------------------------------------
  Q                 Algorithm         Worst-Case Time       Extra Space
  ----------------- ----------------- --------------------- -----------------
  1                 Dictionary        Depends on            Depends on
                    operations        structure/operation   implementation

  2                 Standard Merge    O(n log n)            O(n)
                    Sort                                    

  2                 Modified 3-Way    O(n log n)            O(n)
                    Merge Sort                              

  3                 Sequential k-way  O(nk²)                O(nk)
                    merging                                 

  3                 Pairwise k-way    O(nk log k)           O(nk)
                    merging                                 
  ---------------------------------------------------------------------------

------------------------------------------------------------------------

# Topics Covered

### Analysis

-   [x] Asymptotic notation --- Θ, O, Ω
-   [x] Ordering functions by growth rate
-   [x] Polynomial, superpolynomial, and exponential growth
-   [x] Constant factors
-   [x] Best-case and worst-case analysis
-   [x] Primitive operation counting
-   [x] Empirical order-of-growth analysis
-   [x] Divide-and-conquer recurrences
-   [x] Master theorem

### Algorithms

-   [x] `qsort`
-   [x] Bubble sort and early termination
-   [x] Binary search
-   [x] Brute-force uniqueness checking
-   [x] Sort-and-scan uniqueness checking
-   [x] Hashing
-   [x] Recursion
-   [x] Dictionary operations
-   [x] Merge Sort
-   [x] Three-Way Merge Sort
-   [x] Sequential k-way merging
-   [x] Pairwise k-way merging

### Randomisation and Recurrences

-   [x] Monte Carlo simulation
-   [x] Law of large numbers
-   [x] Biased sampling
-   [x] `T(n) = 2T(n−1) + 1`
-   [x] Closed-form verification
-   [x] Divide-and-conquer recurrences

------------------------------------------------------------------------

# Technologies Used

  Tool                           Purpose
  ------------------------------ -------------------------------------------
  C (C99 / C11)                  Implementation
  GCC                            Compilation
  C standard library             `stdio.h`, `stdlib.h`, `math.h`, `time.h`
  Python + matplotlib + pandas   Lab 01 plots
  GNUPlot                        Lab 02 plots
  CSV / DAT                      Experimental data
  VS Code + WSL                  Development
  Git + GitHub                   Version control

------------------------------------------------------------------------

# Compilation and Execution

Recommended compiler command:

``` bash
gcc -std=c11 -Wall -Wextra -O2 file.c -o output -lm
```

### Lab 01

``` bash
cd DAA_Lab_01/Q1_Putting_them_in_order
gcc -O2 -o Q1 Q1_order_of_growth.c -lm && ./Q1

cd ../Q2_Fair_vs_Biased_Coin
gcc -o Q2 Q2_coin_toss.c && ./Q2

cd ../Q3_Performance_Analysis_of_bubble_sort
gcc -o Q3 Q3_bubble_sort.c && ./Q3

cd ../Q4_Tower_of_Hanoi
gcc -o Q4 Q4_tower_of_hanoi.c && ./Q4

cd ../Q5_Find_the_partition_point
gcc -o Q5 Q5_partition_point.c && ./Q5

cd ../Q6_Element_uniqueness
gcc -O2 -o Q6 Q6_element_uniqueness.c && ./Q6
```

### Lab 02

``` bash
cd DAA_Lab_02/Q1_Dictionary_Operations
gcc -std=c11 -Wall -Wextra -O2 dictionary.c -o dictionary
./dictionary

cd ../Q2_Merge_Sort_vs_Modified_Merge_Sort
gcc -std=c11 -Wall -Wextra -O2 merge.c -o merge
./merge

cd ../Q3_Merging_k_Sorted_Arrays
gcc -std=c11 -Wall -Wextra -O2 merging_k_arrays.c -o merging_k_arrays
./merging_k_arrays
```

On Windows/MinGW-w64, run the generated `.exe` files.

------------------------------------------------------------------------

# Plot Generation

## Lab 01 --- Python / Matplotlib

From `DAA_Lab_01`:

``` bash
pip install pandas matplotlib --break-system-packages
python3 generate_plots.py
```

## Lab 02 --- GNUPlot

``` bash
cd DAA_Lab_02/Q1_Dictionary_Operations
gnuplot -persist dictionary.gnu

cd ../Q2_Merge_Sort_vs_Modified_Merge_Sort
gnuplot -persist merge.gnu

cd ../Q3_Merging_k_Sorted_Arrays
gnuplot -persist merging_k.gnu
```

Plots should clearly show input size, measured quantity, algorithm
names, and relevant complexity. If a logarithmic axis is used, it should
be explicitly labelled.

------------------------------------------------------------------------

# Experimental Notes

Execution times depend on processor speed, current system load, compiler
optimisation, operating system, random input, and input size. Individual
timing values should therefore not be treated as universal constants.

The goal is to observe **order of growth** and compare measured
behaviour with theoretical complexity.

For fair comparisons, algorithms being compared should receive
equivalent input data whenever possible.

------------------------------------------------------------------------

# Repository Conventions

-   One top-level folder per lab: `DAA_Lab_<nn>`.
-   One subfolder per question.
-   Question folders use `Q<number>_<question_title>`.
-   Source files use descriptive names.
-   Generated data stays with the program that created it.
-   GNUPlot scripts stay with their corresponding `.dat` files.
-   PNG plots stay with the corresponding experiment.
-   Plots should label axes, algorithms, and relevant complexity.
-   Recommended flags:

``` bash
gcc -std=c11 -Wall -Wextra -O2 file.c -o output -lm
```

------------------------------------------------------------------------

# License

Coursework for educational purposes. Feel free to read, run, and learn
from the implementations; please do not submit the repository as someone
else's work.

```{=html}
<p align="center">
```
Maintained by `<strong>`{=html}Anurag`</strong>`{=html} · CE, IIIT
Bhubaneswar
```{=html}
</p>
```

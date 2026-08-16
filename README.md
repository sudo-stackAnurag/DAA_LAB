<h1 align="center">Design and Analysis of Algorithms</h1>

<p align="center">
  <strong>DAA Laboratory Assignments — IIIT Bhubaneswar</strong>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-A8B9CC?style=flat-square&logo=c&logoColor=white" alt="C" />
  <img src="https://img.shields.io/badge/Compiler-GCC-FE7A16?style=flat-square&logo=gnu&logoColor=white" alt="GCC" />
  <img src="https://img.shields.io/badge/Platform-Windows-0078D4?style=flat-square&logo=windows&logoColor=white" alt="Windows" />
</p>

---

## Introduction

This repository contains my solutions for the **Design and Analysis of Algorithms (DAA) Laboratory**. Each lab is organized into separate folders, with one folder for each question and the corresponding source code and experiment files.

The programs are written in **C** and include implementations of searching, sorting, divide-and-conquer algorithms, recurrence-based problems, and empirical analysis of algorithm performance.

---

## Student Information

| Field | Details |
| --- | --- |
| **Name** | Anurag Samal |
| **Student ID** | B525009 |
| **Branch** | Computer Engineering (CE) |
| **Institute** | IIIT Bhubaneswar |
| **Course** | Design and Analysis of Algorithms Laboratory |
| **Semester** | B.Tech 3rd Semester |
| **Instructor** | Dr. Ajaya Kumar Dash |

---

## Repository Structure

```text
DAA_LAB/
│
├── README.md
│
├── LAB_1/
│   ├── 1. Put them in Order/
│   ├── 2. Fair vs Biased coin/
│   ├── 3. Performance analysis of bubble sort/
│   ├── 4. Towers of Hanoi/
│   ├── 5. Find the partition point/
│   └── 6. Element uniqueness/
│
├── LAB_2/
│   ├── 1. Dictionary Operations/
│   ├── 2. Merge sort vs Modified merge sort/
│   └── 3. Merging k sorted arrays/
│
└── LAB_3/
    ├── 1. Binary vs Ternary Search/
    ├── 2. Search the Defective Coin/
    ├── 3. Max and Min using D&C Approach/
    ├── 4. Matrix Multiplication using D&C Approach/
    ├── 5. Multiply special-pattern square matrices using D&C approach/
    └── 6. Use of loop invariants in sorting/
```

---

## Lab Index

| Lab | Topic | Questions | Folder |
| --- | --- | ---: | --- |
| **Lab 1** | Growth of functions, simulation, sorting and recurrences | 6 | [LAB_1](LAB_1) |
| **Lab 2** | Dictionary operations, merge sort and k-way merging | 3 | [LAB_2](LAB_2) |
| **Lab 3** | Divide and conquer algorithms and loop invariants | 6 | [LAB_3](LAB_3) |

---

# LAB 1

### 1. Put them in Order

Arrange the given functions in increasing order of growth for sufficiently large `n`.

**Source:** [growth.c](LAB_1/1.%20Put%20them%20in%20Order/growth.c)  
**Data:** [growth.dat](LAB_1/1.%20Put%20them%20in%20Order/growth.dat)  
**Plot:** [plot.png](LAB_1/1.%20Put%20them%20in%20Order/plot.png)  
**Gnuplot:** [plot.gnu](LAB_1/1.%20Put%20them%20in%20Order/plot.gnu)

### 2. Fair vs Biased Coin

Simulate coin tosses and compare the behaviour of a fair coin with biased coins.

**Source:** [coin.c](LAB_1/2.%20Fair%20vs%20Biased%20coin/coin.c)  
**Data:** [coin.dat](LAB_1/2.%20Fair%20vs%20Biased%20coin/coin.dat)  
**Plot:** [coin.png](LAB_1/2.%20Fair%20vs%20Biased%20coin/coin.png)  
**Gnuplot:** [coin.gnu](LAB_1/2.%20Fair%20vs%20Biased%20coin/coin.gnu)

### 3. Performance Analysis of Bubble Sort

Compare the performance of bubble sort and analyse the number of operations as the input size grows.

**Source:** [bubble.c](LAB_1/3.%20Performance%20analysis%20of%20bubble%20sort/bubble.c)  
**Data:** [bubble.dat](LAB_1/3.%20Performance%20analysis%20of%20bubble%20sort/bubble.dat)  
**Plot:** [bubble.png](LAB_1/3.%20Performance%20analysis%20of%20bubble%20sort/bubble.png)  
**Gnuplot:** [bubble.gnu](LAB_1/3.%20Performance%20analysis%20of%20bubble%20sort/bubble.gnu)

### 4. Towers of Hanoi

Implement the Tower of Hanoi problem and analyse its recursive growth.

**Source:** [TOH.c](LAB_1/4.%20Towers%20of%20Hanoi/TOH.c)  
**Data:** [toh.dat](LAB_1/4.%20Towers%20of%20Hanoi/toh.dat)  
**Plot:** [toh.png](LAB_1/4.%20Towers%20of%20Hanoi/toh.png)  
**Gnuplot:** [toh.gnu](LAB_1/4.%20Towers%20of%20Hanoi/toh.gnu)

### 5. Find the Partition Point

Find the transition point in an array containing a sequence of `0`s followed by `1`s.

**Source:** [partition.c](LAB_1/5.%20Find%20the%20partition%20point/partition.c)

### 6. Element Uniqueness

Determine whether all elements in a given collection are unique and analyse the algorithmic cost.

**Source:** [unique.c](LAB_1/6.%20Element%20uniqueness/unique.c)

---

# LAB 2

### 1. Dictionary Operations

Analyse the costs of dictionary operations using different representations and compare their growth experimentally.

**Source:** [dictionary_growth.c](LAB_2/1.%20Dictionary%20Operations/dictionary_growth.c)  
**Data:** [dictionary.dat](LAB_2/1.%20Dictionary%20Operations/dictionary.dat)  
**Plot:** [dictionary_complexity.png](LAB_2/1.%20Dictionary%20Operations/dictionary_complexity.png)  
**Gnuplot:** [dictionary.gnu](LAB_2/1.%20Dictionary%20Operations/dictionary.gnu)

### 2. Merge Sort vs Modified Merge Sort

Compare standard merge sort with a modified multi-way merge sort and analyse their performance.

**Source:** [merge_sort.c](LAB_2/2.%20Merge%20sort%20vs%20Modified%20merge%20sort/merge_sort.c)  
**Data:** [merge.dat](LAB_2/2.%20Merge%20sort%20vs%20Modified%20merge%20sort/merge.dat)  
**Plot:** [merge_sort_comparison.png](LAB_2/2.%20Merge%20sort%20vs%20Modified%20merge%20sort/merge_sort_comparison.png)  
**Gnuplot:** [merge.gnu](LAB_2/2.%20Merge%20sort%20vs%20Modified%20merge%20sort/merge.gnu)

### 3. Merging k Sorted Arrays

Compare different strategies for merging `k` sorted arrays and study their time complexity.

**Source:** [merging_k_arrays.c](LAB_2/3.%20Merging%20k%20sorted%20arrays/merging_k_arrays.c)  
**Data:** [merging_k.dat](LAB_2/3.%20Merging%20k%20sorted%20arrays/merging_k.dat)  
**Plot:** [merging_k_comparison.png](LAB_2/3.%20Merging%20k%20sorted%20arrays/merging_k_comparison.png)  
**Gnuplot:** [merging_k.gnu](LAB_2/3.%20Merging%20k%20sorted%20arrays/merging_k.gnu)

---

# LAB 3

### 1. Binary vs Ternary Search

Search a sorted array using both binary search and ternary search and compare their number of comparisons.

**Source:** [BTsearch.c](LAB_3/1.%20Binary%20vs%20Ternary%20Search/BTsearch.c)  
**Data:** [search_data.dat](LAB_3/1.%20Binary%20vs%20Ternary%20Search/search_data.dat)  
**Gnuplot:** [plot.gnu](LAB_3/1.%20Binary%20vs%20Ternary%20Search/plot.gnu)

### 2. Search the Defective Coin

Use a divide-and-conquer strategy to identify a defective coin using a balance-scale comparison model.

**Source:** [Dcoin.c](LAB_3/2.%20Search%20the%20Defective%20Coin/Dcoin.c)  
**Data:** [data.dat](LAB_3/2.%20Search%20the%20Defective%20Coin/data.dat)  
**Gnuplot:** [Dcoin.gnu](LAB_3/2.%20Search%20the%20Defective%20Coin/Dcoin.gnu)

### 3. Max and Min using D&C Approach

Find both the maximum and minimum elements of an array using a divide-and-conquer approach.

**Source:** [minmax.c](LAB_3/3.%20Max%20and%20Min%20using%20D%26C%20Approach/minmax.c)

### 4. Matrix Multiplication using D&C Approach

Implement matrix multiplication using **Strassen's divide-and-conquer algorithm**, reducing the number of recursive multiplications from eight to seven.

**Source:** [strassen.c](LAB_3/4.%20Matrix%20Multiplication%20using%20D%26C%20Approach/strassen.c)

### 5. Multiply Special-Pattern Square Matrices using D&C Approach

Exploit the recursive structure of special-pattern square matrices to perform multiplication more efficiently than the standard `O(n³)` approach.

**Source:** [specialmat.c](LAB_3/5.%20Multiply%20special-pattern%20square%20matrices%20using%20D%26C%20approach/specialmat.c)  
**Gnuplot:** [specialmat.gnu](LAB_3/5.%20Multiply%20special-pattern%20square%20matrices%20using%20D%26C%20approach/specialmat.gnu)

### 6. Use of Loop Invariants in Sorting

State, initialise, maintain and terminate a loop invariant for a sorting algorithm and use it to establish correctness.

**Source:** [loopsorting.c](LAB_3/6.%20Use%20of%20loop%20invariants%20in%20sorting/loopsorting.c)

---

## Notes

- The `.c` files contain the main implementations for each assignment.
- `.dat` files contain generated experimental data where applicable.
- `.gnu` files contain the Gnuplot scripts used to generate plots.
- `.png` files contain the resulting plots.
- `.exe` files are compiled Windows executables and are included where available.

---

## Language & Tools

- **C** — Algorithm implementations
- **GCC** — C compiler
- **Gnuplot** — Experimental data visualisation
- **Git & GitHub** — Version control

---

<p align="center">
  <strong>Design and Analysis of Algorithms Laboratory</strong>
</p>

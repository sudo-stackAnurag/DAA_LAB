<div align="center">

#  Design and Analysis of Algorithms Laboratory

### DAA Lab Assignments | C Programming | GNUPlot

A collection of **Design and Analysis of Algorithms (DAA)** laboratory programs implemented in **C**, focusing on algorithm design, complexity analysis, recursion, searching, sorting, probability simulations, and graphical performance visualization using **GNUPlot**.

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![Compiler](https://img.shields.io/badge/Compiler-GCC-orange.svg)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-green.svg)
![Graphs](https://img.shields.io/badge/Visualization-GNUPlot-red.svg)
![License](https://img.shields.io/badge/License-MIT-brightgreen.svg)

</div>

---

#  Student Information

| Field | Details |
|-------|---------|
| **Name** | Anurag Samal |
| **ID** | B525009 |
| **Course** | Design and Analysis of Algorithms Laboratory |
| **Instructor** | Dr. Ajaya Kumar Dash |
| **Language Used** | C (C99 Standard) |
| **Compiler** | GCC |
| **IDE** | Visual Studio Code |
| **Graphing Tool** | GNUPlot |

---

#  About the Repository

This repository contains my laboratory implementations for the **Design and Analysis of Algorithms (DAA)** course.

The objective of these programs is to understand the practical implementation of classical algorithms and verify their theoretical analysis through experimentation and graphical visualization.

The repository includes:

- Mathematical Growth Analysis
- Probability Simulations
- Sorting Algorithms
- Recursive Algorithms
- Searching Algorithms
- Complexity Analysis
- Graph Generation using GNUPlot

Each program is written in **C**, documented, and accompanied by explanations of the algorithm, time complexity, and (where applicable) performance graphs.

---

#  Repository Structure

```text
DAA_LAB
│
├── README.md
│
└── LAB_1
    │
    ├── 1. Put them in Order
    │   ├── growth.c
    │   ├── growth.dat
    │   └── plot.gnu
    │
    ├── 2. Fair vs Biased coin
    │   ├── coin.c
    │   ├── coin.dat
    │   └── coin.gnu
    │
    ├── 3. Performance analysis of bubble sort
    │   ├── bubble.c
    │   ├── bubble.dat
    │   └── bubble.gnu
    │
    ├── 4. Towers of Hanoi
    │   ├── TOH.c
    │   ├── toh.dat
    │   └── toh.gnu
    │
    ├── 5. Find the partition point
    │   └── partition.c
    │
    └── 6. Element uniqueness
        └── unique.c
```

---

#  Lab Contents

| Problem | Title | Algorithm |
|----------|-------|-----------|
| 1 | Growth Rate Analysis | Asymptotic Analysis |
| 2 | Fair vs Biased Coin Simulation | Probability Simulation |
| 3 | Bubble Sort Performance Analysis | Sorting |
| 4 | Tower of Hanoi | Recursion |
| 5 | Partition Point Detection | Binary Search |
| 6 | Element Uniqueness | Brute Force Search |

---

#  Problem Descriptions

---

##  Problem 1 – Growth Rate Analysis

### Objective

Compare various mathematical functions according to their asymptotic growth.

### Concepts Covered

- Big-O Notation
- Growth of Functions
- Mathematical Modelling

### Functions Analysed

- 1/n
- log₂(n)
- √n
- n
- n log₂(n)
- n²
- n³
- n^(log₂n)
- 3ⁿ

### Output

- Numerical Data
- GNUPlot Graph
- Growth Comparison

---

##  Problem 2 – Fair vs Biased Coin Simulation

### Objective

Simulate repeated coin tosses to verify probability experimentally.

### Concepts Covered

- Random Number Generation
- Probability
- Law of Large Numbers

### Output

- Probability of Head
- Comparison between Fair and Biased Coins
- Probability Graph

---

##  Problem 3 – Bubble Sort Performance Analysis

### Objective

Compare the normal Bubble Sort algorithm with an optimized version.

### Features

✔ Normal Bubble Sort

✔ Optimized Bubble Sort

✔ Number of Comparisons

✔ Performance Graph

### Observation

The optimized version terminates early if the array becomes sorted, significantly reducing comparisons for already sorted or nearly sorted arrays.

---

##  Problem 4 – Tower of Hanoi

### Objective

Implement the recursive Tower of Hanoi algorithm and analyse its growth.

### Concepts Covered

- Recursion
- Recurrence Relation
- Exponential Growth

Formula

```
Moves = 2ⁿ − 1
```

Output

- Sequence of Moves
- Total Moves
- Growth Graph

---

##  Problem 5 – Partition Point Detection

### Objective

Given an array consisting of 0's followed by 1's, determine the transition point.

Example

```
00001111
```

Transition

```
0000|1111
     ↑
```

Algorithm Used

- Binary Search

Time Complexity

```
O(log n)
```

---

##  Problem 6 – Element Uniqueness

### Objective

Determine whether duplicate elements exist among randomly generated numbers.

Algorithm

- Brute Force Comparison

Features

- Random Number Generation
- Duplicate Detection
- Complexity Analysis

---

#  Time Complexity Summary

| Problem | Time Complexity | Space Complexity |
|----------|-----------------|------------------|
| Growth Rate Analysis | O(n) | O(1) |
| Coin Simulation | O(n) | O(1) |
| Bubble Sort | O(n²) | O(1) |
| Tower of Hanoi | O(2ⁿ) | O(n) |
| Partition Point | O(log n) | O(1) |
| Element Uniqueness | O(n²) | O(1) |

---

#  Graph Generation

The following experiments generate graphs using **GNUPlot**.

- Growth Rate Analysis
- Coin Toss Simulation
- Bubble Sort Comparison
- Tower of Hanoi

Example

```bash
gnuplot -persist bubble.gnu
```

---

#  Compilation

Using GCC

```bash
gcc filename.c -o output
```

Example

```bash
gcc bubble.c -o bubble
```

Run

Windows

```bash
bubble.exe
```

Linux

```bash
./bubble
```

---

#  Requirements

- GCC Compiler
- GNUPlot
- Visual Studio Code
- Git

---

#  Learning Outcomes

After completing these laboratory exercises, the following concepts are understood:

- ✔ Asymptotic Analysis
- ✔ Growth Functions
- ✔ Probability Simulation
- ✔ Bubble Sort Optimization
- ✔ Binary Search
- ✔ Divide and Conquer
- ✔ Recursion
- ✔ Complexity Analysis
- ✔ Performance Evaluation
- ✔ Experimental Verification

---



#  Contributions

This repository is maintained as part of my academic coursework. Suggestions and improvements are always welcome. Feel free to fork the repository, raise issues, or submit pull requests for enhancements.

---

# License

This project is licensed under the **MIT License**.

You are free to use the code for learning purposes. If you use any part of this repository, kindly provide appropriate credit.

---

<div align="center">

### If you found this repository useful, consider giving it a star!



</div>
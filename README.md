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

This repository holds my solutions for the **Design and Analysis of Algorithms (DAA) Laboratory** at IIIT Bhubaneswar. Every lab session gets its own folder, and inside that, every question gets its own subfolder holding the source file for that question plus anything it generates (DAT data, PNG plots).

Most of these questions ask for more than "does it run" — they ask what happens as `n` grows. So the programs here do two jobs: solve the problem, and instrument it — counting comparisons, counting moves, tabulating values across a range of `n` — then export that data so the growth can be plotted rather than just asserted.

---

## Student Information

| Field      | Details                                      |
| ---------- | -------------------------------------------- |
| Name       | Anurag Samal                                 |
| Student ID | B525009                                      |
| Branch     | Computer Engineering (CE)                    |
| Institute  | IIIT Bhubaneswar                             |
| Course     | Design and Analysis of Algorithms Laboratory |
| Semester   | B.Tech 3rd Semester                          |
| Instructor | Dr. Ajaya Kumar Dash                         |

---

## About the Repository

- Written entirely in **C**, compiled with **GCC**.
- One top-level folder per lab (`LAB_1`, `LAB_2`, `LAB_3`).
- Inside each lab folder, one subfolder per question, named after the question itself (e.g. `1. Put them in Order`, `4. Towers of Hanoi`), holding that question's source file plus generated data and plots where applicable.
- File names describe the problem, such as `growth.c`, `bubble.c`, `TOH.c`, and `BTsearch.c`.
- Programs that study growth or performance write their measurements to a **DAT** file inside their own question folder, which is then plotted and committed as a **PNG** next to it.
- Plots are generated with **Gnuplot** scripts (`.gnu`) stored alongside the experimental data and output plots, so the graphs can be regenerated from the committed data.
- No external C libraries — only the C standard library (`stdio.h`, `stdlib.h`, `math.h`, `time.h`).

---

## Repository Structure

```text
DAA_LAB/
│
├── README.md
│
├── LAB_1/
│   ├── 1. Put them in Order/
│   │   ├── growth.c
│   │   ├── growth.dat
│   │   ├── growth.exe
│   │   ├── plot.gnu
│   │   └── plot.png
│   │
│   ├── 2. Fair vs Biased coin/
│   │   ├── coin.c
│   │   ├── coin.dat
│   │   ├── coin.exe
│   │   ├── coin.gnu
│   │   └── coin.png
│   │
│   ├── 3. Performance analysis of bubble sort/
│   │   ├── bubble.c
│   │   ├── bubble.dat
│   │   ├── bubble.exe
│   │   ├── bubble.gnu
│   │   └── bubble.png
│   │
│   ├── 4. Towers of Hanoi/
│   │   ├── TOH.c
│   │   ├── TOH.exe
│   │   ├── toh.dat
│   │   ├── toh.gnu
│   │   └── toh.png
│   │
│   ├── 5. Find the partition point/
│   │   ├── partition.c
│   │   └── partition.exe
│   │
│   └── 6. Element uniqueness/
│       ├── unique.c
│       └── unique.exe
│
├── LAB_2/
│   ├── 1. Dictionary Operations/
│   │   ├── dictionary_growth.c
│   │   ├── dictionary.dat
│   │   ├── dictionary.exe
│   │   ├── dictionary.gnu
│   │   └── dictionary_complexity.png
│   │
│   ├── 2. Merge sort vs Modified merge sort/
│   │   ├── merge_sort.c
│   │   ├── merge.dat
│   │   ├── merge.exe
│   │   ├── merge.gnu
│   │   └── merge_sort_comparison.png
│   │
│   └── 3. Merging k sorted arrays/
│       ├── merging_k_arrays.c
│       ├── merging_k.dat
│       ├── mergearray.exe
│       ├── merging_k.gnu
│       └── merging_k_comparison.png
│
└── LAB_3/
    ├── 1. Binary vs Ternary Search/
    │   ├── BTsearch.c
    │   ├── BTsearch.exe
    │   ├── plot.gnu
    │   └── search_data.dat
    │
    ├── 2. Search the Defective Coin/
    │   ├── Dcoin.c
    │   ├── Dcoin.exe
    │   ├── Dcoin.gnu
    │   └── data.dat
    │
    ├── 3. Max and Min using D&C Approach/
    │   ├── minmax.c
    │   └── minmax.exe
    │
    ├── 4. Matrix Multiplication using D&C Approach/
    │   ├── strassen.c
    │   └── strassen.exe
    │
    ├── 5. Multiply special-pattern square matrices using D&C approach/
    │   ├── specialmat.c
    │   ├── specialmat.exe
    │   └── specialmat.gnu
    │
    └── 6. Use of loop invariants in sorting/
        ├── loopsorting.c
        └── loopsorting.exe
```

---

## Lab Index

| Lab    | Topic                                                    | Questions | Folder |
| ------ | -------------------------------------------------------- | --------- | ------ |
| Lab 01 | Growth of functions, empirical analysis, recurrences     | 6 | [LAB_1](LAB_1) |
| Lab 02 | Dictionary operations, merge sort variants, k-way merging | 3 | [LAB_2](LAB_2) |
| Lab 03 | Divide and conquer algorithms and loop invariants | 6 | [LAB_3](LAB_3) |

---

## LAB_1

> Growth rates, randomised simulation, sorting, recursion, and counting the work an algorithm actually does.

| #   | Question                 | Description                                                                                                                | File                                                                                      |
| --- | ------------------------ | -------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------- |
| 1   | Put them in Order        | Arrange the given functions in increasing order of growth for sufficiently large `n`.                                       | [Q1/growth.c](LAB_1/1.%20Put%20them%20in%20Order/growth.c) |
| 2   | Fair vs Biased Coin      | Simulate coin tosses and compare a fair coin against biased coins.                                                          | [Q2/coin.c](LAB_1/2.%20Fair%20vs%20Biased%20coin/coin.c) |
| 3   | Bubble Sort Performance  | Analyse bubble sort performance by counting operations as the input size grows.                                            | [Q3/bubble.c](LAB_1/3.%20Performance%20analysis%20of%20bubble%20sort/bubble.c) |
| 4   | Towers of Hanoi          | Simulate the puzzle, tabulate the number of moves for `n` discs, and study its recursive growth.                            | [Q4/TOH.c](LAB_1/4.%20Towers%20of%20Hanoi/TOH.c) |
| 5   | Find the Partition Point | Given an array of 0s followed by 1s, locate the transition point.                                                           | [Q5/partition.c](LAB_1/5.%20Find%20the%20partition%20point/partition.c) |
| 6   | Element Uniqueness       | Check whether the given elements are unique and reason about the algorithmic cost.                                         | [Q6/unique.c](LAB_1/6.%20Element%20uniqueness/unique.c) |

---

## Highlight — Q1 compares growth without relying on raw magnitude alone

`growth.c` studies the relative growth of the functions in the assignment. The accompanying `growth.dat` file records the experimental values, while `plot.gnu` and `plot.png` provide the visual analysis.

The important idea is that asymptotic comparison is about how functions behave as `n` becomes large, rather than only comparing their values for one small input.

---

## LAB_2

> Dictionary operations, merge sort variants, and strategies for merging k sorted arrays.

| #   | Question                          | Description                                                                                                  | File                                                                                                      |
| --- | --------------------------------- | ------------------------------------------------------------------------------------------------------------ | --------------------------------------------------------------------------------------------------------- |
| 1   | Dictionary Operations             | Analyse dictionary operations and compare their behaviour experimentally.                                    | [Q1/dictionary_growth.c](LAB_2/1.%20Dictionary%20Operations/dictionary_growth.c) |
| 2   | Merge Sort vs Modified Merge Sort | Compare standard merge sort with the modified merge-sort approach and analyse their performance.              | [Q2/merge_sort.c](LAB_2/2.%20Merge%20sort%20vs%20Modified%20merge%20sort/merge_sort.c) |
| 3   | Merging k Sorted Arrays           | Compare strategies for merging `k` sorted arrays and study their time complexity.                             | [Q3/merging_k_arrays.c](LAB_2/3.%20Merging%20k%20sorted%20arrays/merging_k_arrays.c) |

---

## Highlight — Lab 2 focuses on the cost of different algorithmic strategies

The Lab 2 programs are accompanied by experimental data and plots. The purpose is to connect the theoretical complexity of dictionary operations, merge-sort variants, and k-way merging with measured behaviour as the input size changes.

---

## LAB_3

> Divide and conquer, end to end: search, a balance-scale puzzle, selection, matrix multiplication, special-pattern matrices, and loop invariants.

| #   | Question                          | Description                                                                                                                        | File                                                                                                                     |
| --- | ---------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------ |
| 1   | Binary vs Ternary Search           | Search a sorted array with both strategies and compare their number of comparisons.                                               | [Q1/BTsearch.c](LAB_3/1.%20Binary%20vs%20Ternary%20Search/BTsearch.c) |
| 2   | Search the Defective Coin          | Find the defective coin using a divide-and-conquer balance-scale strategy.                                                         | [Q2/Dcoin.c](LAB_3/2.%20Search%20the%20Defective%20Coin/Dcoin.c) |
| 3   | Max and Min using D&C              | Find both the maximum and minimum of an array using a divide-and-conquer approach.                                                 | [Q3/minmax.c](LAB_3/3.%20Max%20and%20Min%20using%20D%26C%20Approach/minmax.c) |
| 4   | Matrix Multiplication using D&C    | Multiply matrices using Strassen's divide-and-conquer method.                                                                     | [Q4/strassen.c](LAB_3/4.%20Matrix%20Multiplication%20using%20D%26C%20Approach/strassen.c) |
| 5   | Multiply Special-Pattern Matrices  | Exploit the recursive structure of special-pattern square matrices for multiplication.                                            | [Q5/specialmat.c](LAB_3/5.%20Multiply%20special-pattern%20square%20matrices%20using%20D%26C%20approach/specialmat.c) |
| 6   | Loop Invariants in Sorting         | State, maintain and use a loop invariant to establish the correctness of a sorting algorithm.                                     | [Q6/loopsorting.c](LAB_3/6.%20Use%20of%20loop%20invariants%20in%20sorting/loopsorting.c) |

---

## Highlight — Divide and conquer connects the Lab 3 problems

Lab 3 applies the divide-and-conquer idea to several different problems. Binary search reduces the search space recursively, the defective-coin problem divides the candidate set, max-min reduces the number of comparisons through paired recursion, and Strassen's algorithm reduces the number of recursive matrix multiplications.

The special-pattern matrix problem goes one step further by exploiting additional structure in the input rather than treating the matrix as completely arbitrary.

---

## Results and Artifacts

The simulation and measurement programs export their data; the plots are committed next to them inside their own question folder.

| Data | Plot | Produced by | What it shows |
| --- | --- | --- | --- |
| [Q1/growth.dat](LAB_1/1.%20Put%20them%20in%20Order/growth.dat) | [Q1/plot.png](LAB_1/1.%20Put%20them%20in%20Order/plot.png) | Q1 | Experimental growth behaviour of the functions in the assignment. |
| [Q2/coin.dat](LAB_1/2.%20Fair%20vs%20Biased%20coin/coin.dat) | [Q2/coin.png](LAB_1/2.%20Fair%20vs%20Biased%20coin/coin.png) | Q2 | Experimental coin-toss behaviour for fair and biased coins. |
| [Q3/bubble.dat](LAB_1/3.%20Performance%20analysis%20of%20bubble%20sort/bubble.dat) | [Q3/bubble.png](LAB_1/3.%20Performance%20analysis%20of%20bubble%20sort/bubble.png) | Q3 | Bubble-sort performance as input size changes. |
| [Q4/toh.dat](LAB_1/4.%20Towers%20of%20Hanoi/toh.dat) | [Q4/toh.png](LAB_1/4.%20Towers%20of%20Hanoi/toh.png) | Q4 | Tower of Hanoi growth with increasing number of discs. |
| [Q1/dictionary.dat](LAB_2/1.%20Dictionary%20Operations/dictionary.dat) | [Q1/dictionary_complexity.png](LAB_2/1.%20Dictionary%20Operations/dictionary_complexity.png) | Lab 2 Q1 | Experimental dictionary-operation behaviour. |
| [Q2/merge.dat](LAB_2/2.%20Merge%20sort%20vs%20Modified%20merge%20sort/merge.dat) | [Q2/merge_sort_comparison.png](LAB_2/2.%20Merge%20sort%20vs%20Modified%20merge%20sort/merge_sort_comparison.png) | Lab 2 Q2 | Comparison of merge-sort approaches. |
| [Q3/merging_k.dat](LAB_2/3.%20Merging%20k%20sorted%20arrays/merging_k.dat) | [Q3/merging_k_comparison.png](LAB_2/3.%20Merging%20k%20sorted%20arrays/merging_k_comparison.png) | Lab 2 Q3 | Comparison of k-way merging strategies. |
| [Q1/search_data.dat](LAB_3/1.%20Binary%20vs%20Ternary%20Search/search_data.dat) | — | Lab 3 Q1 | Experimental comparison data for binary and ternary search. |
| [Q2/data.dat](LAB_3/2.%20Search%20the%20Defective%20Coin/data.dat) | — | Lab 3 Q2 | Experimental defective-coin data. |

---

## Complexity Summary

| #   | Program                                                  | Time                            | Space                |
| --- | -------------------------------------------------------- | ------------------------------- | -------------------- |
| 1   | Growth ordering                                          | Depends on the functions evaluated | Depends on implementation |
| 2   | Coin toss simulation                                     | Θ(n) in the number of tosses    | Θ(1)                 |
| 3   | Bubble sort                                              | O(n²) worst case               | Θ(1) auxiliary       |
| 4   | Towers of Hanoi                                          | Θ(2ⁿ) moves                     | Θ(n) recursion depth |
| 5   | Partition point — linear scan                            | Θ(n)                            | Θ(1)                 |
| 6   | Element uniqueness — pairwise comparison                 | O(n²)                           | Θ(1) auxiliary       |

**LAB_2**

| #   | Program                                        | Time                                                        | Space           |
| --- | ---------------------------------------------- | ----------------------------------------------------------- | --------------- |
| 1   | Dictionary operations                           | Depends on the chosen representation and operation          | Depends on representation |
| 2   | Merge sort                                     | Θ(n log n)                                                  | Θ(n) auxiliary  |
| 3   | k-way merge                                    | Depends on the merging strategy                             | Depends on implementation |

**LAB_3**

| #   | Program                                          | Time                            | Space                       |
| --- | ------------------------------------------------- | -------------------------------- | ----------------------------- |
| 1   | Binary search                                    | Θ(log n)                        | Θ(1)                        |
| 1   | Ternary search                                   | Θ(log₃ n)                      | Θ(1)                        |
| 2   | Defective coin — divide and conquer              | Θ(log n) weighings              | Θ(log n) recursion depth    |
| 3   | Max-Min — divide and conquer                     | Θ(n)                            | Θ(log n) recursion depth    |
| 4   | Strassen's matrix multiplication                 | O(n^log₂7) ≈ O(n^2.807)         | Θ(n²) auxiliary             |
| 4   | Brute-force matrix multiplication                | Θ(n³)                           | Θ(1) auxiliary              |
| 5   | Special-pattern matrix multiplication            | Depends on the recursive representation | Depends on representation |
| 6   | Sorting with loop invariant                      | Depends on the sorting algorithm | Depends on implementation |

---

## Topics Covered

**Analysis**

- [x] Asymptotic notation — Θ, O, Ω
- [x] Ordering functions by rate of growth
- [x] Polynomial vs superpolynomial vs exponential growth
- [x] Best case vs worst case
- [x] Counting primitive operations as a machine-independent cost model

**Algorithms**

- [x] Sorting and performance analysis
- [x] Bubble sort
- [x] Linear search / partition point
- [x] Binary search
- [x] Ternary search
- [x] Recursion (Towers of Hanoi)
- [x] Merge sort
- [x] k-way merging
- [x] Divide and conquer
- [x] Strassen's matrix multiplication

**Recurrences and Randomisation**

- [x] Solving and analysing recursive algorithms
- [x] Verifying theoretical growth against experimental data
- [x] Coin-toss simulation
- [x] Master theorem and divide-and-conquer recurrences

**Data Structures (LAB_2)**

- [x] Dictionary operations
- [x] Arrays and linked representations
- [x] Cost trade-offs between different representations

**Divide and Conquer (LAB_3)**

- [x] Binary vs ternary search
- [x] Defective-coin problem
- [x] Simultaneous maximum and minimum
- [x] Strassen's matrix multiplication
- [x] Special-pattern matrix multiplication
- [x] Loop invariants — initialization, maintenance, termination

---

## Technologies Used

| Tool                         | Purpose                                   |
| ---------------------------- | ----------------------------------------- |
| C (C99 / C11)                | Implementation language                   |
| GCC                          | Compilation                               |
| C standard library           | `stdio.h`, `stdlib.h`, `math.h`, `time.h` |
| Gnuplot                      | Generating plots from experimental data   |
| `.dat` files                 | Exporting measurements for plotting        |
| VS Code / Windows            | Editor and development environment        |
| Git and GitHub               | Version control                           |

---

## Compilation and Execution

Each question lives in its own folder, so `cd` into it before compiling:

### LAB_1

```bash
cd 'LAB_1/1. Put them in Order'
gcc -O2 -o Q1 growth.c -lm && ./Q1

cd '../2. Fair vs Biased coin'
gcc -o Q2 coin.c && ./Q2

cd '../3. Performance analysis of bubble sort'
gcc -o Q3 bubble.c && ./Q3

cd '../4. Towers of Hanoi'
gcc -o Q4 TOH.c && ./Q4

cd '../5. Find the partition point'
gcc -o Q5 partition.c && ./Q5

cd '../6. Element uniqueness'
gcc -O2 -o Q6 unique.c && ./Q6
```

### LAB_2

```bash
cd 'LAB_2/1. Dictionary Operations'
gcc -O2 -o Q1 dictionary_growth.c && ./Q1

cd '../2. Merge sort vs Modified merge sort'
gcc -O2 -o Q2 merge_sort.c && ./Q2

cd '../3. Merging k sorted arrays'
gcc -O2 -o Q3 merging_k_arrays.c && ./Q3
```

### LAB_3

```bash
cd 'LAB_3/1. Binary vs Ternary Search'
gcc -O2 -o Q1 BTsearch.c && ./Q1

cd '../2. Search the Defective Coin'
gcc -O2 -o Q2 Dcoin.c -lm && ./Q2

cd '../3. Max and Min using D&C Approach'
gcc -O2 -o Q3 minmax.c && ./Q3

cd '../4. Matrix Multiplication using D&C Approach'
gcc -O2 -o Q4 strassen.c && ./Q4

cd '../5. Multiply special-pattern square matrices using D&C approach'
gcc -O2 -o Q5 specialmat.c && ./Q5

cd '../6. Use of loop invariants in sorting'
gcc -O2 -o Q6 loopsorting.c && ./Q6
```

Recommended flags while working:

```bash
gcc -std=c11 -Wall -Wextra -O2 file.c -o out -lm
```

**On Windows** (MinGW-w64), replace `-o Q1` with `-o Q1.exe` and run `Q1.exe`.

**Note on generated files.** Q1, Q3, and Q4 in LAB_1 write their experimental data into the current working directory under fixed names (`growth.dat`, `bubble.dat`, and `toh.dat`). Running them from inside their own question folder will overwrite the committed copies there.

To regenerate a plot after re-running a program, run the corresponding `.gnu` script from that question folder with Gnuplot. For example:

```bash
gnuplot plot.gnu
```

---

## Repository Conventions

- One top-level folder per lab, named `LAB_1`, `LAB_2`, and `LAB_3`, containing one subfolder per question.
- One subfolder per question, named after the question itself, holding that question's `.c` file plus anything it generates (DAT data, PNG plots, and Gnuplot scripts where applicable).
- Sources are named according to the problem, such as `growth.c`, `merge_sort.c`, `BTsearch.c`, and `loopsorting.c`.
- Generated data files keep the name of the analysis they describe, and their plots are stored alongside them.

---

## License

Coursework, published for reference and learning. Feel free to read, run and learn from it; please do not submit it as your own.

---

<p align="center">
  Maintained by <strong>Anurag Samal</strong> · CE, IIIT Bhubaneswar
</p>

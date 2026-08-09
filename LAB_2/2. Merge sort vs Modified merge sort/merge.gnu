set title "Merge Sort vs Modified 3-Way Merge Sort"

set xlabel "Input Size (n)"
set ylabel "Execution Time (seconds)"

set grid
set key top left
set border linewidth 1.5

# Complexity annotations
# Merge Sort Label (Top Left)
set label 1 "Merge Sort\nT(n)=2T(n/2)+O(n)\nTime Complexity: O(n log_2 n)" \
at graph 0.27,0.75

# Modified Merge Sort Label (Top Right)
set label 2 "Modified 3-Way Merge Sort\nT(n)=3T(n/3)+O(n)\nTime Complexity: O(n log_3 n)" \
at graph 0.60,0.85

# Overall Complexity Note (Bottom Center)
set label 3 "Both algorithms have the same asymptotic complexity: O(n log n)" \
at graph 0.18,0.05 boxed

plot \
    "merge.dat" using 1:2 with linespoints lw 3 pt 7 title "Merge Sort", \
    "merge.dat" using 1:3 with linespoints lw 3 pt 5 title "Modified 3-Way Merge Sort"
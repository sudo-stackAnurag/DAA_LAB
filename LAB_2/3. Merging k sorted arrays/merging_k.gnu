set title "Merging k Sorted Arrays: Method 1 vs Method 2"
set xlabel "Number of Sorted Arrays (k)"
set ylabel "Execution Time (seconds)"

set grid
set key top left

set label 1 "Method 1: O(nk²)" at graph 0.05,0.90
set label 2 "Method 2: O(nk log₂k)" at graph 0.05,0.84
set label 3 "n = 10000 elements per array" at graph 0.05,0.78

plot \
"merging_k.dat" using 1:2 with linespoints lw 2 pt 7 title "Method 1", \
"merging_k.dat" using 1:3 with linespoints lw 2 pt 5 title "Method 2"
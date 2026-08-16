set title "Binary Search vs Ternary Search"
set xlabel "Number of Elements (n)"
set ylabel "Number of Comparisons"
set grid
set key left top

plot "search_data.dat" using 1:2 with linespoints title "Binary Search O(log2 n)", \
     "search_data.dat" using 1:3 with linespoints title "Ternary Search O(log3 n)"
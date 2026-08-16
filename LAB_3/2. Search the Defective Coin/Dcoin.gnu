set title "Defective Coin Search - Time Complexity"

set xlabel "Number of Coins (n)"
set ylabel "Number of Balance-Scale Weighings"

set grid
set key left top

set logscale x 2

plot "data.dat" using 1:2 with linespoints linewidth 2 \
     title "Actual Weighings", \
     "data.dat" using 1:(log($1)/log(2)) with lines linewidth 2 \
     title "Theoretical O(log2 n)"
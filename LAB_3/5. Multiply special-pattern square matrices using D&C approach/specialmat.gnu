set title "Special Pattern Matrix Multiplication - O(n^2)"

set xlabel "Matrix Size (n)"
set ylabel "Computational Work"

set grid
set key left top

set logscale x 2
set logscale y 2

plot "data.dat" using 1:2 with linespoints linewidth 2 \
    title "Experimental/Theoretical O(n^2)", \
    x*x with lines linewidth 2 \
    title "Reference n^2"
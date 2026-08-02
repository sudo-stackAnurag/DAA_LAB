set terminal png size 800,600
set output "plot.png"

set title "Growth Rate Comparison"

set xlabel "n"

set ylabel "f(n)"

set logscale y


plot "growth.dat" using 1:2 with lines title "1/n",\
"growth.dat" using 1:3 with lines title "12sqrt(n)",\
"growth.dat" using 1:4 with lines title "50sqrt(n)",\
"growth.dat" using 1:5 with lines title "n^0.51",\
"growth.dat" using 1:6 with lines title "n",\
"growth.dat" using 1:7 with lines title "2^32*n",\
"growth.dat" using 1:8 with lines title "nlogn",\
"growth.dat" using 1:9 with lines title "100n^2+6n",\
"growth.dat" using 1:10 with lines title "n^2-324",\
"growth.dat" using 1:11 with lines title "2n^3",\
"growth.dat" using 1:12 with lines title "n^(log2n)",\
"growth.dat" using 1:13 with lines title "3^n"
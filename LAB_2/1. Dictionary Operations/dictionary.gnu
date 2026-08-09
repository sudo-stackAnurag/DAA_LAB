set title "Worst-Case Growth of Dictionary Operations\n(Y-axis uses Logarithmic Scale)"
set xlabel "Input Size (n)"
set ylabel "Complexity (Log Scale)"

set grid
set border linewidth 1.5
set key top left

# Logarithmic Y-axis
set logscale y

# Optional: show log-scale ticks
set format y "10^{%L}"

# Annotation explaining the graph
set label 1 "Note: Logarithmic Y-axis is used\nso O(1), O(log n), and O(n)\ncan be visualized together." \
at graph 0.55,0.15 boxed

# Complexity labels
set label 2 "O(1)\n(Max, Min,\nPred, Succ)" at 700,1.2
set label 3 "O(log n)\n(Search\nin Sorted Array)" at 700,8
set label 4 "O(n)\n(Search,\nInsert,\nDelete,\nUnsorted Ops)" at 700,250

plot \
    "dictionary.dat" using 1:2 with lines linewidth 3 title "O(1)", \
    "dictionary.dat" using 1:3 with lines linewidth 3 title "O(log n)", \
    "dictionary.dat" using 1:4 with lines linewidth 3 title "O(n)"
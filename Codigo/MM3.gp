set term pdf
set out 'mult-MFLOPS_vs_NB-O3.pdf'
set logscale y
set xlabel "Tamaño del bloque"
set ylabel "MFLOPS"
set title "MFLOPS vs Tamaño matriz"
plot "../Resultados/multiplicacion_blocking_O3.txt" u 1:3 w linespoints t "Blocking", "../Resultados/multiplicacion_eigen_O3.txt" u 1:3 w linespoints t "Eigen", "../Resultados/multiplicacion_armadillo_O3.txt" u 1:3 w linespoints t "Armadillo"

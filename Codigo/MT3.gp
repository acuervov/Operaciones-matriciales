set term pdf
set out 'mult-TIME_vs_NB-O3.pdf'
set logscale y
set xlabel "Tamaño del bloque"
set ylabel "Tiempo CPU"
set title "Tiempo CPU vs Tamaño matriz"
plot "../Resultados/multiplicacion_blocking_O3.txt" u 1:2 w linespoints t "Blocking", "../Resultados/multiplicacion_eigen_O3.txt" u 1:2 w linespoints t "Eigen", "../Resultados/multiplicacion_armadillo_O3.txt" u 1:2 w linespoints t "Armadillo"

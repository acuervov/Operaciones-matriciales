set term pdf
set out 'trans-TIME_vs_NB-O3.pdf'
set logscale y
set xlabel "Tamaño del bloque"
set ylabel "Tiempo CPU"
set title "Tiempo de CPU vs Tamaño matriz"
plot "../Resultados/transpuesta_blocking_O3.txt" u 1:2 w linespoints t "Blocking", "../Resultados/transpuesta_eigen_O3.txt" u 1:2 w linespoints t "Eigen", "../Resultados/transpuesta_armadillo_O3.txt" u 1:2 w linespoints t "Armadillo"

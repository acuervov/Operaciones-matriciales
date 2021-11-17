set term pdf
set out 'mult-TIME_vs_NB-O0.pdf'
set logscale y
set xlabel "Tamaño del bloque"
set ylabel "Tiempo CPU"
set title "Tiempo CPU vs Tamaño matriz"
plot "../Resultados/multiplicacion_blocking.txt" u 1:2 w linespoints t "Blocking", "../Resultados/multiplicacion_eigen.txt" u 1:2 w linespoints t "Eigen", "../Resultados/multiplicacion_armadillo.txt" u 1:2 w linespoints t "Armadillo"


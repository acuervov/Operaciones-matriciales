set term pdf
set out 'trans-MFLOPS_vs_NB-O0.pdf'
set logscale y
set xlabel "Tamaño del bloque"
set ylabel "MFLOPS"
set title "MFLOPS vs Tamaño matriz"
plot "../Resultados/transpuesta_blocking.txt" u 1:3 w linespoints t "Blocking", "../Resultados/transpuesta_eigen.txt" u 1:3 w linespoints t "Eigen", "../Resultados/transpuesta_armadillo.txt" u 1:3 w linespoints t "Armadillo"

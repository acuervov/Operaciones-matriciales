set term pdf
set out 'trans-MFLOPS_vs_NB-O3.pdf'
set logscale y
set xlabel "Tamaño del matriz"
set ylabel "MFLOPS"
set title "MFLOPS vs Tamaño matriz"
plot "../Resultados/transpuesta_blocking_O3.txt" u 1:3 w linespoints t "Blocking", "../Resultados/transpuesta_eigen_O3.txt" u 1:3 w linespoints t "Eigen", "../Resultados/transpuesta_armadillo_O3.txt" u 1:3 w linespoints t "Armadillo"

set term pdf
set out 'Bloque_optimo.pdf'
set xlabel "Tamaño del bloque"
set ylabel "Tiempo"
set logscale y
set title "Time vs Tamaño del bloque"
plot "../Resultados/Bloque_optimo_T.txt" u 1:2 w linespoints t "Transpuesta", "../Resultados/Bloque_optimo_M.txt" u 1:2 w linespoints t "Multiplicación"
set ylabel "MFLOPS"
set title "MFLOPS vs Tamaño del bloque"
plot "../Resultados/Bloque_optimo_T.txt" u 1:3 w linespoints t "Transpuesta", "../Resultados/Bloque_optimo_M.txt" u 1:3 w linespoints t "Multiplicación"


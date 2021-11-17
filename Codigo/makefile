
transpuesta_blocking_performance_block.x:transpuesta_blocking_performance_block.cpp
	g++ -o0 transpuesta_blocking_performance_block.cpp -lpapi -o transpuesta_blocking_performance_block.x

Bloque_optimo_T.txt:transpuesta_blocking_performance_block.x
	./transpuesta_blocking_performance_block.x 2048 > ../Resultados/Bloque_optimo_T.txt
	rm transpuesta_blocking_performance_block.x

multiplicacion_blocking_performance_block.x:multiplicacion_blocking_performance_block.cpp
	g++ -o0  multiplicacion_blocking_performance_block.cpp -lpapi -o multiplicacion_blocking_performance_block.x

Bloque_optimo_M.txt:multiplicacion_blocking_performance_block.x
	./multiplicacion_blocking_performance_block.x 2048 > ../Resultados/Bloque_optimo_M.txt
	rm multiplicacion_blocking_performance_block.x



multiplicacion_blocking.x:multiplicacion_blocking.cpp
	g++ -o0 multiplicacion_blocking.cpp  -lpapi -o multiplicacion_blocking.x

multiplicacion_eigen.x:multiplicacion_eigen.cpp
	g++ -o0 multiplicacion_eigen.cpp -lpapi -o multiplicacion_eigen.x

multiplicacion_armadillo.x:multiplicacion_armadillo.cpp
	g++ -o0 multiplicacion_armadillo.cpp -lpapi -larmadillo  -o multiplicacion_armadillo.x

multiplicacion_blocking.txt:multiplicacion_blocking.x
	./multiplicacion_blocking.x 8192 > ../Resultados/multiplicacion_blocking.txt
	rm multiplicacion_blocking.x
multiplicacion_eigen.txt:multiplicacion_eigen.x
	./multiplicacion_eigen.x 8192 > ../Resultados/multiplicacion_eigen.txt
		rm multiplicacion_eigen.x
multiplicacion_armadillo.txt:multiplicacion_armadillo.x
	./multiplicacion_armadillo.x 8192 > ../Resultados/multiplicacion_armadillo.txt
		rm multiplicacion_armadillo.x



multiplicacion_blocking_O3.x:multiplicacion_blocking.cpp
	g++ -o3 multiplicacion_blocking.cpp  -lpapi -o multiplicacion_blocking_O3.x

multiplicacion_eigen_O3.x:multiplicacion_eigen.cpp
	g++ -o3 multiplicacion_eigen.cpp -lpapi -o multiplicacion_eigen_O3.x

multiplicacion_armadillo_O3.x:multiplicacion_armadillo.cpp
	g++ -o3 multiplicacion_armadillo.cpp  -lpapi -larmadillo -o multiplicacion_armadillo_O3.x

multiplicacion_blocking_O3.txt:multiplicacion_blocking_O3.x
	./multiplicacion_blocking_O3.x 8192 > ../Resultados/multiplicacion_blocking_O3.txt
	rm multiplicacion_blocking_O3.x

multiplicacion_eigen_O3.txt:multiplicacion_eigen_O3.x
	./multiplicacion_eigen_O3.x 8192 > ../Resultados/multiplicacion_eigen_O3.txt
	rm multiplicacion_eigen_O3.x

multiplicacion_armadillo_O3.txt:multiplicacion_armadillo_O3.x
	./multiplicacion_armadillo_O3.x 8192 > ../Resultados/multiplicacion_armadillo_O3.txt
	rm multiplicacion_armadillo_O3.x



transpuesta_blocking.x:transpuesta_blocking.cpp
	g++ -o0 transpuesta_blocking.cpp  -lpapi -o transpuesta_blocking.x

transpuesta_eigen.x:transpuesta_eigen.cpp
	g++ -o0 transpuesta_eigen.cpp -lpapi -o transpuesta_eigen.x

transpuesta_armadillo.x:transpuesta_armadillo.cpp
	g++ -o0 transpuesta_armadillo.cpp -lpapi -larmadillo -o transpuesta_armadillo.x

transpuesta_blocking.txt:transpuesta_blocking.x
	./transpuesta_blocking.x 8192 > ../Resultados/transpuesta_blocking.txt
	rm transpuesta_blocking.x

transpuesta_eigen.txt:transpuesta_eigen.x
	./transpuesta_eigen.x 8192 > ../Resultados/transpuesta_eigen.txt
	rm transpuesta_eigen.x

transpuesta_armadillo.txt:transpuesta_armadillo.x
	./transpuesta_armadillo.x 8192 > ../Resultados/transpuesta_armadillo.txt
	rm transpuesta_armadillo.x


transpuesta_blocking_O3.x:transpuesta_blocking.cpp
	g++ -o3 transpuesta_blocking.cpp  -lpapi -o transpuesta_blocking_O3.x

transpuesta_eigen_O3.x:transpuesta_eigen.cpp
	g++ -o3 transpuesta_eigen.cpp -lpapi -o transpuesta_eigen_O3.x

transpuesta_armadillo_O3.x:transpuesta_armadillo.cpp
	g++ -o3 transpuesta_armadillo.cpp -lpapi -larmadillo -o transpuesta_armadillo_O3.x

transpuesta_blocking_O3.txt:transpuesta_blocking_O3.x
	./transpuesta_blocking_O3.x 8192 > ../Resultados/transpuesta_blocking_O3.txt
	rm transpuesta_blocking_O3.x

transpuesta_eigen_O3.txt:transpuesta_eigen_O3.x
	./transpuesta_eigen_O3.x 8192 > ../Resultados/transpuesta_eigen_O3.txt
	rm transpuesta_eigen_O3.x

transpuesta_armadillo_O3.txt:transpuesta_armadillo_O3.x
	./transpuesta_armadillo_O3.x 8192 > ../Resultados/transpuesta_armadillo_O3.txt
	rm transpuesta_armadillo_O3.x

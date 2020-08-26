adminLibro: main.cpp funciones.hpp.gch
	g++ main.cpp -o adminLibro
funciones.hpp.gch: funciones.hpp
	g++ funciones.hpp
clean:
	rm *.gch
	rm adminLibro
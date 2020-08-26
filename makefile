#Makefile para adminLibro
adminLibro: main.cpp funciones.hpp.gch
	g++ main.cpp -o adminLibro
funciones.hpp.gch: funciones.hpp lista.hpp.gch
	g++ funciones.hpp
lista.hpp.gch: lista.hpp libro.hpp.gch
	g++ lista.hpp
libro.hpp.gch: libro.hpp
	g++ libro.hpp
#Borra todos los archivos que se generaron arriba
clean:
	rm *.gch
	rm adminLibro
#Instala el programa
install:
	cp adminLibro /bin/adminLibro
	touch /var/db/LIBROS.db
uninstall:
	rm /bin/adminLibro
	rm /var/db/LIBROS.db
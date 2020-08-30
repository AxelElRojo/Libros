adminLibro: main.cpp funciones.hpp lista.hpp libro.hpp
	g++ main.cpp -o adminLibro
clean:
	rm adminLibro
install:
	cp adminLibro /bin/adminLibro
	touch /var/db/LIBROS.db
uninstall:
	rm /bin/adminLibro
	rm /var/db/LIBROS.db
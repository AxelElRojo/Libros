adminLibro: main.cpp funciones.hpp lista.hpp libro.hpp
	g++ main.cpp -o adminLibro
clean:
	rm adminLibro
install:
	cp adminLibro /bin/adminLibro
	touch ~/.local/share/LIBROS.db
	cp adminLibro.7 /usr/local/man/man1/adminLibro.1
	gzip /usr/local/man/man1/adminLibro.1
uninstall:
	rm /bin/adminLibro ~/.local/share/LIBROS.db /usr/local/man/man1/adminLibro.1
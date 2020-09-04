adminLibro: main.cpp funciones.hpp lista.hpp libro.hpp
	g++ main.cpp -o adminLibro
clean:
	rm adminLibro
install:
	cp adminLibro /bin/adminLibro
	touch ~/.local/share/LIBROS.db
	cp adminLibro /usr/local/man/man1/adminLibro.1
	gzip /usr/local/man/man1/adminLibro.1
uninstall:
	rm /bin/adminLibro /var/db/LIBROS.db
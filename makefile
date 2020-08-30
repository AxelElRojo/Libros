adminLibro: main.cpp funciones.hpp lista.hpp libro.hpp
	g++ main.cpp -o adminLibro
clean:
	rm adminLibro
install:
	cp adminLibro /bin/adminLibro
	touch /var/db/LIBROS.db
	cp adminLibro /usr/local/man/man8/adminLibro.7
	gzip /usr/local/man/man8/adminLibro.7
uninstall:
	rm /bin/adminLibro /var/db/LIBROS.db
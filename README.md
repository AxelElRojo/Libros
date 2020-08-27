# Alch este programa no tiene nombre, el repo se llama "Libros" porque es lo que administra
Un programa para guardar datos de libros en una librería/biblioteca. Usa una lista simple para guardar los libros, todo con stdin y stdout, está pensado para principalmente usarse desde SSH.

Creo que ya se puede utilizar, está implementado todo el programa, pero no lo he utilizado, por lo que podría haber bugs, además no existe una página del manual, pero el programa debería ser instalable y también se deberían poder consultar los libros.

El programa cuenta con 3 posibles flags, -a, -t y -h, que permiten buscar rápidamente por autor y título del libro, obviamente se tiene que especificar el dato a buscar (no se usan expresiones regulares, se tiene que indicar el nombre exactamente), el tercer flag imprime una pequeña pantalla de ayuda, está pensada para ser una guía rápida, sólo explica las flags y cómo entrar al menú.

Si el programa se ejecuta sin usar flags, se abre el menú principal. Desde el que se puede dar de alta, de baja y buscar libros (por autor, título y año). Si se utilizan las opciones para dar de alta o de baja, hay que guardar los cambios, para ello se utiliza la opción "guardar y salir".

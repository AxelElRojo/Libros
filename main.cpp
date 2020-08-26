#include "funciones.hpp"
int main(){
    int opc;
    cLista libros;
    libros.cargar();
    do{
        opc = menu();
        switch(opc){
            case ALTA:
                menuAlta(libros);
            break;
            case BUSQUEDA:
                menuBusqueda(libros);
            break;
            case BAJA:
            break;
            case SALIR:
                libros.guardar();
            break;
            default:
                std::cout << "Ingrese una opción válida!\n";
        }
    pausa();
    }while(opc!=SALIR);
}
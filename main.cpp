#include "funciones.hpp"
#include <cstring>
int main(int argc, char* argv[]){
    cLista libros;
    if(argc > 1){
        std::vector<cLibro>resultados;
        if(argv[1][0] == '-')
            switch (argv[1][1]){
                case 'a':
                    carga(libros);
                    libros.buscarAutor(resultados, argv[2]);
                    mostrarResultados(resultados);
                break;
                case 't':
                    carga(libros);
                    libros.buscarTitulo(resultados, argv[2]);
                    mostrarResultados(resultados);
                break;
                case 'h':
                cout << "AYUDA:\n\t-a Búsqueda por autor\n\t-t Búsqueda por título\n\t-h Esta pantalla\n"
                << "Si el programa se corre sin flags, se abre el menú principal.\n"
                << "En donde se puede dar de alta, baja y buscar por año.\n";
                break;
                default:
                cout << argv[1] << " es un flag inválido!\nPrueba -h o RTFM\n";
            }
        else if(!std::strcmp(argv[1],"RTFM"))
            std::system("man adminLibro");
        else
            cout << "Opción inválida!\nPrueba -h o RTFM\n";
    }else{
        short opc;
        carga(libros);
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
                    menuBaja(libros);
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
}
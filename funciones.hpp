#pragma once
#include <cctype>
#include <cstdlib>
#include <vector>
#include "lista.hpp"
using std::cin;
using std::cout;
enum OPCIONES{ALTA=1,BUSQUEDA,BAJA,SALIR};
enum BUSQUEDA{TITULO=1,AUTOR,ANIO,TODO};
void pausa(){
    cout << "\nPresione enter para continuar...";
    cin.ignore();
    while(cin.get()!='\n');
    std::system("clear");
}
void carga(cLista& libros){
    if(!libros.cargar()){
        cout << "ADVERTENCIA: No se pudo encontrar el archivo de base de datos\n";
        pausa();
    }
}
bool leerSN(){
    char letra;
    do{
        cin >> letra;
    }while(!cin.fail() && letra!='s' && letra!='n');
    return letra == 's';
}
void mostrarResultados(const std::vector<cLibro>&resultados){
    short tamResultados = resultados.size();
    cout << "Hubo un total de " << tamResultados << " resultados, ¿Desea verlos? (s/n): ";
    if(leerSN()){
        cout << "\tAño\tEdición\tAutor\tNombre\n";
        for(short i(0);i<tamResultados;++i)
            cout << i+1 << ":\t" << resultados[i].mostrarDatos() << '\n';
    }else
        cout << "No se mostraron los resultados\n";
}
short menu(){
    short opc;
    std::system("clear");
    cout << "\t\tAdministrador de Libros\n1- Alta\n2- Búsqueda\n3- Baja\n4- Guardar y salir\nIngrese una opción: ";
    cin >> opc;
    return opc;
}
void menuAlta(cLista& lista){
    std::string nombre, autor;
    short anio, edicion;
    std::system("clear");
    cout << "Ingrese los siguientes datos:\nNombre del libro: ";
    cin.ignore();
    std::getline(cin,nombre);
    cout << "Nombre del autor: ";
    cin.ignore();
    std::getline(cin,autor);
    cout << "Edición: ";
    cin >> edicion;
    cout << "Año: ";
    cin >> anio;
    cLibro libro(nombre,autor,anio,edicion);
    lista.insertar(libro);
}
void menuBusqueda(cLista& libros){
    short opc, anio;
    string criterio;
    std::vector<cLibro>resultados;
    std::system("clear");
    cout << "1- Búsqueda por título\n2- Búsqueda por Autor\n3- Buscar por año\nIngrese una opción: ";
    cin >> opc;
    switch(opc){
        case TITULO:
            cout << "Ingrese el título del libro: ";
            cin.ignore();
            std::getline(cin,criterio);
            libros.buscarTitulo(resultados,criterio);
        break;
        case AUTOR:
            cout << "Ingrese el autor del libro: ";
            cin.ignore();
            std::getline(cin,criterio);
            libros.buscarTitulo(resultados,criterio);
        break;
        case ANIO:
            cout << "Ingrese el año del libro: ";
            cin >> anio;
            libros.buscarAnio(resultados,anio);
        break;
        case TODO:
            std::system("clear");
            cout << libros.listar();
            return;
        break;
        default:
            cout << "Ingrese una opción válida!\n";
    }
    mostrarResultados(resultados);
}
void menuBaja(cLista& libros){
    string nombre;
    cout << "Introduzca el nombre del libro para dar de baja: ";
    cin.ignore();
    std::getline(cin, nombre);
    cout << "¿Está seguro de querer eliminar el libro? (s/n): ";
    if(leerSN())
        if(libros.eliminar(nombre))
            cout << "Libro eliminado correctamente\n";
        else
            cout << "No se encontró el libro\n";
    else
        cout << "No se eliminó nada\n";
}
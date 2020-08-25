#pragma once
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "lista.hpp"
using std::cin;
using std::cout;
enum OPCIONES{ALTA=1,BUSQUEDA,BAJA,SALIR};
enum BUSQUEDA{TITULO=1,AUTOR,ANIO};
bool leerSN(){
    char letra;
    do{
        letra = toupper(cin.get());
    }while(letra != 'S' || letra != 'N');
    return letra == 'S';
}
int menu(){
    int opc;
    std::system("clear");
    cout << "1- Alta\n2- Búsqueda\n3- Baja\n4- Salir\nIngrese una opción: ";
    cin >> opc;
    return opc;
}
void menuAlta(cLista& lista){
    std::string nombre, autor;
    int anio, edicion;
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
    int opc;
    std::vector<cLibro>resultados;
    std::system("clear");
    cout << "1- Búsqueda por título\n2- Búsqueda por Autor\n3- Buscar por año\nIngrese una opción: ";
    cin >> opc;
    switch (opc){
        case TITULO:
        break;
        case AUTOR:
        break;
        case ANIO:
        break;
        default:
            cout << "Ingrese una opción válida!\n";
    }
    cout << "Hubo un total de " << resultados.size() << " resultados, ¿Desea verlos? (S/N)";
    if(leerSN())
        for(int i(0);i<resultados.size();++i)
            cout << '\t' << i+1 << ":\n" << resultados[i] << '\n';
    else
        cout << "No se mostraron los resultados\n";

}
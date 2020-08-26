#pragma once
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>
#include "lista.hpp"
using std::cin;
using std::cout;
enum OPCIONES{ALTA=1,BUSQUEDA,BAJA,SALIR};
enum BUSQUEDA{TITULO=1,AUTOR,ANIO};
void pausa(){
    cout << "Presione enter para continuar...";
    cin.ignore();
    while(cin.get()!='\n');
    std::system("clear");
}
bool leerSN(){
    char letra;
    do{
        letra = toupper(cin.get());
    }while(letra != 'S' || letra != 'N');
    return letra == 'S';
}
short menu(){
    short opc;
    std::system("clear");
    cout << "1- Alta\n2- Búsqueda\n3- Baja\n4- Salir\nIngrese una opción: ";
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
        default:
            cout << "Ingrese una opción válida!\n";
    }
    cout << "Hubo un total de " << resultados.size() << " resultados, ¿Desea verlos? (S/N)";
    if(leerSN())
        for(short i(0);i<resultados.size();++i)
            cout << '\t' << i+1 << ":\n" << resultados[i] << '\n';
    else
        cout << "No se mostraron los resultados\n";
}
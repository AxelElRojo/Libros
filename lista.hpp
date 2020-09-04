#pragma once
#include <fstream>
#include <vector>
#include "libro.hpp"
class cNodo{
    cLibro lDato;
    cNodo* siguiente;
    friend class cLista;
    cNodo(const cLibro& libro):lDato(libro),siguiente(nullptr){}
    cNodo():siguiente(nullptr){}
    ~cNodo(){delete siguiente;}
    void insertarAdelante(const cLibro& libro);
    void eliminarAdelante();
};
void cNodo::insertarAdelante(const cLibro& libro){
    if(siguiente != nullptr)
        siguiente->insertarAdelante(libro);
    else
        siguiente = new cNodo(libro);
}
void cNodo::eliminarAdelante(){
    cNodo* adelante = siguiente->siguiente;
    delete siguiente;
    siguiente = adelante;
}
class cLista{
    cNodo* cabeza;
    cLibro eliminarInicio(){
        cLibro lRetorno = cabeza->lDato;
        cNodo* nuevaCabeza = cabeza->siguiente;
        delete cabeza;
        cabeza = nuevaCabeza;
        return lRetorno;
    }
    public:
    cLista():cabeza(nullptr){}
    ~cLista(){delete cabeza;}
    int tamano() const;
    void insertar(const cLibro& libro);
    bool estaVacia() const;
    bool cargar();
    bool guardar();
    void buscarTitulo(std::vector<cLibro>&resultados,const string& titulo) const;
    void buscarAutor(std::vector<cLibro>&resultados,const string& autor) const;
    void buscarAnio(std::vector<cLibro>&resultados,const short& anio) const;
    bool eliminar(const string& titulo);
};
int cLista::tamano() const{
    int i;
    for(cNodo* pIt=cabeza;pIt;++i,pIt=pIt->siguiente);
    return i;
}
void cLista::insertar(const cLibro& libro){
        if(cabeza != nullptr)
            cabeza->insertarAdelante(libro);
        else
            cabeza = new cNodo(libro);
    }
bool cLista::estaVacia() const{
    return cabeza == nullptr;
}
bool cLista::cargar(){
    std::ifstream fin("~/.local/share/LIBROS.db");
    if(fin.is_open()){
        while(!fin.eof()){
            cLibro libro;
            fin >> libro;
            insertar(libro);
        }
        fin.close();
        return true;
    }else
        return false;
}
bool cLista::guardar(){
    std::ofstream fout("~/.local/share/LIBROS.db");
    if(fout.is_open()){
        while(!estaVacia())
            fout << eliminarInicio();
        fout.close();
        return true;
    }else
        return false;
}
void cLista::buscarTitulo(std::vector<cLibro>&resultados,const string& titulo) const{
    cNodo* pIt = cabeza;
    while (pIt != nullptr){
        if(pIt->lDato.mostrarNombre() == titulo)
            resultados.push_back(pIt->lDato);
        pIt = pIt->siguiente;
    }
}
void cLista::buscarAutor(std::vector<cLibro>&resultados,const string& autor) const{
    cNodo* pIt = cabeza;
    while (pIt != nullptr){
        if(pIt->lDato.mostrarAutor() == autor)
            resultados.push_back(pIt->lDato);
        pIt = pIt->siguiente;
    }
}
void cLista::buscarAnio(std::vector<cLibro>&resultados,const short& anio) const{
    cNodo* pIt = cabeza;
    while (pIt != nullptr){
        if(pIt->lDato.mostrarAnio() == anio)
            resultados.push_back(pIt->lDato);
        pIt = pIt->siguiente;
    }
}
bool cLista::eliminar(const string& titulo){
    cNodo* pIt = cabeza;
    while(pIt != nullptr)
        if(pIt->siguiente && pIt->siguiente->lDato.mostrarNombre() == titulo){
            pIt->eliminarAdelante();
            return true;
        }else
            pIt = pIt->siguiente;
    return false;
}
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
    void insertarAdelante(const cLibro& libro){
        if(siguiente != nullptr)
            siguiente->insertarAdelante(libro);
        else
            siguiente = new cNodo(libro);
    }
    void eliminarAdelante(){
        cNodo* adelante = siguiente->siguiente;
        delete siguiente;
        siguiente = adelante;
    }
};
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
    cLista(const cLibro& libro):cabeza(new cNodo(libro)){}
    cLista():cabeza(nullptr){}
    ~cLista(){
        delete cabeza;
    }
    void insertar(const cLibro& libro){
        if(cabeza != nullptr)
            cabeza->insertarAdelante(libro);
        else
            cabeza = new cNodo(libro);
    }
    bool estaVacia() const{
        return cabeza == nullptr;
    }
    bool cargar(){
        std::ifstream fin("LIBROS.db");
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
    bool guardar(){
        std::ofstream fout("LIBROS.db");
        if(fout.is_open()){
            while(!estaVacia()){
                fout << eliminarInicio();
            }
            fout.close();
            return true;
        }else
            return false;
    }
    void buscarTitulo(std::vector<cLibro>&resultados,const string& titulo) const{
        cNodo* pIt = cabeza;
        while (pIt != nullptr){
            if(pIt->lDato.mostrarNombre() == titulo)
                resultados.push_back(pIt->lDato);
            pIt = pIt->siguiente;
        }
    }
    void buscarAutor(std::vector<cLibro>&resultados,const string& autor) const{
        cNodo* pIt = cabeza;
        while (pIt != nullptr){
            if(pIt->lDato.mostrarAutor() == autor)
                resultados.push_back(pIt->lDato);
            pIt = pIt->siguiente;
        }
    }
    void buscarAnio(std::vector<cLibro>&resultados,const short& anio) const{
        cNodo* pIt = cabeza;
        while (pIt != nullptr){
            if(pIt->lDato.mostrarAnio() == anio)
                resultados.push_back(pIt->lDato);
            pIt = pIt->siguiente;
        }
    }
};
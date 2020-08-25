#pragma once
#include <iostream>
#include <sstream>
using std::string;
class cLibro{
    string nombre, autor;
    int anio, edicion;
    friend class cNodo;
public:
    cLibro(string nombre, string autor, int anio, int edicion){
        ponerDatos(nombre, autor, anio, edicion);
    }
    cLibro():edicion(-1){}
    void ponerDatos(string nombre, string autor, int anio, int edicion){
        this->nombre = nombre;
        this->autor = autor;
        this->anio = anio;
        this->edicion = edicion;
    }
    string mostrarDatos() const{
        std::stringstream ss;
        ss << "Nombre: " << this->nombre << "\nAutor: " << this->autor << '\n'
           << "Año: " << this->anio << "\nEdición: " << this->edicion << '\n';
        return ss.str();
    }
    friend std::ostream& operator << (std::ostream& out, const cLibro& libro){
        out << libro.anio << ' ' << libro.edicion << ' ' << libro.nombre << '|' << libro.autor << '\n';
        return out;
    }
    friend std::istream& operator >> (std::istream& in, cLibro& libro){
        in >> libro.anio >> libro.edicion;
        in.ignore();
        std::getline(in,libro.nombre,'|');
        in.ignore();
        std::getline(in,libro.autor);
        return in;
    }
    bool operator == (const string& nombre) const{
        return this->nombre == nombre;
    }
    bool operator != (const string& nombre) const{
        return this->nombre != nombre;
    }
};
#pragma once
#include <iostream>
#include <sstream>
using std::string;
class cLibro{
    string nombre, autor;
    short anio, edicion;
    friend class cNodo;
public:
    cLibro(string nombre, string autor, short anio, short edicion){
        ponerDatos(nombre, autor, anio, edicion);
    }
    cLibro():edicion(-1){}
    void ponerDatos(string nombre, string autor, short anio, short edicion);
    string mostrarNombre() const;
    string mostrarAutor() const;
    short mostrarAnio() const;
    string mostrarDatos() const;
    friend std::ostream& operator << (std::ostream& out, const cLibro& libro);
    friend std::istream& operator >> (std::istream& in, cLibro& libro);
};
void cLibro::ponerDatos(string nombre, string autor, short anio, short edicion){
    this->nombre = nombre;
    this->autor = autor;
    this->anio = anio;
    this->edicion = edicion;
}
string cLibro::mostrarNombre() const{
    return nombre;
}
string cLibro::mostrarAutor() const{
    return autor;
}
short cLibro::mostrarAnio() const{
    return anio;
}
string cLibro::mostrarDatos() const{
    std::stringstream ss;
    ss << '\t' << anio << '\t' << edicion << '\t' << autor << '\t' << nombre << '\n';
    return ss.str();
}
std::ostream& operator << (std::ostream& out, const cLibro& libro){
    out << libro.anio << ' ' << libro.edicion << ' ' << libro.nombre << '\n' << libro.autor << '\n';
    return out;
}
std::istream& operator >> (std::istream& in, cLibro& libro){
    in >> libro.anio >> libro.edicion;
    in.ignore();
    std::getline(in,libro.nombre);
    std::getline(in,libro.autor);
    return in;
}
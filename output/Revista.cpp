#include "Revista.h"
#include <iostream>

using namespace std;

// Constructor
Revista::Revista(const string& nombre, const string& isbn, const string& autor,
    const string& prestado, const string& numeroEdicion, const string& mesPublicacion)
    : MaterialBibliografico(nombre, isbn, autor, prestado),
    numeroEdicion(numeroEdicion), mesPublicacion(mesPublicacion) {}

// Getters y Setters
string Revista::getNumeroEdicion() const {
    return numeroEdicion;
}

void Revista::setNumeroEdicion(const string& numeroEdicion) {
    this->numeroEdicion = numeroEdicion;
}

string Revista::getMesPublicacion() const {
    return mesPublicacion;
}

void Revista::setMesPublicacion(const string& mesPublicacion) {
    this->mesPublicacion = mesPublicacion;
}

// Sobrescribir el método para mostrar información
void Revista::mostrarInfo() const {
    cout << "Revista: " << getNombre() << "\n"
        << "ISBN: " << getIsbn() << "\n"
        << "Autor: " << getAutor() << "\n"
        << "Prestado: " << getPrestado() << "\n"
        << "Número de Edicion: " << numeroEdicion << "\n"
        << "Mes de Publicacion: " << mesPublicacion << endl;
}

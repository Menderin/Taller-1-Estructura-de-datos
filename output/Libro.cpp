#include "Libro.h"
#include <iostream>

using namespace std;

// Constructor
Libro::Libro(const string& nombre, const string& isbn, const string& autor,
    const string& fechaPublicacion, const string& resumen)
    : MaterialBibliografico(nombre, isbn, autor),
    fechaPublicacion(fechaPublicacion), resumen(resumen) {}

// Getters y Setters
string Libro::getFechaPublicacion() const {
    return fechaPublicacion;
}

void Libro::setFechaPublicacion(const string& fechaPublicacion) {
    this->fechaPublicacion = fechaPublicacion;
}

string Libro::getResumen() const {
    return resumen;
}

void Libro::setResumen(const string& resumen) {
    this->resumen = resumen;
}

// Sobrescribir el método para mostrar información
void Libro::mostrarInfo() const {
    cout << "Libro: " << getNombre() << "\n"
        << "ISBN: " << getIsbn() << "\n"
        << "Autor: " << getAutor() << "\n"
        << "Prestado: " << (getPrestado() ? "Sí" : "No") << "\n"
        << "Fecha de Publicacion: " << fechaPublicacion << "\n"
        << "Resumen: " << resumen << endl;
}


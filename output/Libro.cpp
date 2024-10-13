#include "Libro.h"
#include <iostream>

using namespace std;

// Constructor
Libro::Libro(const string& nombre, const string& isbn, const string& autor,
    const string& fechaPublicacion, const string& resumen, 
    const string& prestado, Usuario* usuario)
    : MaterialBibliografico(nombre, isbn, autor) {
    
    this->fechaPublicacion = fechaPublicacion;
    this->resumen = resumen;
    
    if (prestado == "Si") {
        this->setPrestado(true);
        this->setUsuarioPrestado(usuario);
    } else {
        this->setPrestado(false);
        this->setUsuarioPrestado(nullptr);
    }
}

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


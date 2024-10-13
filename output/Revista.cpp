#include "Revista.h"
#include <iostream>

using namespace std;

// Constructor
Revista::Revista(const string& nombre, const string& isbn, const string& autor,
     const string& numeroEdicion, const string& mesPublicacion, const string& prestado, Usuario* usuario)
     : MaterialBibliografico(nombre, isbn, autor), numeroEdicion(numeroEdicion), mesPublicacion(mesPublicacion) 
     {
    if (prestado == "Si") {
        this->setPrestado(true);
        this->setUsuarioPrestado(usuario);
    } else {
        this->setPrestado(false);
        this->setUsuarioPrestado(nullptr);
    }
}
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
        << "Prestado: " << (getPrestado() ? "Sí" : "No") << "\n"
        << "Numero de Edicion: " << numeroEdicion << "\n"
        << "Mes de Publicacion: " << mesPublicacion << endl;
}

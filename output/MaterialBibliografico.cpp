#include "MaterialBibliografico.h"
#include <iostream>

using namespace std;                                                                                                                                                                                                                                 

// Constructor
MaterialBibliografico::MaterialBibliografico(const string& nombre, const string& isbn, const string& autor, const string& prestado)
    : nombre(nombre), isbn(isbn), autor(autor), prestado(prestado) {}

// Métodos para acceder a los atributos
string MaterialBibliografico::getNombre() const {
    return nombre;
}

string MaterialBibliografico::getIsbn() const {
    return isbn;
}

string MaterialBibliografico::getAutor() const {
    return autor;
}

string MaterialBibliografico::getPrestado() const {
    return prestado;
}

// Métodos para modificar los atributos
void MaterialBibliografico::setNombre(const string& nombre) {
    this->nombre = nombre;
}

void MaterialBibliografico::setIsbn(const string& isbn) {
    this->isbn = isbn;
}

void MaterialBibliografico::setAutor(const string& autor) {
    this->autor = autor;
}

void MaterialBibliografico::setPrestado(const string& prestado) {
    this->prestado = prestado;
}

// Método para mostrar la información del material
void MaterialBibliografico::mostrarInfo() const {
    cout << "Nombre: " << nombre << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Autor: " << autor << endl;
    cout << "Prestado: " << prestado << endl;
}

#include "MaterialBibliografico.h"
#include <iostream>
#include "Usuario.h"

using namespace std;                                                                                                                                                                                                                                 

// Constructor
MaterialBibliografico::MaterialBibliografico(const string& nombre, const string& isbn, const string& autor)
: nombre(nombre), isbn(isbn), autor(autor), prestado(false), usuarioPrestado(nullptr) {}
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

bool MaterialBibliografico::getPrestado() const {
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

void MaterialBibliografico::setPrestado(const bool& prestado) {
    this->prestado = prestado;
}
// Métodos para prestar y devolver
void MaterialBibliografico::prestar() {
    if (!prestado) {
        prestado = true;
        cout << "El material ha sido prestado.\n";
    } else {
        cout << "El material ya está prestado.\n";
    }
}

void MaterialBibliografico::devolver() {
    if (prestado) {
        prestado = false;
        cout << "El material ha sido devuelto.\n";
    } else {
        cout << "El material no estaba prestado.\n";
    }
}

// Método para mostrar la información del material
void MaterialBibliografico::mostrarInfo() const {
    cout << "Nombre: " << nombre << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Autor: " << autor << endl;
    cout << "Prestado: " << (getPrestado() ? "Sí" : "No") << "\n";
}
// Métodos para acceder a los atributos
Usuario* MaterialBibliografico::getUsuarioPrestado() const {
    return usuarioPrestado;  // Devuelve el usuario que tiene el material prestado
}

// Métodos para modificar los atributos
void MaterialBibliografico::setUsuarioPrestado(Usuario* usuario) {
    this->usuarioPrestado = usuario;  // Establece el usuario que tiene el material prestado
}
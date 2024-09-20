#include "Usuario.h"
#include <iostream>

using namespace std;

// Constructor
Usuario::Usuario(const string& nombre, const string& id) : nombre(nombre), id(id), cantidadMateriales(0) {
    // Inicializar el array de punteros a nullptr
    for (int i = 0; i < 5; ++i) {
        materialesPrestados[i] = nullptr;
    }
}

// Métodos de acceso
string Usuario::getNombre() const {
    return nombre;
}

void Usuario::setNombre(const string& nombre) {
    this->nombre = nombre;
}

string Usuario::getId() const {
    return id;
}

void Usuario::setId(const string& id) {
    this->id = id;
}

// Métodos para manejar los materiales prestados
bool Usuario::prestarMaterial(MaterialBibliografico* material) {
    if (cantidadMateriales < 5) {
        if (!material->getPrestado()) {  // Verificar que el material no esté prestado
            materialesPrestados[cantidadMateriales] = material;
            material->prestar();  // Cambiar el estado del material a "prestado"
            ++cantidadMateriales;
            return true;
        } else {
            cout << "El material ya está prestado.\n";
        }
    } else {
        cout << "No puedes prestar más de 5 materiales.\n";
    }
    return false;
}

bool Usuario::devolverMaterial(MaterialBibliografico* material) {
    for (int i = 0; i < cantidadMateriales; ++i) {
        if (materialesPrestados[i] == material) {
            // Mover el último material al lugar del material devuelto
            materialesPrestados[i] = materialesPrestados[cantidadMateriales - 1];
            materialesPrestados[cantidadMateriales - 1] = nullptr;
            --cantidadMateriales;
            material->devolver();  // Cambiar el estado del material a "no prestado"
            return true;
        }
    }
    return false; // El material no estaba en la lista de materiales prestados
}

void Usuario::mostrarMaterialesPrestados() const {
    for (int i = 0; i < cantidadMateriales; ++i) {
        materialesPrestados[i]->mostrarInfo(); // Asume que MaterialBibliografico tiene un método mostrarInfo()
        cout << endl;
    }
}

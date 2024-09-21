#include "Usuario.h"
#include <iostream>
#include "MaterialBibliografico.h"

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
    if (cantidadMateriales < 5 && !material->getPrestado()) {
        material->setPrestado(true);  // Marcar el material como prestado
        material->setUsuarioPrestado(this);  // Asignar el usuario al material
        materialesPrestados[cantidadMateriales] = material;
        ++cantidadMateriales;
        return true;
    }
    return false;  // No se puede prestar más materiales si ya se tienen 5 o está prestado
}


bool Usuario::devolverMaterial(MaterialBibliografico* material) {
    for (int i = 0; i < cantidadMateriales; ++i) {
        if (materialesPrestados[i] == material) {
            material->setPrestado(false);  // Marcar el material como no prestado
            material->setUsuarioPrestado(nullptr);  // Eliminar el usuario prestado
            // Mover el último material al lugar del material devuelto
            materialesPrestados[i] = materialesPrestados[cantidadMateriales - 1];
            materialesPrestados[cantidadMateriales - 1] = nullptr;
            --cantidadMateriales;
            return true;
        }
    }
    return false;  // El material no estaba en la lista de materiales prestados
}


void Usuario::mostrarMaterialesPrestados() const {
    for (int i = 0; i < cantidadMateriales; ++i) {
        materialesPrestados[i]->mostrarInfo(); // Asume que MaterialBibliografico tiene un método mostrarInfo()
        cout << endl;
    }
}

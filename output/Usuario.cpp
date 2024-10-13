#include "Usuario.h"
#include <iostream>
#include "MaterialBibliografico.h"

using namespace std;
// Constructor
Usuario::Usuario(const string& nombre, const string& id) : nombre(nombre), id(id), cantidadMateriales(0) {
    // Inicializar el array con nullptr
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
    // Verificar si el material ya está prestado al usuario
    for (int i = 0; i < cantidadMateriales; ++i) {
        if (materialesPrestados[i] == material) {
            return false;
        }
    }
    if (cantidadMateriales < 5) {  // Límite de 5 materiales
        material->setPrestado(true);  // Marcar el material como prestado
        material->setUsuarioPrestado(this);  // Asignar el usuario al material
        materialesPrestados[cantidadMateriales] = material;  // Agregar al array
        ++cantidadMateriales;
        return true;
    }
    return false;  // No se puede prestar más materiales
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
    if (cantidadMateriales == 0) {
        std::cout << "No tienes materiales prestados.\n";
        cout << endl;
        return;
    }
    cout << "Materiales prestados a " << nombre << ":\n";
    cout << "-----------------------------\n";
    for (int i = 0; i < cantidadMateriales; ++i) {
        if (materialesPrestados[i]) {
            std::cout << "Material " << i + 1 << ":\n";
            materialesPrestados[i]->mostrarInfo();  // Mostrar la información del material
            std::cout << "---------------------\n";
        } else {
            std::cout << "Error: Material en la posición " << i << " es nullptr.\n";
        }
    }
}

void Usuario::devolverTodosLosMateriales() {
    for (int i = 0; i < cantidadMateriales; ++i) {
        if (materialesPrestados[i]) {
            materialesPrestados[i]->setPrestado(false);   
            materialesPrestados[i]->setUsuarioPrestado(nullptr);  
            materialesPrestados[i] = nullptr;  
        }
    }
    cantidadMateriales = 0;
}





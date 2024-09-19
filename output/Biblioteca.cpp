#include "Biblioteca.h"

Biblioteca::Biblioteca() : cantidadMateriales(0) {
    // Inicializamos el array con punteros nulos
    for (int i = 0; i < 100; ++i) {
        recursos[i] = nullptr;
    }
}

Biblioteca::~Biblioteca() {
    // Liberamos la memoria de los materiales almacenados
    for (int i = 0; i < cantidadMateriales; ++i) {
        delete recursos[i];
    }
}

bool Biblioteca::agregarMaterial(MaterialBibliografico* material) {
    // Verificar si hay espacio en el array
    if (cantidadMateriales >= 100) {
        std::cerr << "La biblioteca está llena, no se puede agregar más materiales.\n";
        return false;
    }

    // Agregar el material al array y aumentar el contador
    recursos[cantidadMateriales++] = material;
    std::cout << "Material agregado correctamente.\n";
    return true;
}

void Biblioteca::mostrarMateriales() const {
    // Verificar si hay materiales en la biblioteca
    if (cantidadMateriales == 0) {
        std::cout << "No hay materiales en la biblioteca.\n";
        return;
    }

    // Mostrar la información de todos los materiales
    std::cout << "Materiales en la biblioteca:\n";
    for (int i = 0; i < cantidadMateriales; ++i) {
        recursos[i]->mostrarInfo();
        std::cout << "----------\n";
    }
}

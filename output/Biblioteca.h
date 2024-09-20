#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "MaterialBibliografico.h"
#include "Libro.h"
#include "Revista.h"
#include <string>
#include <iostream>

class Biblioteca {
private:
    MaterialBibliografico* recursos[100];  // Array estático de punteros a MaterialBibliografico
    int cantidadMateriales;

public:
    Biblioteca();  // Constructor
    ~Biblioteca();  // Destructor para liberar memoria

    bool agregarMaterial(MaterialBibliografico* material);  // Método para agregar material
    void mostrarMateriales() const;  // Método para mostrar todos los materiales
    MaterialBibliografico* buscarMaterial(const std::string& criterio, const std::string& valor) const;  // Método para buscar material
};

#endif

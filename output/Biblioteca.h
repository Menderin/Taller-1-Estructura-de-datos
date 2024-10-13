#pragma once
#include "MaterialBibliografico.h"
#include "Libro.h"
#include "Revista.h"
#include <string>
#include <iostream>
#include <vector>

class Biblioteca {
private:
    MaterialBibliografico* recursos[100];  // Array estático de punteros a MaterialBibliografico
    int cantidadMateriales;

public:
    Biblioteca();
    ~Biblioteca();
    bool agregarMaterial(MaterialBibliografico* material);  // Método para agregar material
    void mostrarMateriales() const;  // Método para mostrar todos los materiales
    MaterialBibliografico* buscarMaterial(const std::string& criterio, const std::string& valor) const;  // Método para buscar material
    std::vector<Libro*> getLibros() const;    // Método para obtener todos los libros
    std::vector<Revista*> getRevistas() const;  // Método para obtener todas las revistas
    int getCantidadMateriales() const; //retorna numeros de materiales en el array
    MaterialBibliografico* getMaterial(int indice) const; //get material por indice
};


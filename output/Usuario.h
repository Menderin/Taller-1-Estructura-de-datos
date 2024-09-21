#pragma once
#include <string>
#include "MaterialBibliografico.h"

class MaterialBibliografico;

class Usuario {
public:
    // Constructor
    Usuario(const std::string& nombre = "", const std::string& id = "");

    // Métodos de acceso (getters y setters)
    std::string getNombre() const;
    void setNombre(const std::string& nombre);

    std::string getId() const;
    void setId(const std::string& id);

    // Métodos para manejar los materiales prestados
    bool prestarMaterial(MaterialBibliografico* material);
    bool devolverMaterial(MaterialBibliografico* material);
    void mostrarMaterialesPrestados() const;

private:
    std::string nombre;
    std::string id; // Cambiado a string
    MaterialBibliografico* materialesPrestados[5]; // Array de punteros a MaterialBibliografico
    int cantidadMateriales; // Contador de materiales actualmente prestados
};


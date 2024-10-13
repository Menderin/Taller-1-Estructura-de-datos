#pragma once
#include <string>
#include "MaterialBibliografico.h"

class MaterialBibliografico;

class Usuario {

    private:
        std::string nombre;
        std::string id;
        MaterialBibliografico* materialesPrestados[5]; // Array de punteros a MaterialBibliografico
        int cantidadMateriales; // Contador de materiales actualmente prestados
    public:
        
        Usuario(const std::string& nombre = "", const std::string& id = "");
        std::string getNombre() const;
        void setNombre(const std::string& nombre);
        std::string getId() const;
        void setId(const std::string& id);
        // Métodos para manejar los materiales prestados
        bool prestarMaterial(MaterialBibliografico* material);
        bool devolverMaterial(MaterialBibliografico* material);
        void mostrarMaterialesPrestados() const;
};


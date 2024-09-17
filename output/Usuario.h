#include <iostream>
#include "MaterialBibliografico.h"
#pragma once

using namespace std;

class Usuario{
    private: 
        string nombre;
        string id;
        MaterialBibliografico MaterialBibliografico[5];
    
    public:
        Usuario(string nombre, string id);
        void prestarMaterial(string);
        void devolverMaterial(string);
        void mostrarMaterialesPrestados();
};
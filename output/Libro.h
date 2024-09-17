#include <iostream>
#pragma once
using namespace std;
#include "MaterialBibliografico.h"
class Libro : public MaterialBibliografico{
    private: 
        string fechaPublicacion;
        string resumen;
    public:
        Libro(string,string,string,string,string,string);
        void mostrarInformacion();

};

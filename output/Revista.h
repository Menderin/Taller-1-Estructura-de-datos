#include "MaterialBibliografico.h"
#include <iostream>
#pragma once
using namespace std;

class Revista : public MaterialBibliografico{

    private:
        string numeroEdicion;
        string mesPublicacion;
    public:
        Revista(string,string,string,string,string,string);
        void mostrarInformacion();
};

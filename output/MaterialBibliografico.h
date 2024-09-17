#include <iostream>
#pragma once
using namespace std;

class MaterialBibliografico{
    private:
        string nombre;
        string isbn;
        string autor;
        string prestado;

    public:
        MaterialBibliografico(string,string,string,string);
        virtual void mostrarInformacion();
        string getEstado();
};
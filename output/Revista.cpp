#include "MaterialBibliografico.h"
#include "Revista.h"
#include <iostream>
using namespace std;

Revista::Revista(string nombre,string isbm,string autor,string prestado,string numeroEdicion,string mesPublicacion):MaterialBibliografico(string (nombre),string (isbm),string (autor),string (prestado)){
    this-> numeroEdicion = numeroEdicion;
    this-> mesPublicacion = mesPublicacion; 
}

void Revista::mostrarInformacion(){
    MaterialBibliografico:mostrarInformacion();
    cout<<"Edicion de la revista: "<<numeroEdicion<<endl;
    cout<<"Mes de publicacion: "<<mesPublicacion<<endl;
}
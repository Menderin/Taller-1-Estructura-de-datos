#include "MaterialBibliografico.h"
#include "Libro.h"
#include <iostream>
using namespace std;

Libro::Libro(string nombre,string isbm,string autor,string prestado,string fecha,string resumen):MaterialBibliografico(string (nombre),string (isbm),string (autor),string (prestado)){
    this-> fechaPublicacion = fecha;
    this-> resumen = resumen;
};

void Libro::mostrarInformacion(){
    MaterialBibliografico:mostrarInformacion();
    cout<<"Fecha de Publicación: "<< fechaPublicacion<<endl;
    cout<<"Resumen del libro: "<<endl;
    cout<<resumen<<endl;
    }

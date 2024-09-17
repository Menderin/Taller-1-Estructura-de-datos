#include "MaterialBibliografico.h"
#include <iostream>

MaterialBibliografico::MaterialBibliografico(string nombre,string isbn, string autor, string prestado){
    this -> nombre = nombre;
    this -> isbn = isbn;
    this -> autor = autor;
    this -> prestado = prestado;
}
void MaterialBibliografico :: mostrarInformacion(){
    cout<<"Titulo: "<<nombre<<endl;
    cout<<"Isbm: "<<isbn<<endl;
    cout<<"Autor: "<<autor<<endl;
    cout<<"Disponible: "<<getEstado()<<endl;
}

string MaterialBibliografico::getEstado(){
    if(prestado == "Y"){
        return "No disponible";
    }
    else{
        return "Disponible";
    }
}
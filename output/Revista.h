#ifndef REVISTA_H
#define REVISTA_H

#include "MaterialBibliografico.h"
#include <string>

using namespace std;

class Revista : public MaterialBibliografico {
private:
    string numeroEdicion;
    string mesPublicacion;

public:
    // Constructor
    Revista(const string& nombre, const string& isbn, const string& autor,const string& numeroEdicion, const string& mesPublicacion);

    // Getters y Setters
    string getNumeroEdicion() const;
    void setNumeroEdicion(const string& numeroEdicion);

    string getMesPublicacion() const;
    void setMesPublicacion(const string& mesPublicacion);

    // Sobrescribir método para mostrar información
    void mostrarInfo() const override;
};

#endif // REVISTA_H

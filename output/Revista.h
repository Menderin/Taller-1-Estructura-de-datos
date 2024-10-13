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
    Revista(const string& nombre, const string& isbn, const string& autor,const string& numeroEdicion,
    const string& mesPublicacion,  const std::string& prestado = "No", Usuario* usuario = nullptr);
    // Getters y Setters
    string getNumeroEdicion() const;
    void setNumeroEdicion(const string& numeroEdicion);
    string getMesPublicacion() const;
    void setMesPublicacion(const string& mesPublicacion);
    void mostrarInfo() const override;
};

#endif // REVISTA_H

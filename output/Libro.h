#pragma once
#include "MaterialBibliografico.h"
#include <string>

using namespace std;

class Libro : public MaterialBibliografico {
private:

    string fechaPublicacion;
    string resumen;

public:
    // Constructor
    Libro(const string& nombre, const string& isbn, const string& autor, const string& fechaPublicacion,
     const string& resumen, const std::string& prestado = "No", Usuario* usuario = nullptr);
    // Getters y Setters
    string getFechaPublicacion() const;
    void setFechaPublicacion(const string& fechaPublicacion);
    string getResumen() const;
    void setResumen(const string& resumen);
    void mostrarInfo() const override;
};



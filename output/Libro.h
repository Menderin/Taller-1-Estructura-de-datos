#ifndef LIBRO_H
#define LIBRO_H

#include "MaterialBibliografico.h"
#include <string>

using namespace std;

class Libro : public MaterialBibliografico {
private:
    string fechaPublicacion;
    string resumen;

public:
    // Constructor
    Libro(const string& nombre, const string& isbn, const string& autor,
        const string& prestado, const string& fechaPublicacion, const string& resumen);

    // Getters y Setters
    string getFechaPublicacion() const;
    void setFechaPublicacion(const string& fechaPublicacion);

    string getResumen() const;
    void setResumen(const string& resumen);

    // Sobrescribir método para mostrar información
    void mostrarInfo() const override;
};

#endif // LIBRO_H

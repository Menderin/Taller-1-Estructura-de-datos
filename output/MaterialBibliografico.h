#ifndef MATERIALBIBLIOGRAFICO_H
#define MATERIALBIBLIOGRAFICO_H

#include <string>

using namespace std;

class MaterialBibliografico {
protected:
    string nombre;
    string isbn;
    string autor;
    string prestado;

public:
    // Constructor
    MaterialBibliografico(const string& nombre, const string& isbn, const string& autor, const string& prestado);

    // Métodos para acceder a los atributos
    string getNombre() const;
    string getIsbn() const;
    string getAutor() const;
    string getPrestado() const;

    // Métodos para modificar los atributos
    void setNombre(const string& nombre);
    void setIsbn(const string& isbn);
    void setAutor(const string& autor);
    void setPrestado(const string& prestado);

    // Método para mostrar la información del material
    virtual void mostrarInfo() const;
};

#endif // MATERIALBIBLIOGRAFICO_H


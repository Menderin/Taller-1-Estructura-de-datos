#ifndef MATERIALBIBLIOGRAFICO_H
#define MATERIALBIBLIOGRAFICO_H

#include <string>

using namespace std;

class MaterialBibliografico {
protected:
    string nombre;
    string isbn;
    string autor;
    bool prestado;

public:
    // Constructor
    MaterialBibliografico(const string& nombre, const string& isbn, const string& autor);

    // Métodos para acceder a los atributos
    string getNombre() const;
    string getIsbn() const;
    string getAutor() const;
    bool getPrestado() const;

    // Métodos para modificar los atributos
    void setNombre(const string& nombre);
    void setIsbn(const string& isbn);
    void setAutor(const string& autor);
    void setPrestado(const bool& prestado);

    // Método para mostrar la información del material
    virtual void mostrarInfo() const;

    // Métodos para préstamo
    void prestar();  // Cambia prestado a true
    void devolver();  // Cambia prestado a false
};



#endif // MATERIALBIBLIOGRAFICO_H


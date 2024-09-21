#ifndef MATERIALBIBLIOGRAFICO_H
#define MATERIALBIBLIOGRAFICO_H
#include "Usuario.h"
#include <string>
class Usuario;
using namespace std;

class MaterialBibliografico {
protected:
    string nombre;
    string isbn;
    string autor;
    bool prestado;
    Usuario* usuarioPrestado;  // Puntero al usuario que tiene el material prestado

public:
    // Constructor
    MaterialBibliografico(const string& nombre, const string& isbn, const string& autor);

    // Métodos para acceder a los atributos
    string getNombre() const;
    string getIsbn() const;
    string getAutor() const;
    bool getPrestado() const;
    Usuario* getUsuarioPrestado() const;  // Nuevo método para obtener el usuario que tiene el material prestado

    // Métodos para modificar los atributos
    void setNombre(const string& nombre);
    void setIsbn(const string& isbn);
    void setAutor(const string& autor);
    void setPrestado(const bool& prestado);
    void setUsuarioPrestado(Usuario* usuario);  // Nuevo método para establecer el usuario que tiene el material
    // Método para mostrar la información del material
    virtual void mostrarInfo() const;

    // Métodos para préstamo
    void prestar();  // Cambia prestado a true
    void devolver();  // Cambia prestado a false
};



#endif // MATERIALBIBLIOGRAFICO_H


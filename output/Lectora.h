#pragma once
#include <string>
#include <vector>
#include "Usuario.h"
#include "Libro.h"
#include "Revista.h"

using namespace std;

class Lectora {

private:
    // Nombres de los archivos
    const string archivoUsuarios = "usuarios.txt";
    const string archivoLibros = "libros.txt";
    const string archivoRevistas = "revistas.txt";
    vector<string> leerArchivo(const string& nombreArchivo) const; //Metodo comun para leer archivos


public:
    Lectora();
    ~Lectora();
    vector<Usuario*> leerUsuarios() const;
    vector<Libro*> leerLibros(const std::vector<Usuario*>& usuarios) const;
    vector<Revista*> leerRevistas(const std::vector<Usuario*>& usuarios) const;
    void guardarUsuarios(const std::vector<Usuario*>& usuarios) const;  // Nueva función para guardar usuarios
    void guardarLibros(const vector<Libro*>& libros) const;
    void guardarRevistas(const vector<Revista*>& revistas) const;

};
#include "Lectora.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Lectora::Lectora() {}

Lectora::~Lectora() {}

vector<string> Lectora::leerArchivo(const string& nombreArchivo) const {
    vector<string> lineas;
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return lineas;
    }

    string linea;
    while (getline(archivo, linea)) {
        lineas.push_back(linea);
    }

    archivo.close();
    return lineas;
}

vector<Usuario*> Lectora::leerUsuarios() const {
    vector<Usuario*> usuarios;
    vector<string> lineas = leerArchivo(archivoUsuarios);

    for (const string& linea : lineas) {
        stringstream ss(linea);
        string nombre;
        string id; // Cambiado a string

        // Leer el nombre y el ID desde la línea
        getline(ss, nombre, ',');
        getline(ss, id); // Leer el id como string

        // Crear una instancia de Usuario y agregar al vector
        Usuario* usuario = new Usuario(nombre, id);
        usuarios.push_back(usuario);
    }

    return usuarios;
}

vector<Libro*> Lectora::leerLibros() const {
    vector<Libro*> libros;
    vector<string> lineas = leerArchivo(archivoLibros);

    for (const string& linea : lineas) {
        stringstream ss(linea);
        string nombre, isbn, autor, prestado, fechaPublicacion, resumen;

        // Leer los campos desde la línea
        getline(ss, nombre, ',');
        getline(ss, isbn, ',');
        getline(ss, autor, ',');
        getline(ss, prestado, ',');
        getline(ss, fechaPublicacion, ',');
        getline(ss, resumen);

        // Crear una instancia de Libro y agregar al vector
        Libro* libro = new Libro(nombre, isbn, autor, prestado, fechaPublicacion, resumen);
        libros.push_back(libro);
    }

    return libros;
}

vector<Revista*> Lectora::leerRevistas() const {
    vector<Revista*> revistas;
    vector<string> lineas = leerArchivo(archivoRevistas); // Cambiado a archivoRevistas

    for (const string& linea : lineas) {
        stringstream ss(linea);
        string nombre, isbn, autor, prestado, numeroEdicion, mesPublicacion;

        // Leer los campos desde la línea
        getline(ss, nombre, ',');
        getline(ss, isbn, ',');
        getline(ss, autor, ',');
        getline(ss, prestado, ',');
        getline(ss, numeroEdicion, ',');
        getline(ss, mesPublicacion);

        // Crear una instancia de Revista y agregar al vector
        Revista* revista = new Revista(nombre, isbn, autor, prestado, numeroEdicion, mesPublicacion);
        revistas.push_back(revista);
    }

    return revistas;
}

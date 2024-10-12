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
    vector<string> lineas = leerArchivo("usuarios.txt");  // Asegúrate de que el nombre sea el correcto

    if (lineas.empty()) {
        cerr << "No se encontraron usuarios en el archivo." << endl;
        return usuarios;
    }

    for (const string& linea : lineas) {
        stringstream ss(linea);
        string nombre;
        string id;

        // Leer el nombre y el ID desde la línea
        getline(ss, nombre, ',');
        getline(ss, id);

        if (!nombre.empty() && !id.empty()) {
            // Crear una instancia de Usuario y agregar al vector
            cout << "Usuario leído: " << nombre << ", ID: " << id << endl;  // Mensaje de depuración
            Usuario* usuario = new Usuario(nombre, id);
            usuarios.push_back(usuario);
        }
    }
    return usuarios;
}


vector<Libro*> Lectora::leerLibros(const vector<Usuario*>& usuarios) const {
    vector<Libro*> libros;
    vector<string> lineas = leerArchivo("libros.txt");

    for (const string& linea : lineas) {
        stringstream ss(linea);
        string nombre, isbn, autor, fechaPublicacion, resumen, prestado, idUsuario;

        // Leer los campos desde la línea
        getline(ss, nombre, ',');
        getline(ss, isbn, ',');
        getline(ss, autor, ',');
        getline(ss, fechaPublicacion, ',');
        getline(ss, resumen, ',');
        getline(ss, prestado, ',');  // Estado de préstamo (1 o 0)
        getline(ss, idUsuario);  // ID del usuario que tiene el material prestado

        // Crear el libro
        Libro* libro = new Libro(nombre, isbn, autor, fechaPublicacion, resumen);

        // Verificar si el material estaba prestado
        if (prestado == "1") {
            libro->setPrestado(true);

            // Buscar al usuario que tenía el libro prestado
            for (Usuario* usuario : usuarios) {
                if (usuario->getId() == idUsuario) {
                    libro->setUsuarioPrestado(usuario);  // Asignar el usuario al material
                    break;
                }
            }
        }

        libros.push_back(libro);
    }

    return libros;
}


vector<Revista*> Lectora::leerRevistas(const vector<Usuario*>& usuarios) const {
    vector<Revista*> revistas;
    vector<string> lineas = leerArchivo("revistas.txt");

    for (const string& linea : lineas) {
        stringstream ss(linea);
        string nombre, isbn, autor, numeroEdicion, mesPublicacion, prestado, idUsuario;

        // Leer los campos desde la línea
        getline(ss, nombre, ',');
        getline(ss, isbn, ',');
        getline(ss, autor, ',');
        getline(ss, numeroEdicion, ',');
        getline(ss, mesPublicacion, ',');
        getline(ss, prestado, ',');  // Estado de préstamo (1 o 0)
        getline(ss, idUsuario);      // ID del usuario que tiene la revista prestada

        // Crear la revista
        Revista* revista = new Revista(nombre, isbn, autor, numeroEdicion, mesPublicacion);

        // Verificar si la revista estaba prestada
        if (prestado == "1") {
            revista->setPrestado(true);

            // Buscar al usuario que tiene la revista prestada
            for (Usuario* usuario : usuarios) {
                if (usuario->getId() == idUsuario) {
                    revista->setUsuarioPrestado(usuario);  // Asignar el usuario a la revista
                    break;
                }
            }
        }

        revistas.push_back(revista);
    }

    return revistas;
}


void Lectora::guardarUsuarios(const vector<Usuario*>& usuarios) const {
    ofstream archivo("usuarios.txt");

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para escribir: usuarios.txt" << endl;
        return;
    }

    for (const Usuario* usuario : usuarios) {
        archivo << usuario->getNombre() << "," << usuario->getId() << endl;
    }

    archivo.close();
}
void Lectora::guardarLibros(const vector<Libro*>& libros) const {
    ofstream archivo(archivoLibros, ios::out | ios::trunc);  // Abrir el archivo en modo truncar para sobrescribir
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo de libros para escritura.\n";
        return;
    }

    for (const Libro* libro : libros) {
        archivo << libro->getNombre() << ","
                << libro->getIsbn() << ","
                << libro->getAutor() << ","
                << libro->getFechaPublicacion() << ","
                << libro->getResumen() << ","
                << (libro->getPrestado() ? "1" : "0") << ","
                << (libro->getPrestado() && libro->getUsuarioPrestado() ? libro->getUsuarioPrestado()->getId() : "0") << "\n";
    }
    archivo.close();
}


void Lectora::guardarRevistas(const vector<Revista*>& revistas) const {
    ofstream archivo(archivoRevistas, ios::out | ios::trunc);  // Abrir el archivo en modo truncar para sobrescribir
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo de revistas para escritura.\n";
        return;
    }

    for (const Revista* revista : revistas) {
        archivo << revista->getNombre() << ","
                << revista->getIsbn() << ","
                << revista->getAutor() << ","
                << revista->getNumeroEdicion() << ","
                << revista->getMesPublicacion() << ","
                << (revista->getPrestado() ? "1" : "0") << ","
                << (revista->getPrestado() && revista->getUsuarioPrestado() ? revista->getUsuarioPrestado()->getId() : "0") << "\n";
    }
    archivo.close();
}



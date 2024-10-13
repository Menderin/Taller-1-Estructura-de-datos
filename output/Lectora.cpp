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
        getline(ss, prestado, ',');  // Si o No
        getline(ss, idUsuario);      // ID del usuario o "null" si no está prestado

    

        // Crear el libro
        Libro* libro = new Libro(nombre, isbn, autor, fechaPublicacion, resumen, prestado);

        // Si el ID de usuario no es "null", buscar al usuario y asignarle el libro prestado
        if (prestado == "Si" && idUsuario != "null") {
            for (Usuario* usuario : usuarios) {
                if (usuario->getId() == idUsuario) {
                    
                    usuario->prestarMaterial(libro);  // Añadir el libro al array de materiales del usuario
                    libro->setUsuarioPrestado(usuario);  // Asignar el usuario prestado al libro
                    libro->setPrestado(true);  // Marcar el libro como prestado
                    break;
                }
            }
        }

        libros.push_back(libro);  // Añadir el libro a la lista general
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
        getline(ss, prestado, ',');  // Si o No
        getline(ss, idUsuario);      // ID del usuario o "null" si no está prestada

        // Mensaje de depuración para asegurarnos de que los datos se leen correctamente
        

        // Crear la revista
        Revista* revista = new Revista(nombre, isbn, autor, numeroEdicion, mesPublicacion, prestado);

        // Si el ID de usuario no es "null", buscar al usuario y asignarle la revista prestada
        if (prestado == "Si" && idUsuario != "null") {
            for (Usuario* usuario : usuarios) {
                if (usuario->getId() == idUsuario) {
                    
                    usuario->prestarMaterial(revista);  // Añadir la revista al array de materiales del usuario
                    revista->setUsuarioPrestado(usuario);  // Asignar el usuario prestado a la revista
                    revista->setPrestado(true);  // Marcar la revista como prestada
                    break;
                }
            }
        }

        revistas.push_back(revista);  // Añadir la revista a la lista general
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
    ofstream archivo("libros.txt", ios::out | ios::trunc);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo libros.txt para escritura." << endl;
        return;
    }

    for (const Libro* libro : libros) {
        archivo << libro->getNombre() << ","
                << libro->getIsbn() << ","
                << libro->getAutor() << ","
                << libro->getFechaPublicacion() << ","
                << libro->getResumen() << ","
                << (libro->getPrestado() ? "Si" : "No") << ","
                << (libro->getPrestado() ? libro->getUsuarioPrestado()->getId() : "null")
                << endl;
    }

    archivo.close();
}


void Lectora::guardarRevistas(const vector<Revista*>& revistas) const {
    ofstream archivo("revistas.txt", ios::out | ios::trunc);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo revistas.txt para escritura." << endl;
        return;
    }

    for (const Revista* revista : revistas) {
        archivo << revista->getNombre() << ","
                << revista->getIsbn() << ","
                << revista->getAutor() << ","
                << revista->getNumeroEdicion() << ","
                << revista->getMesPublicacion() << ","
                << (revista->getPrestado() ? "Si" : "No") << ","  // Indicar si está prestada
                << (revista->getPrestado() ? revista->getUsuarioPrestado()->getId() : "null")  // ID del usuario o "null"
                << endl;
    }

    archivo.close();
}








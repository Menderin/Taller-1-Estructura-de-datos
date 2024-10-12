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

        getline(ss, nombre, ',');
        getline(ss, isbn, ',');
        getline(ss, autor, ',');
        getline(ss, fechaPublicacion, ',');
        getline(ss, resumen, ',');
        getline(ss, prestado, ',');  // Si o No
        getline(ss, idUsuario);      // null si no está prestado

        Usuario* usuarioPrestado = nullptr;
        if (prestado == "Si") {
            for (Usuario* usuario : usuarios) {
                if (usuario->getId() == idUsuario) {
                    usuarioPrestado = usuario;
                    break;
                }
            }
        }

        // Crear el libro con los datos leídos, prestado y el usuario correspondiente
        Libro* libro = new Libro(nombre, isbn, autor, fechaPublicacion, resumen, prestado, usuarioPrestado);
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

        getline(ss, nombre, ',');
        getline(ss, isbn, ',');
        getline(ss, autor, ',');
        getline(ss, numeroEdicion, ',');
        getline(ss, mesPublicacion, ',');
        getline(ss, prestado, ',');  // Si o No
        getline(ss, idUsuario);      // null si no tiene dueño

        Usuario* usuarioPrestado = nullptr;
        if (prestado == "Si") {
            for (Usuario* usuario : usuarios) {
                if (usuario->getId() == idUsuario) {
                    usuarioPrestado = usuario;
                    break;
                }
            }
        }

        Revista* revista = new Revista(nombre, isbn, autor, numeroEdicion, mesPublicacion, prestado, usuarioPrestado);
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
    // Abrir el archivo libros.txt en modo de escritura y truncar (eliminar contenido anterior)
    ofstream archivo("libros.txt", ios::out | ios::trunc);

    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo libros.txt para escritura." << endl;
        return;
    }

    // Guardar los datos de cada libro en el archivo
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

    // Cerrar el archivo después de escribir
    archivo.close();
    cout << "Libros guardados correctamente." << endl;  // Mensaje opcional para verificar que se guardaron correctamente
}

void Lectora::guardarRevistas(const vector<Revista*>& revistas) const {
    // Abrir el archivo revistas.txt en modo de escritura y truncar (eliminar contenido anterior)
    ofstream archivo("revistas.txt", ios::out | ios::trunc);

    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo revistas.txt para escritura." << endl;
        return;
    }

    // Guardar los datos de cada revista en el archivo
    for (const Revista* revista : revistas) {
        archivo << revista->getNombre() << ","
                << revista->getIsbn() << ","
                << revista->getAutor() << ","
                << revista->getNumeroEdicion() << ","
                << revista->getMesPublicacion() << ","
                << (revista->getPrestado() ? "Si" : "No") << ","
                << (revista->getPrestado() ? revista->getUsuarioPrestado()->getId() : "null")
                << endl;
    }

    // Cerrar el archivo después de escribir
    archivo.close();
    cout << "Revistas guardadas correctamente." << endl;  // Mensaje opcional
}







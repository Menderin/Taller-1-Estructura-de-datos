#include <iostream>
#include <algorithm>
#include <limits>
#include "Lectora.h"
#include "Biblioteca.h"
#include "MaterialBibliografico.h"
#include "Libro.h"
#include "Revista.h"
#include "Usuario.h"

using namespace std;

void menu(Biblioteca&,Usuario&);
Usuario* accesoUsuario(const vector<Usuario*>& usuarios);  // Cambia esto en la declaración
string trim(const string& str);   // Cambia el parámetro a 'const string&'
void menuUsuarios(vector<Usuario*>& usuarios, Lectora& lectora, Biblioteca& biblioteca);
void buscarUsuario(const vector<Usuario*>& usuarios);
void crearUsuario(vector<Usuario*>& usuarios, Lectora& lectora);
void eliminarUsuario(vector<Usuario*>& usuarios, Lectora& lectora);


int main() {
    Lectora lectora;
    Biblioteca biblioteca;
    cout<<"Usuarios leidos desde 'usuarios.txt': "<<endl;
    vector<Usuario*> usuarios = lectora.leerUsuarios();
    vector<Libro*> libros = lectora.leerLibros(usuarios);
    vector<Revista*> revistas = lectora.leerRevistas(usuarios);

    // Imprimir los datos de los usuarios
    for (Libro* libro : libros) {
        biblioteca.agregarMaterial(libro);
    }

    // Agregar las revistas leídas a la biblioteca
    for (Revista* revista : revistas) {
        biblioteca.agregarMaterial(revista);
    }
    cout << "----------" << endl;

    menuUsuarios(usuarios, lectora, biblioteca);

    /*Usuario* usuario = accesoUsuario(usuarios);  // Verificar si el usuario es válido

    if (usuario != nullptr) {
        // Si el acceso es exitoso, mostrar el menú de la biblioteca
        menu(biblioteca, *usuario);
    } else {
        cout << "Acceso denegado. Cerrando el programa.\n";
    }
    */


    //Fin del programa

    for (Usuario* usuario : usuarios) {delete usuario;}
    for (Libro* libro : libros) {delete libro;}
    for (Revista* revista : revistas) { delete revista; }

    return 0;
}

void menuUsuarios(vector<Usuario*>& usuarios, Lectora& lectora, Biblioteca& biblioteca) {
    int opcion;
    bool continuar = true;

    while (continuar) {
        cout << "\nControl de Usuario:\n";
        cout << "1. Ingresar a Biblioteca\n";
        cout << "2. Buscar Usuario\n";
        cout << "3. Crear Usuario\n";
        cout << "4. Eliminar Usuario\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Usuario* usuario = accesoUsuario(usuarios);  // Verificar si el usuario es válido
                if (usuario != nullptr) {
                    menu(biblioteca, *usuario);  // Ingresar a la biblioteca
                } else {
                    cout << "Acceso denegado.\n";
                }
                break;
            }
            case 2:
                buscarUsuario(usuarios);
                break;
            case 3:
                crearUsuario(usuarios, lectora);
                break;
            case 4:
                eliminarUsuario(usuarios, lectora);
                break;
            case 5:
                continuar = false;
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida, por favor intente de nuevo.\n";
                break;
        }
    }
}


Usuario* accesoUsuario(const vector<Usuario*>& usuarios) {
    string nombre, id;

    // Limpiar el búfer antes de llamar a getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Ingrese su nombre: ";
    getline(cin, nombre);  // Lee el nombre
    nombre = trim(nombre);  // Limpiar espacios en blanco

    cout << "Ingrese su ID: ";
    getline(cin, id);  // Lee el ID
    id = trim(id);  // Limpiar espacios en blanco

    // Buscar al usuario en la lista
    for (Usuario* usuario : usuarios) {
        string nombreUsuario = trim(usuario->getNombre());  // Limpiar espacios al comparar
        string idUsuario = trim(usuario->getId());  // Limpiar espacios al comparar

        if (nombreUsuario == nombre && idUsuario == id) {
            cout << "Acceso concedido. Bienvenido, " << nombre << "!\n";
            return usuario;  // Usuario encontrado, devolver el puntero a ese usuario
        }
    }

    // Si no se encuentra el usuario
    cout << "Acceso denegado. Usuario no encontrado.\n";
    return nullptr;  // Devolver nullptr si no se encuentra al usuario
}


void buscarUsuario(const vector<Usuario*>& usuarios) {
    string nombre;
    cout << "Ingrese el nombre del usuario a buscar: ";
    cin.ignore();
    getline(cin, nombre);

    for (const Usuario* usuario : usuarios) {
        if (usuario->getNombre() == nombre) {
            cout << "Usuario encontrado: " << usuario->getNombre() << ", ID: " << usuario->getId() << endl;
            return;
        }
    }
    cout << "Usuario no encontrado.\n";
}

// Función para crear usuario
void crearUsuario(vector<Usuario*>& usuarios, Lectora& lectora) {
    string nombre, id;
    cout << "Ingrese el nombre del nuevo usuario: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese el ID del nuevo usuario: ";
    getline(cin, id);

    Usuario* nuevoUsuario = new Usuario(nombre, id);
    usuarios.push_back(nuevoUsuario);
    lectora.guardarUsuarios(usuarios);  // Guardar en el archivo usuarios.txt
    cout << "Usuario creado con éxito.\n";
}

// Función para eliminar usuario y borrarlo del txt
void eliminarUsuario(vector<Usuario*>& usuarios, Lectora& lectora) {
    string nombre;
    cout << "Ingrese el nombre del usuario a eliminar: ";
    cin.ignore();
    getline(cin, nombre);

    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
        if ((*it)->getNombre() == nombre) {
            delete *it;
            usuarios.erase(it);
            lectora.guardarUsuarios(usuarios);  // Guardar cambios en usuarios.txt
            cout << "Usuario eliminado con éxito.\n";
            return;
        }
    }
    cout << "Usuario no encontrado.\n";
}



void menu(Biblioteca& biblioteca, Usuario& usuario) {

    int opcion;
    bool continuar = true;

    while (continuar) {
         cout<<"Bienvenido "<<usuario.getNombre() <<" al sistema de Bilioteca Digital "<<endl;
        cout<<endl;
        cout << "1. Agregar libro\n";
        cout << "2. Agregar revista\n";
        cout << "3. Buscar material por título\n";
        cout << "4. Buscar material por autor\n";
        cout << "5. Mostrar todos los materiales\n";
        cout << "6. Solicitar prestamo de material\n";
        cout << "7. Devolver material\n";
        cout << "8. Salir\n";
        cout<<endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
    // Agregar un libro
                string nombre, isbn, autor, fechaPublicacion, resumen;

                cout << "Ingrese el nombre del libro: ";
                cin.ignore();
                getline(cin, nombre);

                // Verifica si el libro ya existe antes de agregarlo
                if (biblioteca.buscarMaterial("titulo", nombre) != nullptr) {
                    cout << "El libro ya existe en la biblioteca.\n";
                    break;
                }

                cout << "Ingrese el ISBN: ";
                getline(cin, isbn);
                cout << "Ingrese el autor: ";
                getline(cin, autor);
                cout << "Ingrese la fecha de publicación: ";
                getline(cin, fechaPublicacion);
                cout << "Ingrese el resumen: ";
                getline(cin, resumen);

                Libro* nuevoLibro = new Libro(nombre, isbn, autor, fechaPublicacion, resumen);
                biblioteca.agregarMaterial(nuevoLibro);
                break;
            }

            case 2: {
                // Agregar una revista
                string nombre, isbn, autor, numeroEdicion, mesPublicacion;

                cout << "Ingrese el nombre de la revista: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese el ISBN: ";
                getline(cin, isbn);
                cout << "Ingrese el autor: ";
                getline(cin, autor);
                cout << "Ingrese el número de edición: ";
                getline(cin, numeroEdicion);
                cout << "Ingrese el mes de publicación: ";
                getline(cin, mesPublicacion);

                Revista* nuevaRevista = new Revista(nombre, isbn, autor, numeroEdicion, mesPublicacion);
                biblioteca.agregarMaterial(nuevaRevista);
                break;
            }
            case 3: {
                // Buscar material por título
                string titulo;
                cout << "Ingrese el título a buscar: ";
                cin.ignore();
                getline(cin, titulo);

                MaterialBibliografico* encontrado = biblioteca.buscarMaterial("titulo", titulo);
                if (encontrado) {
                    cout << "Material encontrado:\n";
                    encontrado->mostrarInfo();
                } else {
                    cout << "No se encontró material con ese título.\n";
                }
                break;
            }
            case 4: {
                // Buscar material por autor
                string autorBusqueda;
                cout << "Ingrese el autor a buscar: ";
                cin.ignore();
                getline(cin, autorBusqueda);

                MaterialBibliografico* encontrado = biblioteca.buscarMaterial("autor", autorBusqueda);
                if (encontrado) {
                    cout << "Material encontrado:\n";
                    encontrado->mostrarInfo();
                } else {
                    cout << "No se encontró material con ese autor.\n";
                }
                break;
            }

            case 5: {
                // Mostrar todos los materiales solo una vez
                biblioteca.mostrarMateriales();  // Muestra todos los materiales almacenados    
                break;
            }

            case 6: {
                // Prestar material
                string titulo;
                cout << "Ingrese el título del material que solicita prestamo: ";
                cin.ignore();
                getline(cin, titulo);

                MaterialBibliografico* material = biblioteca.buscarMaterial("titulo", titulo);
                if (material && !material->getPrestado()) {
                    if (usuario.prestarMaterial(material)) {
                        cout << "Material prestado con éxito.\n";
                    } else {
                        cout << "No se pudo prestar el material. El usuario ya tiene 5 materiales prestados.\n";
                    }
                } else {
                    cout << "El material no se encuentra disponible o ya está prestado.\n";
                }
                break;
            }

            case 7: {
                cout << "Materiales actualmente prestados a " << usuario.getNombre() << ":\n";
                 usuario.mostrarMaterialesPrestados();
                // Devolver material
                string titulo;
                cout << "Ingrese el título del material a devolver: ";
                cin.ignore();
                getline(cin, titulo);

                MaterialBibliografico* material = biblioteca.buscarMaterial("titulo", titulo);
                if (material && usuario.devolverMaterial(material)) {
                    cout << "Material devuelto con éxito.\n";
                } else {
                    cout << "No se pudo devolver el material.\n";
                }
                break;
            }

            case 8:
                // Salir
                continuar = false;
                cout << "Saliendo del sistema...\n";
                break;

            default:
                cout << "Opción no válida, por favor intente de nuevo.\n";
                break;
        }
    }
}
string trim(const string& str) {
    const char* whitespace = " \t\n\r\f\v";  // Lista de posibles caracteres de espacio
    size_t first = str.find_first_not_of(whitespace);
    if (first == string::npos)
        return "";  // Si la cadena está vacía o sólo contiene espacios
    size_t last = str.find_last_not_of(whitespace);
    return str.substr(first, (last - first + 1));
}


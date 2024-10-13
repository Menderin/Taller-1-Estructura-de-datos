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

void menu(Biblioteca&,Usuario&,Lectora&);
Usuario* accesoUsuario(const vector<Usuario*>& usuarios);  // Cambia esto en la declaración
string trim(const string& str);   // Cambia el parámetro a 'const string&'
void menuUsuarios(vector<Usuario*>& usuarios, Lectora& lectora, Biblioteca& biblioteca);
void buscarUsuario(const vector<Usuario*>& usuarios);
void crearUsuario(vector<Usuario*>& usuarios, Lectora& lectora);
void eliminarUsuario(vector<Usuario*>& usuarios, Lectora& lectora);

int main() {
    Lectora lectora;
    Biblioteca biblioteca;
    //leer los usuarios, libros y revistas desde los archivos txt
    vector<Usuario*> usuarios = lectora.leerUsuarios();
    vector<Libro*> libros = lectora.leerLibros(usuarios);
    vector<Revista*> revistas = lectora.leerRevistas(usuarios);

    for (Libro* libro : libros) {
        biblioteca.agregarMaterial(libro);  // Agregar cada libro a la biblioteca
    }
    
    for (Revista* revista : revistas) {
        biblioteca.agregarMaterial(revista);  // Agregar cada revista a la biblioteca
    }

    menuUsuarios(usuarios, lectora, biblioteca);  // Iniciar el menú principal, da acceso al menu de los usuarios

    // Liberar memoria de todos los punteros y arrays
    for (Usuario* usuario : usuarios) { delete usuario; }
    for (Libro* libro : libros) { delete libro; }
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
        cout << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // Validar si la entrada es incorrecta
        if (cin.fail()) {
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            cout << "Entrada no válida. Por favor ingrese un número.\n";
            continue;  
        }

        switch (opcion) {
            case 1: {
                Usuario* usuario = accesoUsuario(usuarios);  // Verificar si el usuario es válido
                if (usuario != nullptr) {
                    menu(biblioteca, *usuario, lectora);  // Ingresar a la biblioteca
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Ingrese su nombre: ";
    getline(cin, nombre);  // Lee el nombre
    nombre = trim(nombre);  // Limpiar espacios en blanco

    cout << "Ingrese su ID: ";
    getline(cin, id);  // Lee el ID
    id = trim(id);

    // Buscar al usuario en la lista
    for (Usuario* usuario : usuarios) {
        string nombreUsuario = trim(usuario->getNombre());  
        string idUsuario = trim(usuario->getId());  

        if (nombreUsuario == nombre && idUsuario == id) {
            cout <<endl;
            cout << "Acceso concedido. Bienvenido. \n";
            cout << endl;
            return usuario;  
        }
    }
    // Si no se encuentra el usuario
    cout << "Acceso denegado. Usuario no encontrado.\n";
    return nullptr;  
}

void buscarUsuario(const vector<Usuario*>& usuarios) {
    string nombre;
    cout << "Ingrese el nombre del usuario a buscar: ";
    cin.ignore();
    getline(cin, nombre);

    for (const Usuario* usuario : usuarios) {
        if (usuario->getNombre() == nombre) {
            cout << "-----------------------------------\n";
            cout << "Usuario encontrado: " << usuario->getNombre() << ", ID: " << usuario->getId() << endl;
            return;
        }
    }
    cout << "Usuario no encontrado.\n";
}
// Función para crear nuevos usuario
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
            cout << "Usuario eliminado con exito.\n";
            return;
        }
    }
    cout << "Usuario no encontrado.\n";
}

void menu(Biblioteca& biblioteca, Usuario& usuario, Lectora& lectora) {

    int opcion;
    bool continuar = true;

    while (continuar) {
        cout<<"Bienvenido "<<usuario.getNombre() <<" al sistema de Bilioteca Digital "<<endl;
        cout<<endl;
        cout << "1. Agregar libro\n";
        cout << "2. Agregar revista\n";
        cout << "3. Buscar material\n";
        cout << "4. Mostrar todos los materiales\n";
        cout << "5. Mostrar mis materiales pedidos\n";
        cout << "6. Solicitar prestamo de material\n";
        cout << "7. Devolver material\n";
        cout << "8. Salir\n";
        cout<<endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Entrada no valida. Por favor ingrese un numero.\n";
            continue; // Volver a mostrar el menú
        }

        switch (opcion) {
            case 1: {
                // Agregar un libro
                string nombre, isbn, autor, fechaPublicacion, resumen;
                cout << "Ingrese el nombre del libro: ";
                cin.ignore();
                getline(cin, nombre);
                if (biblioteca.buscarMaterial("titulo", nombre) != nullptr) {
                    cout << "El libro ya existe en la biblioteca.\n";
                    break;
                }
                cout << "Ingrese el ISBN: ";
                getline(cin, isbn);
                cout << "Ingrese el autor: ";
                getline(cin, autor);
                cout << "Ingrese la fecha de publicacion: ";
                getline(cin, fechaPublicacion);
                cout << "Ingrese el resumen: ";
                getline(cin, resumen);
                
                Libro* nuevoLibro = new Libro(nombre, isbn, autor, fechaPublicacion, resumen, "No", nullptr);
                biblioteca.agregarMaterial(nuevoLibro);
                vector<Libro*> libros = biblioteca.getLibros();
                lectora.guardarLibros(libros);
                cout<<endl;
                cout<< "Libro agregado correctamente."<<endl;
                cout<<endl;
                break;
            }

            case 2: {
                // Agregar una revista

                string nombre, isbn, autor, numeroEdicion, mesPublicacion;
                cout << "Ingrese el nombre de la revista: ";
                cin.ignore();
                getline(cin, nombre);
                if (biblioteca.buscarMaterial("titulo", nombre) != nullptr) {
                    cout << "La revista ya existe en la biblioteca.\n";
                    break;
                }
                cout << "Ingrese el ISBN: ";
                getline(cin, isbn);
                cout << "Ingrese el autor: ";
                getline(cin, autor);
                cout << "Ingrese el numero de edicion: ";
                getline(cin, numeroEdicion);
                cout << "Ingrese el mes de publicacion: ";
                getline(cin, mesPublicacion);
                
                Revista* nuevaRevista = new Revista(nombre, isbn, autor, numeroEdicion, mesPublicacion, "No", nullptr);
                biblioteca.agregarMaterial(nuevaRevista);
                vector<Revista*> revistas = biblioteca.getRevistas();
                lectora.guardarRevistas(revistas);
                cout<<endl;
                cout<< "Revista agregada correctamente."<<endl;
                cout<<endl;
                break;
            }
            case 3: {
                //Buscar recursos por titulo o autor
            int subopcion;
            cout << "Buscar recurso por:\n";
            cout << "1. Título\n";
            cout << "2. Autor\n";
            cout << "Seleccione una opcion: ";
            cin >> subopcion;
            cout<<endl;

            if (subopcion == 1) {
                // Buscar por título
                string titulo;
                cout << "Ingrese el titulo a buscar: ";
                cin.ignore();
                getline(cin, titulo);
                cout<<endl;
                bool encontrado = false;
                for (int i = 0; i < biblioteca.getCantidadMateriales(); ++i) {
                    MaterialBibliografico* material = biblioteca.getMaterial(i);
                    if (material->getNombre() == titulo) {
                        material->mostrarInfo();
                        cout<<endl;
                        encontrado = true;
                    }
                }
                if (!encontrado) {
                    cout << "No se encontro material con ese título.\n";
                }

                } else if (subopcion == 2) {
                    // Buscar por autor
                    string autorBusqueda;
                    cout << "Ingrese el autor a buscar: ";
                    cin.ignore();
                    getline(cin, autorBusqueda);
                    cout<<endl;
                    bool encontrado = false;
                    for (int i = 0; i < biblioteca.getCantidadMateriales(); ++i) {
                        MaterialBibliografico* material = biblioteca.getMaterial(i);
                        if (material->getAutor() == autorBusqueda) {
                            material->mostrarInfo();  // Mostrar la información del material encontrado
                            cout<<endl;
                            encontrado = true;
                        }
                    }
                    if (!encontrado) {
                        cout << "No se encontro material con ese autor.\n";
                    }
                } else {
                    cout << "Opcion no valida.\n";
                }
                break;
            }
            case 4: {
                // Mostrar todos los materiales
                cout<<endl;
                biblioteca.mostrarMateriales();  
                break;
            }
            case 5: {
                // Mostrar recursos prestados por el usuario actual
                cout << endl;
                usuario.mostrarMaterialesPrestados();
                break;
            }
            case 6: { // Prestar material al usuario actual
                string titulo;
                cout << "Ingrese el titulo del material que solicita prestamo: ";
                cin.ignore();
                getline(cin, titulo);

                MaterialBibliografico* material = biblioteca.buscarMaterial("titulo", titulo);

                if (material && !material->getPrestado()) {
                    if (usuario.prestarMaterial(material)) {
                        cout << "Material prestado con exito.\n";
                        cout << endl;
                        // Verificar si es un libro o una revista y guardar los cambios
                        if (Libro* libro = dynamic_cast<Libro*>(material)) {
                            vector<Libro*> libros = biblioteca.getLibros();
                            lectora.guardarLibros(libros);  // Actualizar libros.txt
                        } else if (Revista* revista = dynamic_cast<Revista*>(material)) {
                            vector<Revista*> revistas = biblioteca.getRevistas();
                            lectora.guardarRevistas(revistas);  // Actualizar revistas.txt
                        }

                    } else {
                        cout << "No se pudo prestar el material. El usuario ya tiene 5 materiales prestados.\n";
                        cout << endl;
                    }
                } else {
                    cout << "El material no se encuentra disponible o ya esta prestado.\n";
                    cout << endl;
                }
                break;
            }
           case 7: {
                cout << "Materiales actualmente prestados a " << usuario.getNombre() << ":\n";
                usuario.mostrarMaterialesPrestados();

                // Devolver material
                string titulo;
                cout << "Ingrese el titulo del material a devolver: ";
                cin.ignore();
                getline(cin, titulo);

                MaterialBibliografico* material = biblioteca.buscarMaterial("titulo", titulo);
                
                if (material && usuario.devolverMaterial(material)) {
                    cout << "Material devuelto con exito.\n";
                    cout << endl;

                    // Actualizar el archivo correspondiente (libros o revistas)
                    if (Libro* libro = dynamic_cast<Libro*>(material)) {
                        vector<Libro*> libros = biblioteca.getLibros();
                        lectora.guardarLibros(libros);
                    } else if (Revista* revista = dynamic_cast<Revista*>(material)) {
                        vector<Revista*> revistas = biblioteca.getRevistas();
                        lectora.guardarRevistas(revistas);
                    } 
                } else {
                    cout << "No se pudo devolver el material.\n";
                    cout << endl;
                }
                break;
            }
            case 8:
                // Salir
                continuar = false;
                cout << "Saliendo del sistema...\n";
                break;

            default:
                cout << "Opcion no valida, por favor intente de nuevo.\n";
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


#include <iostream>
#include "Lectora.h"

using namespace std;

int main() {
    Lectora lectora;

    vector<Usuario*> usuarios = lectora.leerUsuarios();
    vector<Libro*> libros = lectora.leerLibros();
    vector<Revista*> revistas = lectora.leerRevistas();

    // Imprimir los datos de los usuarios
    cout << "Usuarios leidos desde el archivo:" << endl;
    for (const Usuario* usuario : usuarios) {
        cout << "Nombre: " << usuario->getNombre() << ", ID: " << usuario->getId() << endl;
    }
    cout << "----------" << endl;

    // Imprimir los datos de los libros
    cout << "\nLibros leidos desde el archivo:" << endl;
    for (const Libro* libro : libros) {
        libro->mostrarInfo();  // Asume que hay un método mostrarInfo() en MaterialBibliografico o en la clase derivada Libro
        cout << "----------" << endl;
    }

    // Imprimir los datos de revistas
    cout << "\nRevistas leidas desde el archivo:" << endl;
    for (const Revista* revista : revistas) {
        revista->mostrarInfo();  // Asume que hay un método mostrarInfo() en MaterialBibliografico o en la clase derivada Libro
        cout << "----------" << endl;
    }
    
    // Liberar memoria
    for (Usuario* usuario : usuarios) {delete usuario;}
    for (Libro* libro : libros) {delete libro;}
    for (Revista* revista : revistas) { delete revista; }

    return 0;
}

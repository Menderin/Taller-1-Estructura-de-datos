#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Usuario.h"

using namespace std;

void leer_txt(const string& archivo, vector<Usuario*>& usuarios) {
    ifstream archivoEntrada(archivo);

    if (!archivoEntrada) {
        cerr << "Error al abrir el archivo: " << archivo << std::endl;
        return;
    }

    string linea;
    while (getline(archivoEntrada, linea)) {
        istringstream iss(linea);
        string nombre, id;

        getline(iss, nombre, ',');
        getline(iss, id, ',');

        cout << nombre << endl;
        cout << id << endl;
    }

    archivoEntrada.close();
}



int main(){

    vector<Usuario*> usuarios;

    leer_txt("usuarios.txt",usuarios);

    // Aquí puedes utilizar el vector usuarios

    

    /*
    Libro a("El nombre del viento","978-0-7564-0471-2","Patrick Rothfuss","Y","2007","'El nombre del viento' sigue la historia de Kvothe, un joven prodigio que narra su vida desde su infancia en una troupe de artistas itinerantes hasta su búsqueda de conocimiento y venganza en la universidad mágica.");
    a.mostrarInformacion();
    cout<< "---" << endl;

    Libro b ("El camino de los reyes","978-84-08-13008-0","Brandon Sanderson","Y","2010","'El camino de los reyes' es el primer libro de la serie 'El Archivo de las Tormentas', y sigue las historias entrelazadas de varios personajes en un mundo de magia y guerra, explorando sus destinos y las fuerzas que los moldean.");
    b.mostrarInformacion();
    */

       // No olvides liberar la memoria después de usarla
    for (Usuario* usuario : usuarios) {
        delete usuario;
    }
    return 0; 
}
#include <iostream>
#include "MaterialBibliografico.h"
#include "Libro.h"
#include "Revista.h"
#include "Usuario.h"
#include "Biblioteca.h"

using namespace std;


int main(){

    //Biblioteca biblioteca();
    Libro a("El nombre del viento","978-0-7564-0471-2","Patrick Rothfuss","Y","2007","'El nombre del viento' sigue la historia de Kvothe, un joven prodigio que narra su vida desde su infancia en una troupe de artistas itinerantes hasta su búsqueda de conocimiento y venganza en la universidad mágica.");
    a.mostrarInformacion();
    cout<< "---" << endl;

    Libro b ("El camino de los reyes","978-84-08-13008-0","Brandon Sanderson","Y","2010","'El camino de los reyes' es el primer libro de la serie 'El Archivo de las Tormentas', y sigue las historias entrelazadas de varios personajes en un mundo de magia y guerra, explorando sus destinos y las fuerzas que los moldean.");
    b.mostrarInformacion();
    return 0; 
}
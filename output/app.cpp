#include <iostream>
#include "MaterialBibliografico.h"
#include "Libro.h"
#include "Revista.h"
#include "Usuario.h"
#include "Biblioteca.h"
using namespace std;


using namespace std;


int main(){

    //Biblioteca biblioteca();
    Libro a("El nombre del viento", "Patrick Rothfuss", "DAW Books", "978-0-7564-0471-2", "1ra edición", "2007");
    a.mostrarInformacion();
    return 0; 
}
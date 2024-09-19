#include <string>
#include <vector>
#include "Usuario.h"
#include "Libro.h"
#include "Revista.h"

using namespace std;

class Lectora {
public:
    Lectora();
    ~Lectora();

    // Métodos para leer archivos específicos
    vector<Usuario*> leerUsuarios() const;
    vector<Libro*> leerLibros() const;
    vector<Revista*> leerRevistas() const;

private:
    // Nombres de los archivos
    const string archivoUsuarios = "usuarios.txt";
    const string archivoLibros = "libros.txt";
    const string archivoRevistas = "revistas.txt";

    // Método común para leer archivos y devolver su contenido como un vector de strings
    vector<string> leerArchivo(const string& nombreArchivo) const;
};
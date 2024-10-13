#include "Biblioteca.h"

Biblioteca::Biblioteca() : cantidadMateriales(0) {
    // Inicializamos el array con punteros nulos
    for (int i = 0; i < 100; ++i) {
        recursos[i] = nullptr;
    }
}

Biblioteca::~Biblioteca() {
    // Liberamos la memoria de los materiales almacenados
    for (int i = 0; i < cantidadMateriales; ++i) {
        delete recursos[i];
    }
}

bool Biblioteca::agregarMaterial(MaterialBibliografico* material) {
    // Verificar si hay espacio en el array
    if (cantidadMateriales >= 100) {
        std::cerr << "La biblioteca está llena, no se puede agregar más recursos.\n";
        return false;
    }

    // Si el material ya está prestado a alguien, asegúrate de agregarlo al usuario correcto
    if (material->getPrestado() && material->getUsuarioPrestado() != nullptr) {
        material->getUsuarioPrestado()->prestarMaterial(material);
    }

    // Agregar el material al array y aumentar el contador
    recursos[cantidadMateriales++] = material;
    
    return true;
}



void Biblioteca::mostrarMateriales() const {
    // Verificar si hay materiales en la biblioteca
    if (cantidadMateriales == 0) {
        std::cout << "No hay Recursos en la biblioteca.\n";
        return;
    }

    // Mostrar la información de todos los materiales
    std::cout << "Recursos en la biblioteca:\n";
    cout<<endl;
    for (int i = 0; i < cantidadMateriales; ++i) {
        recursos[i]->mostrarInfo();
        std::cout << "-----------------\n";
    }
}
MaterialBibliografico* Biblioteca::buscarMaterial(const std::string& criterio, const std::string& valor) const {
    for (int i = 0; i < cantidadMateriales; ++i) {
        
        if (criterio == "titulo" && recursos[i]->getNombre() == valor) {
            return recursos[i];  // Se encontró el material por título
        }
        if (criterio == "autor" && recursos[i]->getAutor() == valor) {
            return recursos[i];  // Se encontró el material por autor
        }
    }
    return nullptr;  // No se encontró ningún material que coincida
}

vector<Revista*> Biblioteca::getRevistas() const {
    vector<Revista*> revistas;
    for (int i = 0; i < cantidadMateriales; ++i) {
        Revista* revista = dynamic_cast<Revista*>(recursos[i]);
        if (revista != nullptr) {
            revistas.push_back(revista);
        }
    }
    return revistas;
}

#include "Biblioteca.h"
#include "Libro.h"
#include <vector>

// Método para obtener todos los libros
std::vector<Libro*> Biblioteca::getLibros() const {
    std::vector<Libro*> libros;  // Crear un vector de punteros a libros
    for (int i = 0; i < cantidadMateriales; ++i) {
        // Verificar si el material es de tipo Libro
        Libro* libro = dynamic_cast<Libro*>(recursos[i]);
        if (libro != nullptr) {
            libros.push_back(libro);  // Agregar el libro al vector
        }
    }
    return libros;  // Devolver el vector con los libros
}
// Obtener la cantidad de materiales en la biblioteca
int Biblioteca::getCantidadMateriales() const {
    return cantidadMateriales;
}

// Obtener un material en una posición específica del array
MaterialBibliografico* Biblioteca::getMaterial(int indice) const {
    if (indice >= 0 && indice < cantidadMateriales) {
        return recursos[indice];
    }
    return nullptr;  // Si el índice está fuera de rango, devuelve nullptr
}

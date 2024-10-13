# Taller 1 Estructura de datos
  Taller1

Integrantes: 
Nombre: Víctor Fabianno Jopia Santander; Rut: 21.719.697.3; Correo: victor.jopia01@alumnos.ucn.cl; Paralelo: C2
Nombre: Kevin Joab Silva Ossandón; Rut: 18.923.929-7; Correo: kevin.silva@alumnos.ucn.cl; Paralelo: C1

Para iniciar el programa: 

g++ output/app.cpp output/Biblioteca.cpp output/Lectora.cpp output/Libro.cpp output/MaterialBibliografico.cpp output/Revista.cpp output/Usuario.cpp -o app

//Entrar a la carpeta output donde se encuentra el programa

cd /output/ 

y luego 

.\app.exe para iniciar

Explicación del main:

En la linea 22 se declara una instancia de la clase Lectora llamada lectora

En la linea 23 se declara una instancia de la clase Biblioteca llamada biblioteca

En la linea 25, 26, 27 se crean vectores (con punteros) para guardar los usuarios, los libros y las revistas, a su vez se llama a lectora que leera los usuarios, libros y revistas

En la linea 29 se recorre el vector de libros para añadirlos al array estatico de recursos usando un metodo de biblioteca

En la linea 33 se recorre el vector de revistas para añadirlos al array estatico de recursos usando un metodo de biblioteca

Existen 4 usuarios en el archivo de usuarios txt, para ingresar al programa es necesario el nombre e id

como referencia para ingresar puede usar cualquiera de estos 4:

nombre,id

admin,0000
kevin,123
victor,321
juan,1234

En la linea 37 se inicia como tal el programa y llama al metodo menuUsusarios con los parametros usuarios, lectora, biblioteca, este menu permite acceder al menu biblioteca, buscar, crear y eliminar usuarios ademas de finalizar el programa. 

En caso de ingresar un usuario correcto, se accede a la biblioteca en la cual se pueden hacer 8 acciones, 1.-Agregar un libro, 2.-Agregar una revista, 3.-Buscar un material, 4.-Mostrar todos los materiales de la biblioteca, 5.-Mostrar los materiales que han sido prestados al usuario actual, 6.-Solicitar prestamo de material, 7.-Devolver material y 8.-Salir

Explicación de funciones:

1.-Agregar un libro

Solicita los datos por teclado, crea el libro y lo añade un nuevo libro al array de recursos.

2.-Argegar una revista

Solicita los datos por teclado y añade una nueva revista al array de recursos.

3.-Buscar un material

Busca un material por titulo o autor y recorre todo el array nombrando toda las concidencias (por autor o titulo) y mostrando información detallada del material.

4.-Mostrar todos los materiales de la biblioteca

Recorre de manera linea el array de materiales y muestra información detallada de cada recurso. 

5.-Mostrar los materiales que han sido prestados al usuario actual 

Accede al array del usuario actual y enumera los materiales prestados que tiene el usuario.

6.-Solicitar prestamo de material

Solicita el prestamo de un material usando su titulo, luego se busca en el array y en caso de encontrarlo y no estar prestado a otro usuario se agrega al array del usuario actual.

7.-Devolver material

Busca un material por su titulo, luego recorre el array personal del usuario de materialesprestados y en caso de encontrarlo se elimina del array y vuelve a estar disponible para que otro usuario lo pida prestado.

8.-Salir

Cierra sesion en el usuario actual (cerrar menu de la biblioteca) y vuelve al menu de usuarios en caso de que otro usuario quiera entrar.

En las lineas 40, 41 y 42 se eliminan los punteros y se libera la memoria. 
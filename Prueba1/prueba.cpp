#include "prueba.h"
#include <iostream>
using namespace std;
//contructor
prueba::prueba(string a):texto(a){};

void prueba:: getTexto(){
    cout<<"EYEYEYE el texto ingresado es: "<<texto<<"."<<endl;
}
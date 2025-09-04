#include <iostream>
#include <cstring>
#include "funciones.h"
#include "clsContador.h"
#include "clsAlumno.h"

using namespace std;

/**
DESARROLLAR UNA CLASE Fecha, QUE PERMITA TRABAJAR CON LAS
SIGUIENTES PROPIEDADES:
-DIA, MES, AÑO.
AGREGAR LOS SETTERS y GETTERS CORRESPONDIENTES.
LOS OBJETOS DE FECHA DEBEN ESTABLECER VALORES A LAS PROPIEDADES
<<AL MOMENTO DE SER DECLARADOS>>. SI SE LES ENVIA VALORES,
<<DEBE UTILIZAR LOS RECIBIDOS>>, EN CASO CONTRARIO DEBE
INICIALIZARLAS EN 01/01/1900.
*/

void funcionAlPepe(){
    Contador obj;
}

int main(){
    setlocale(LC_ALL, "spanish");
    Alumno alu;
    alu.Cargar();
    alu.Mostrar();
    return 0;
    Contador obj;
    //obj.establecerValorInicial(5);
    obj.Mostrar();
    obj.incrementar();
    obj.incrementar();
    obj.incrementar(5);
    obj.Mostrar();
    funcionAlPepe();
    obj.decrementar();
    obj.decrementar();
    obj.decrementar();
    obj.decrementar();
    obj.decrementar();
    obj.Mostrar();
    obj.reiniciar();
    obj.Mostrar();
    return 0;
    menu();
    return 0;
}

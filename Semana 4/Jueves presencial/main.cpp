#include <iostream>
#include <cstring>
#include "funciones.h"
#include "clsContador.h"
#include "clsAlumno.h"

using namespace std;

/**
DESARROLLAR UNA CLASE Fecha, QUE PERMITA TRABAJAR CON LAS
SIGUIENTES PROPIEDADES:
-DIA, MES, A�O.
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
    FILE *p;
    p = fopen("Alumnos.dat", "rb");///new
    /**
    fopen es una funci�n que crea un v�nculo entre mi programa
    y el archivo. Este v�nculo se guarda en el puntero FILE.
    Los modos de apertura son:
    -rb: Abre el archivo en modo lectura. NO crea archivos.
    -ab: Abre el archivo en modo escritura. Si no existe, lo crea.
        Siempre escribe al final del archivo.
    -wb: Abre el archivo en modo escritura. SIEMPRE crea un archivo
        vac�o.
    */
    if(p == nullptr){
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        return -1;
    }
    ///USO EL ARCHIVO
    Alumno alu;
    fread(&alu, sizeof (Alumno), 1, p);
    /**
    fread copia de mi archivo la cantidad de bytes que surge de
    multiplicar el segundo y el tercer par�metro entre si y lo
    guarda en la direcci�n de memoria del primer par�metro.
    -El primer par�metro es la direcci�n de memoria donde
    quiero copiar la informaci�n.
    -El segundo es el tama�o de UN registro.
    -El tercero es la cantidad de registros que quiero leer
    -El cuarto es el v�nculo con el archivo (puntero FILE).
    */
    fclose(p); ///delete[] p;
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

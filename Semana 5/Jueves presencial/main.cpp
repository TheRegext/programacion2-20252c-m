#include <iostream>
#include <cstring>
#include "funciones.h"
#include "cargarCadena.h"
#include "clsContador.h"
#include "clsAlumno.h"
#include "clsArchivoAlumnos.h"

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

/**
HACER UN PROGRAMA CON UN MENU QUE TENGA LAS SIGUIENTES OPCIONES:
-AGREGAR UN ALUMNO.
-LISTAR TODOS LOS ALUMNOS.
CADA OPCION DEL MENU DEBE LLAMAR A UNA FUNCION (NO HACER TODO EN EL
                                                MAIN)
PUEDE USARSE MAS DE UNA FUNCION PARA CARGAR Y/O MOSTRAR. TRATAR DE
HACERLO LO MAS MODULAR POSIBLE.
*/

void agregarAlumno(){
    Alumno obj;
    ArchivoAlumnos arc;
    obj.Cargar();
    arc.grabarRegistro(obj);
}

void listarAlumnos(){
    ArchivoAlumnos arc;
    arc.listar();
}

void buscarPorLegajo(){
    cout<<"INGRESE EL LEGAJO DEL ALUMNO: ";
    int legajo;
    cin>>legajo;
    ArchivoAlumnos arc;
    int pos = arc.buscarRegistro(legajo);
    if(pos < 0){
        cout<<"NO EXISTE ESE LEGAJO EN EL ARCHIVO"<<endl;
        return;
    }
    Alumno obj = arc.leerRegistro(pos);
    if(obj.getLegajo()<0){
        cout<<"NO EXISTE ESA POSICION EN EL ARCHIVO"<<endl;
        return;
    }
    obj.Mostrar();
}

void listarPorApellido(){
    cout<<"INGRESE EL APELLIDO: ";
    char apellido[30];
    cargarCadena(apellido, 29);
    ArchivoAlumnos arc;
    int cantReg = arc.contarRegistros();
    bool bandera = false;
    for(int i=0; i<cantReg; i++){
        Alumno obj = arc.leerRegistro(i);
        if(strcmp(apellido, obj.getApellido())==0){
            obj.Mostrar();
            bandera = true;
        }
    }
    if(bandera==false){
        cout<<"NO HAY ALUMNOS CON ESE APELLIDO"<<endl;
    }
}

void listarPorPosicion(){
    cout<<"INGRESE LA POSICION DEL REGISTRO: ";
    int posicion;
    cin>>posicion;
    ArchivoAlumnos arc;
    Alumno obj = arc.leerRegistro(posicion);
    if(obj.getLegajo()<0){
        cout<<"NO HAY UN REGISTRO EN ESA POSICION"<<endl;
        return;
    }
    obj.Mostrar();
}

/**
AGREGAR UNA OPCION QUE PIDA EL INGRESO DE UNA POSICION EN EL ARCHIVO Y MUESTRE EL
REGISTRO DE ESA POSICION.
*/

int main(){
    setlocale(LC_ALL, "spanish");
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"===================="<<endl;
        cout<<"1-AGREGAR UN ALUMNO"<<endl;
        cout<<"2-LISTAR ALUMNOS"<<endl;
        cout<<"3-BUSCAR ALUMNO POR LEGAJO"<<endl;
        cout<<"4-LISTAR POR APELLIDO"<<endl;
        cout<<"5-MOSTRAR REGISTRO POR POSICION"<<endl;
        cout<<"0-SALIR"<<endl;
        cout<<"===================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
        case 1:
            agregarAlumno();
            break;
        case 2:
            listarAlumnos();
            break;
        case 3:
            buscarPorLegajo();
            break;
        case 4:
            listarPorApellido();
            break;
        case 5:
            listarPorPosicion();
            break;
        case 0:
            return 0;
        }
        system("pause");
    }
}

//int main(){
//    setlocale(LC_ALL, "spanish");
//    FILE *p;
//    p = fopen("Alumnos.dat", "rb");///new
//    /**
//    fopen es una función que crea un vínculo entre mi programa
//    y el archivo. Este vínculo se guarda en el puntero FILE.
//    Los modos de apertura son:
//    -rb: Abre el archivo en modo lectura. NO crea archivos.
//    -ab: Abre el archivo en modo escritura. Si no existe, lo crea.
//        Siempre escribe al final del archivo.
//    -wb: Abre el archivo en modo escritura. SIEMPRE crea un archivo
//        vacío.
//    */
//    if(p == nullptr){
//        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
//        return -1;
//    }
//    ///USO EL ARCHIVO
//    Alumno alu;
//    while(fread(&alu, sizeof (Alumno), 1, p) == 1){
//        alu.Mostrar();
//        cout<<endl;
//    }
////    fread(alu, sizeof (Alumno), 2, p);
////    alu[0].Mostrar();
////    cout<<endl;
////    alu[1].Mostrar();
////    cout<<endl;
////    fread(alu, sizeof (Alumno), 2, p);
////    alu[0].Mostrar();
////    cout<<endl;
////    alu[1].Mostrar();
////    cout<<endl;
//    /**
//    fread copia de mi archivo la cantidad de bytes que surge de
//    multiplicar el segundo y el tercer parámetro entre si y lo
//    guarda en la dirección de memoria del primer parámetro.
//    -El primer parámetro es la dirección de memoria donde
//    quiero copiar la información.
//    -El segundo es el tamaño de UN registro.
//    -El tercero es la cantidad de registros que quiero leer
//    -El cuarto es el vínculo con el archivo (puntero FILE).
//    Lee hasta el end of file (eof). Si estoy en el eof, no lee nada
//    y no modifica la información de la memoria.
//    */
//    ///alu.Cargar();
//    ///fwrite(&alu, sizeof(Alumno), 1, p);
//    /**
//    fwrite copia de la dirección de memoria del primer parámetro
//    la cantidad de bytes que surge de multiplicar el segundo
//    y el tercer parámetro entre si y lo guarda en el archivo.
//    -El primer parámetro es la dirección de memoria desde donde
//    quiero copiar la información.
//    -El segundo es el tamaño de UN registro.
//    -El tercero es la cantidad de registros que quiero guardar
//    -El cuarto es el vínculo con el archivo (puntero FILE).
//    */
//    fclose(p); ///delete[] p;
//    return 0;
//    Contador obj;
//    //obj.establecerValorInicial(5);
//    obj.Mostrar();
//    obj.incrementar();
//    obj.incrementar();
//    obj.incrementar(5);
//    obj.Mostrar();
//    funcionAlPepe();
//    obj.decrementar();
//    obj.decrementar();
//    obj.decrementar();
//    obj.decrementar();
//    obj.decrementar();
//    obj.Mostrar();
//    obj.reiniciar();
//    obj.Mostrar();
//    return 0;
//    menu();
//    return 0;
//}

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

/**
HACER UN PROGRAMA CON UN MENU QUE TENGA LAS SIGUIENTES OPCIONES:
-AGREGAR UN ALUMNO.
-LISTAR TODOS LOS ALUMNOS.
CADA OPCION DEL MENU DEBE LLAMAR A UNA FUNCION (NO HACER TODO EN EL
                                                MAIN)
PUEDE USARSE MAS DE UNA FUNCION PARA CARGAR Y/O MOSTRAR. TRATAR DE
HACERLO LO MAS MODULAR POSIBLE.
*/

bool grabarRegistro(Alumno obj){
    FILE *p;
    p = fopen("alumnos.dat", "ab");
    if(p==nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

void agregarAlumno(){
    Alumno obj;
    obj.Cargar();
    grabarRegistro(obj);
}

void listarAlumnos(){
    FILE *p;
    p=fopen("alumnos.dat","rb");
    if(p == nullptr){
        return;
    }
    Alumno obj;
    while(fread(&obj, sizeof obj, 1, p)){
        obj.Mostrar();
        cout<<endl;
    }
    fclose(p);
}

/**
AGREGAR UNA OPCION AL MENU QUE SE LLAME "BUSCAR REGISTRO POR LEGAJO", QUE
PIDA UN LEGAJO AL USUARIO Y MUESTRE AL ALUMNO QUE TIENE ESE LEGAJO.
PENSAR QUE FUNCIONES ME CONVIENE HACER.
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

#include <iostream>
#include <cstring>
#include "clsArchivoAlumnos.h"

using namespace std;

ArchivoAlumnos::ArchivoAlumnos(const char *n){
    strcpy(nombre, n);
}
int ArchivoAlumnos::contarRegistros(){
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p, 0, 2);
    /**
    fseek nos permite desplazarnos una cantidad de bytes determinada (segundo
    parámetro), desde un origen determinado (tercer parámetro).
    El valor del origen puede ser:
    0 o SEEK_SET: desde el principio del archivo.
    1 o SEEK_CUR: desde la posición actual (el desplazamiento que haya hecho
                                             hasta el momento).
    2 o SEEK_END: desde el eof (final del archivo).
    SIEMPRE nos conviene desplazarnos una cantidad múltiplo del tamaño de un
    registro. En caso contrario, quedaríamos a mitad (no necesariamente justo
    la mitad) de un registro.
    */
    int bytes = ftell(p);
    /**
    ftell recibe como parámetro el vínculo con el archivo (FILE *) y devuelve
    el desplazamiento actual desde el principio del archivo.
    (sería la cantidad de bytes que hay desde el principio hasta donde
     estoy parado).
    */
    fclose(p);
    return bytes/sizeof(Alumno);
}
int ArchivoAlumnos::buscarRegistro(int legajo){
    Alumno obj;
    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++){
        obj = leerRegistro(i);
        if(obj.getLegajo() == legajo){
            return i;
        }
    }
    return -1;
}
Alumno ArchivoAlumnos::leerRegistro(int pos){
    FILE *p = fopen(nombre, "rb");
    Alumno obj;
    if(p == nullptr){
        obj.setLegajo(-1);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    obj.setLegajo(-2);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}
bool ArchivoAlumnos::grabarRegistro(Alumno obj){
    FILE *p = fopen(nombre, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}
bool ArchivoAlumnos::modificarRegistro(Alumno obj, int pos){
    FILE *p = fopen(nombre, "rb+");
    if(p == nullptr){
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}
void ArchivoAlumnos::listar(){
    Alumno obj;
    int cantReg=contarRegistros();
    for(int i=0; i<cantReg; i++){
        obj = leerRegistro(i);
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }
}

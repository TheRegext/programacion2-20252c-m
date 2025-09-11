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
    Alumno obj;
    int cont = 0;
    while(fread(&obj, sizeof obj, 1, p)){
        cont++;
    }
    fclose(p);
    return cont;
}
int ArchivoAlumnos::buscarRegistro(int legajo){
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    Alumno obj;
    int cont = 0;
    while(fread(&obj, sizeof obj, 1, p)){
        if(obj.getLegajo() == legajo){
            fclose(p);
            return cont;
        }
        cont++;
    }
    fclose(p);
    return -2;
}
Alumno ArchivoAlumnos::leerRegistro(int pos){
    FILE *p = fopen(nombre, "rb");
    Alumno obj;
    obj.setLegajo(-1);
    if(p == nullptr){
        return obj;
    }
    int cont = 0;
    while(fread(&obj, sizeof obj, 1, p)){
        if(cont == pos){
            fclose(p);
            return obj;
        }
        cont++;
    }
    fclose(p);
    obj.setLegajo(-2);
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
void ArchivoAlumnos::listar(){
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

#include <iostream>
#include <cstring>
#include "funciones.h"
#include "clsAlumno.h"
#include "tipos.h"
#include "clsContador.h"

using namespace std;

void menu(){
    Materia vReg[20];
    Alumno aux;
    aux.Cargar();
    aux.Mostrar();
    return;
    while(true){
        int opc;
        system("cls");
        cout<<"SYSACAD UTN FRGP"<<endl;
        cout<<"==================="<<endl;
        cout<<"1 - CARGAR MATERIAS"<<endl;
        cout<<"2 - MOSTRAR MATERIAS"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"==================="<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                cargarMaterias(vReg);
                break;
            case 2:
                mostrarMaterias(vReg);
                break;
            case 0:
                return;
        }
        system("pause");
    }
}

void cargarMaterias(Materia *vM){
    for(int i=0; i<20; i++){
        int aux;
        cout<<"INGRESO NUMERO: "<<i+1<<endl;
        cout<<"INGRESE EL NUMERO DE LA MATERIA: ";
        cin>>aux;///5
        vM[i].setNumero(aux);///5
        cout<<"INGRESE EL NOMBRE DE LA MATERIA: ";
        cin.ignore();
        char nombre[50];
        cin.getline(nombre,50);
        vM[i].setNombre(nombre);
        cout<<"INGRESE LA CANTIDAD DE PARCIALES: ";
        cin>>aux;
        vM[i].setCantidadParciales(aux);
        cout<<"INGRESE LA CANTIDAD DE ALUMNOS: ";
        cin>>aux;
        vM[i].setCantidadAlumnos(aux);
        cout<<"INGRESE LA CANTIDAD DE DOCENTES: ";
        cin>>aux;
        vM[i].setCantidadDocentes(aux);
    }
}
void mostrarMaterias(Materia *vM){
    for(int i=0; i<20; i++){
        cout<<"======================================="<<endl;
        cout<<"NUMERO DE LA MATERIA: "<<vM[i].getNumero()<<endl;
        cout<<"NOMBRE DE LA MATERIA: "<<vM[i].getNombre()<<endl;
        cout<<"CANTIDAD DE PARCIALES: "<<vM[i].getCantidadParciales()<<endl;
        cout<<"INGRESE LA CANTIDAD DE ALUMNOS: "<<vM[i].getCantidadAlumnos()<<endl;
        cout<<"INGRESE LA CANTIDAD DE DOCENTES: "<<vM[i].getCantidadDocentes()<<endl;
        cout<<"======================================="<<endl;
    }
}

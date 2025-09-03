#include <iostream>
#include <cstring>
#include "cargarCadena.h"
#include "clsAlumno.h"

using namespace std;

Alumno::Alumno(int leg, const char *nom, const char *ape, int d, Fecha fN, Fecha fI, const char *e){
    legajo = leg;
    strcpy(nombre, nom);
    strcpy(apellido, ape);
    dni = d;
    fechaNacimiento = fN;
    fechaInscripcion = fI;
    strcpy(email, e);
}

///SETTERS
void Alumno::setLegajo(int leg){
    legajo = leg;
}
void Alumno::setNombre(const char *nom){
    strcpy(nombre, nom);
}
void Alumno::setApellido(const char *ape){
    strcpy(apellido, ape);
}
void Alumno::setDni(int d){
    dni = d;
}
void Alumno::setFechaNacimiento(Fecha fN){
    fechaNacimiento = fN;
}
void Alumno::setEmail(const char *mail){
    strcpy(email, mail);
}
///GETTERS
int Alumno::getLegajo(){
    return legajo;
}
const char *Alumno::getNombre(){
    return nombre;
}
const char *Alumno::getApellido(){
    return apellido;
}
int Alumno::getDni(){
    return dni;
}
Fecha Alumno::getFechaNacimiento(){
    return fechaNacimiento;
}
const char *Alumno::getEmail(){
    return email;
}
///OTROS METODOS
void Alumno::Cargar(){
    cout<<"INGRESE EL LEGAJO: ";
    cin>>legajo;
    cout<<"INGRESE EL NOMBRE DEL ALUMNO: ";
    cargarCadena(nombre, 29);
    cout<<"INGRESE EL APELLIDO DEL ALUMNO: ";
    cargarCadena(apellido,29);
    cout<<"INGRESE EL DNI: ";
    cin>>dni;
    cout<<"INGRESE LA FECHA DE NACIMIENTO: "<<endl;
    fechaNacimiento.Cargar();
    cout<<"INGRESE LA FECHA DE INSCRIPCION: "<<endl;
    fechaInscripcion.Cargar();
    cout<<"INGRESE EL DOMICILIO: "<<endl;
    domicilio.Cargar();
    cout<<"INGRESE EL EMAIL: ";
    cargarCadena(email, 29);
}
void Alumno::Mostrar(){
    cout<<"LEGAJO: "<<legajo<<endl;
    cout<<"NOMBRE DEL ALUMNO: "<<nombre<<endl;
    cout<<"APELLIDO DEL ALUMNO: "<<apellido<<endl;
    cout<<"DNI: "<<dni<<endl;
    cout<<"FECHA DE NACIMIENTO: ";
    fechaNacimiento.Mostrar();
    cout<<"FECHA DE INSCRIPCION: ";
    fechaInscripcion.Mostrar();
    cout<<"DOMICILIO: "<<endl;
    domicilio.Mostrar();
    cout<<"INGRESE EL EMAIL: "<<email<<endl;
}

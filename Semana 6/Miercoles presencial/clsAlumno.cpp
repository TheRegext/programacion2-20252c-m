#include <iostream>
#include <cstring>
#include "cargarCadena.h"
#include "clsAlumno.h"

using namespace std;

Persona::Persona(const char *nom, const char *ape, int d, Fecha fN, const char *e){
    strcpy(nombre, nom);
    strcpy(apellido, ape);
    dni = d;
    fechaNacimiento = fN;
    strcpy(email, e);
}

Alumno::Alumno(int leg, Fecha fI): Persona("S/N", "S/A", 0, Fecha(), "S/E"){
    legajo = leg;
    fechaInscripcion = fI;
}

///SETTERS
void Alumno::setLegajo(int leg){
    legajo = leg;
}
void Alumno::setFechaInscripcion(Fecha fI){
    fechaInscripcion = fI;
}
void Alumno::setEstado(bool e){
    estado = e;
}
void Persona::setNombre(const char *nom){
    strcpy(nombre, nom);
}
void Persona::setApellido(const char *ape){
    strcpy(apellido, ape);
}
void Persona::setDni(int d){
    dni = d;
}
void Persona::setFechaNacimiento(Fecha fN){
    fechaNacimiento = fN;
}
void Persona::setDomicilio(Domicilio d){
    domicilio = d;
}
void Persona::setEmail(const char *mail){
    strcpy(email, mail);
}
///GETTERS
int Alumno::getLegajo(){
    return legajo;
}
bool Alumno::getEstado(){
    return estado;
}
const char *Persona::getNombre(){
    return nombre;
}
const char *Persona::getApellido(){
    return apellido;
}
int Persona::getDni(){
    return dni;
}
Fecha Persona::getFechaNacimiento(){
    return fechaNacimiento;
}
Domicilio Persona::getDomicilio(){
    return domicilio;
}
const char *Persona::getEmail(){
    return email;
}
///OTROS METODOS

void Persona::Cargar(){
    cout<<"INGRESE EL NOMBRE DEL ALUMNO: ";
    char nomAux[30];
    cargarCadena(nomAux, 29);
    setNombre(nomAux);
    cout<<"INGRESE EL APELLIDO DEL ALUMNO: ";
    cargarCadena(apellido,29);
    cout<<"INGRESE EL DNI: ";
    cin>>dni;
    cout<<"INGRESE LA FECHA DE NACIMIENTO: "<<endl;
    fechaNacimiento.Cargar();
    cout<<"INGRESE EL DOMICILIO: "<<endl;
    domicilio.Cargar();
    cout<<"INGRESE EL EMAIL: ";
    cargarCadena(email, 29);
}
void Alumno::Cargar(int l){
    if(l==-999){
        cout<<"INGRESE EL LEGAJO: ";
        cin>>legajo;
    }else{
        legajo = l;
    }
    Persona::Cargar();
    cout<<"INGRESE LA FECHA DE INSCRIPCION: "<<endl;
    fechaInscripcion.Cargar();
    estado=true;
}
void Persona::Mostrar(){
    cout<<"NOMBRE DEL ALUMNO: "<<nombre<<endl;
    cout<<"APELLIDO DEL ALUMNO: "<<apellido<<endl;
    cout<<"DNI: "<<dni<<endl;
    cout<<"FECHA DE NACIMIENTO: ";
    fechaNacimiento.Mostrar();
    cout<<"DOMICILIO: "<<endl;
    domicilio.Mostrar();
    cout<<"INGRESE EL EMAIL: "<<email<<endl;
}
void Alumno::Mostrar(){
    cout<<"LEGAJO: "<<legajo<<endl;
    Persona::Mostrar();
    cout<<"FECHA DE INSCRIPCION: ";
    fechaInscripcion.Mostrar();
}

#include <iostream>
#include <cstring>
#include "cargarCadena.h"
#include "clsAlumno.h"

using namespace std;

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
void Alumno::setDiaNacimiento(int dia){
    diaNacimiento = dia;
}
void Alumno::setMesNacimiento(int mes){
    mesNacimiento = mes;
}
void Alumno::setAnioNacimiento(int anio){
    anioNacimiento = anio;
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
int Alumno::getDiaNacimiento(){
    return diaNacimiento;
}
int Alumno::getMesNacimiento(){
    return mesNacimiento;
}
int Alumno::getAnioNacimiento(){
    return anioNacimiento;
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
    cout<<"INGRESE EL DIA DE NACIMIENTO: ";
    cin>>diaNacimiento;
    cout<<"INGRESE EL MES DE NACIMIENTO: ";
    cin>>mesNacimiento;
    cout<<"INGRESE EL AÑO DE NACIMIENTO: ";
    cin>>anioNacimiento;
    cout<<"INGRESE EL EMAIL: ";
    cargarCadena(email, 29);
}
void Alumno::Mostrar(){
    cout<<"LEGAJO: "<<legajo<<endl;
    cout<<"NOMBRE DEL ALUMNO: "<<nombre<<endl;
    cout<<"APELLIDO DEL ALUMNO: "<<apellido<<endl;
    cout<<"DNI: "<<dni<<endl;
    cout<<"FECHA DE NACIMIENTO: "<<diaNacimiento<<"/"<<mesNacimiento<<"/"<<anioNacimiento<<endl;
    cout<<"INGRESE EL EMAIL: "<<email<<endl;
}

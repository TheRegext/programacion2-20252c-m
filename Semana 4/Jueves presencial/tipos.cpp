#include "tipos.h"

void Materia::setNumero(int n){
        numero = n;
}
void Materia::setNombre(const char *n){strcpy(nombre,n);}
void Materia::setCantidadParciales(int cP){cantidadParciales=cP;}
void Materia::setCantidadAlumnos(int cA){cantidadAlumnos=cA;}
void Materia::setCantidadDocentes(int cD){cantidadDocentes=cD;}
int Materia::getNumero(){return numero;}
const char *Materia::getNombre(){return nombre;}
int Materia::getCantidadParciales(){return cantidadParciales;}
int Materia::getCantidadAlumnos(){return cantidadAlumnos;}
int Materia::getCantidadDocentes(){return cantidadDocentes;}

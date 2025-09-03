#include <iostream>
#include "clsFecha.h"

using namespace std;

Fecha::Fecha(int d, int m, int a){
    dia=d;
    mes=m;
    anio=a;
}
void Fecha::setDia(int d){
    dia=d;
}
void Fecha::setMes(int m){
    mes=m;
}
void Fecha::setAnio(int a){
    anio=a;
}
int Fecha::getDia(){
    return dia;
}
int Fecha::getMes(){
    return mes;
}
int Fecha::getAnio(){
    return anio;
}
void Fecha::Cargar(){
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"AÑO: ";
    cin>>anio;
}
void Fecha::Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

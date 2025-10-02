#include <iostream>

using namespace std;

#include "Fecha.h"

Fecha::Fecha(int d, int m, int a){
    dia=d;
    mes=m;
    anio=a;
 }

void Fecha::Cargar(){
        cout<<"DIA ";
        cin>>dia;
        cout<<"MES ";
        cin>>mes;
        cout<<"ANIO ";
        cin>>anio;
    }

void Fecha::Mostrar(){
        /*cout<<"DIA "<<dia<<endl;
        cout<<"MES "<<mes<<endl;
        cout<<"ANIO "<<anio<<endl;*/
        cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    }

int Fecha::getDia(){return dia;}
int Fecha::getMes(){return mes;}
int Fecha::getAnio(){return anio;}

void Fecha::setDia(int a){dia=a;}
void Fecha:: setMes(int a){mes=a;}
void Fecha:: setAnio(int a){anio=a;}

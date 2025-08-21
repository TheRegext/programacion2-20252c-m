#include <iostream>
#include "funciones.h"

using namespace std;

void menu(){
    int *pVec=nullptr;
    int tam;
    while(true){
        int opc;
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"=================="<<endl;
        cout<<"1 - CREAR VECTOR"<<endl;
        cout<<"2 - CARGAR VECTOR"<<endl;
        cout<<"3 - MOSTRAR VECTOR"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"=================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                if(pVec == nullptr){
                    pVec = crearVector(tam);
                }
                break;
            case 2:
                if(pVec != nullptr)cargarVector(pVec, tam);
                break;
            case 3:
                if(pVec != nullptr)mostrarVector(pVec, tam);
                break;
            case 0:
                delete[] pVec;
                return;
        }
        system("pause>nul");
    }
}
int *crearVector(int &tam){
    cout<<"INGRESE LA CANTIDAD DE ELEMENTOS DEL VECTOR: ";
    cin>>tam;
    if(tam<=0){
        cout<<"EL TAMAÑO INGRESADO NO ES VALIDO"<<endl;
        return nullptr;
    }
    int *p = nullptr;
    p = new int[tam];
    if(p == nullptr){
        cout<<"FALLO LA SOLICITUD DE MEMORIA"<<endl;
        return nullptr;
    }
    return p;
}
void cargarVector(int *v, int tam){
    for(int i=0; i<tam; i++){
        v[i]=i+1;
    }
}
void mostrarVector(int *v, int tam){
    for(int i=0; i<tam; i++){
        cout<<v[i]<<endl;
    }
}

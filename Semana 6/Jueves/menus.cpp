#include <iostream>
#include <cstring>
#include "menus.h"

using namespace std;

void menuPrincipal(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"=============="<<endl;
        cout<<"1 - USUARIOS"<<endl;
        cout<<"2 - JUEGOS"<<endl;
        cout<<"3 - ACCESOS"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"=============="<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                menuUsuarios();
                break;
            case 2:
                menuJuegos();
                break;
            case 3:
                menuAccesos();
                break;
            case 0:
                return;
        }
    }
}
void menuUsuarios(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU USUARIOS"<<endl;
        cout<<"=============="<<endl;
        cout<<"1 - AGREGAR USUARIO"<<endl;
        cout<<"2 - DAR DE BAJA USUARIO"<<endl;
        cout<<"3 - MODIFICAR USUARIO"<<endl;
        cout<<"4 - LISTAR USUARIOS"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"=============="<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 0:
                return;
        }
    }
}
void menuJuegos(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU JUEGOS"<<endl;
        cout<<"=============="<<endl;
        cout<<"1 - AGREGAR JUEGO"<<endl;
        cout<<"2 - DAR DE BAJA JUEGO"<<endl;
        cout<<"3 - MODIFICAR JUEGO"<<endl;
        cout<<"4 - LISTAR JUEGOS"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"=============="<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 0:
                return;
        }
    }
}
void menuAccesos(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU ACCESO"<<endl;
        cout<<"=============="<<endl;
        cout<<"1 - AGREGAR ACCESO"<<endl;
        cout<<"2 - DAR DE BAJA ACCESO"<<endl;
        cout<<"3 - MODIFICAR ACCESO"<<endl;
        cout<<"4 - LISTAR ACCESOS"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"=============="<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 0:
                return;
        }
    }
}

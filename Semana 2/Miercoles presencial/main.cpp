#include <iostream>
#include "funciones.h"

using namespace std;

int *funcion(){
    int tam;
    cin>>tam;
    int *pVec=nullptr;///NULL
    ///PIDO MEMORIA
    if(tam<=0){
        cout<<"VALOR INVALIDO DE TAMANIO"<<endl;
        return nullptr;
    }
    pVec=new int[tam];
    if(pVec==nullptr){
        cout<<"NO SE PUDO RESERVAR LA MEMORIA"<<endl;
        return nullptr;
    }
    for(int i=0; i<tam; i++){
        pVec[i]=i+1;
    }
    return pVec;
}

/**
HACER UN PROGRAMA QUE LE SOLICITE AL USUARIO UN TAMAÑO DE VECTOR,
CARGAR LAS POSICIONES DEL MISMO CON VALORES DEL 1 EN ADELANTE Y
LUEGO MOSTRAR EL CONTENIDO DEL VECTOR.

HACER UN PROGRAMA QUE HAGA LO MISMO QUE EL ANTERIOR, PERO CON UN
MENU CON LAS SIGUIENTES OPCIONES.
-PEDIR TAMAÑO Y RESERVAR MEMORIA.
-CARGAR EL VECTOR.
-MOSTRAR EL VECTOR.
BONUS: NO PERMITIR INGRESAR MAS DE UNA VEZ A LA OPCION 1.
*/

int main(){
    int **mat;
    int otraMat[10][10];
    mat = new int*[10];
    for(int i=0; i<10; i++){
        mat[i] = new int[100000000];
    }
    for(int i=0; i<10; i++){
        for(int j=0; j<100000000; j++){
            mat[i][j]=10;
        }
    }
    system("pause");
    for(int i=0; i<10; i++){
        delete[] mat[i];
    }
    delete[] mat;
    system("pause");
    return 0;
    menu();
    return 0;
}

/**int main()
{
    int *pVec;///NULL
    while(true){
        pVec = funcion();
        if(pVec == nullptr){
            return -1;
        }
        delete[] pVec;
        pVec=nullptr;
    }
    return 0;
}
*/

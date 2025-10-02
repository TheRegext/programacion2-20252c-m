#include <iostream>
#include <cstring>

using namespace std;

#include "Fecha.h"
#include "Libro.h"
#include "ArchivoLibro.h"
#include "funciones_globales.h"
#include "menuLibro.h"
#include "menuListados.h"

void menuListados(){
	int opc;
    while(true){
        system("cls");
        cout << "****** LISTADOS ******" << endl;
        cout << "1. LISTAR LIBROS POR AUTOR" << endl;
        cout << "2. LISTAR LIBROS DEL SIGLO XX" << endl;
        cout << "3. LISTAR LIBROS DEL SIGLO XXI (DINAMICO) " << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL " << endl;
        cout << "************************" << endl;
        cout << "SELECCIONAR OPCION " << endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                    break;
            case 2:

                    break;
            case 3: listarSigloXXI();
                    break;
            case 0: return;
                    break;
            default: cout<<"LA SELECCION NO ES CORRECTA"<<endl;

        }
        system("pause");
    }
    return;
}

bool listarPorAutor(){

    return true;
}

bool listarSigloXXI(){
    ///contar los libros que se publicaron con año >=2000
    Libro reg;
    ArchivoLibros archi;
    int cantReg, cantLibrosXXI=0;
    cantReg=archi.contarRegistros();
    for(int i=0;i<cantReg;i++){
        reg=archi.leerRegistro(i);
        if(reg.getEstado()&& reg.getFechaPublicacion().getAnio()>=2000){
            cantLibrosXXI++;
        }
    }
    /// si no hay libros me voy
    if(cantLibrosXXI==0){
            cout<<"NO HAY LIBROS DEL SIGLO XXI"<<endl;
            return true;
    }
    ///pedir memoria para un vector de la cantidad contada
    Libro *vLibros;
    vLibros=new Libro[cantLibrosXXI];
    if(vLibros==nullptr) return false;
    ///copiar los registros que correpondan en el vector
    int pos=0;
    for(int i=0;i<cantReg;i++){
        reg=archi.leerRegistro(i);
        if(reg.getEstado()&& reg.getFechaPublicacion().getAnio()>=2000){
            vLibros[pos]=reg;
            pos++;
        }
    }
    ///mostrar el vector
    for(int i=0;i<cantLibrosXXI;i++){
        vLibros[i].Mostrar();
        cout<<endl;
    }
    ///devolver la memoria
    delete []vLibros;
    return true;
}

bool listarSigloXX(){

    return true;
}

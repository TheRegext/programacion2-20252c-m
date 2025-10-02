#include <iostream>
#include <cstring>

using namespace std;

#include "Fecha.h"
#include "Libro.h"
#include "ArchivoLibro.h"
#include "funciones_globales.h"

int main(){
	int opc;
    while(true){
        system("cls");
        cout << "****** ABML LIBROS ******" << endl;
        cout << "1. ALTA LIBROS" << endl;
        cout << "2. BAJA LIBROS" << endl;
        cout << "3. MODIFICACION STOCK " << endl;
        cout << "4. LISTADO LIBROS " << endl;
        cout << "0. FIN DEL PROGRAMA" << endl;
        cout << "************************" << endl;
        cout << "SELECCIONAR OPCION " << endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: if(altaLibro()) cout<<"REGISTRO AGREGADO "<<endl;
                    else cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
                    break;
            case 2: if(bajaLibro()) cout<<"REGISTRO ELIMINADO "<<endl;
                    else cout<<"NO SE PUDO ELIMINAR EL REGISTRO "<<endl;
                    break;
            case 3: if(modificarStock()) cout<<"STOCK MODIFICADO "<<endl;
                    else cout<<"NO SE PUDO MODIFICAR EL STOCK "<<endl;
                    break;
            case 4: if(!listarLibros()) cout<<"EL ARCHIVO NO TIENE REGISTROS"<<endl;
                    break;
            case 0: return 0;
                    break;
            default: cout<<"LA SELECCION NO ES CORRECTA"<<endl;

        }
        system("pause");
    }
    return 0;
}


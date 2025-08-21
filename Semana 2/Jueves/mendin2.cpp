///Fecha:
///Autor:
///Comentario:

#include <iostream>

using namespace std;

void ponerCeroMatriz(int (*m)[5], int filas, int columnas);
void mostrarMatriz(int (*m)[5], int filas, int columnas);

int main(){

    int (*m)[5], tam;
    delete []m;
    cout<<"INGRESAR CANTIDAD DE FILAS DE LA MATRIZ ";
    cin>>tam;

    m=new int[tam][5];///dirección si todo anduvo bien; nullptr o NULL si no se consiguió memoria
    if(m==nullptr){
        cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
        return -1;
    }

    ponerCeroMatriz(m, tam, 5);
    mostrarMatriz(m, tam, 5);


    int (*otra)[5];
    otra=nullptr;
    otra=m;
    delete []otra;
	system("pause");
	return 0;

}

void ponerCeroMatriz(int (*m)[5], int filas, int columnas){
    int i, j;
    for(i=0;i< filas; i++)
        for(j=0;j<columnas;j++)
            m[i][j]=0;
}


void mostrarMatriz(int (*m)[5], int filas, int columnas){
    int i, j;
    for(i=0;i< filas; i++){

        for(j=0;j<columnas;j++){
            cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }
}


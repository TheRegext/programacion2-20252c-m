///Fecha:
///Autor:
///Comentario:

#include <iostream>

using namespace std;

void ponerCeroMatriz(int **m, int filas, int columnas);
void mostrarMatriz(int **m, int filas, int columnas);

int main(){

    int **m, filas, columnas;
    cout<<"INGRESAR FILAS ";
    cin>>filas;
    cout<<"INGRESAR COLUMNAS ";
    cin>>columnas;

    m=new int *[filas];
    if(m==nullptr)return -1;
    for(int i=0;i<filas;i++){
        m[i]= new int[columnas];
        if(m[i]==nullptr){
            for(int j=0;j<i;j++){
              delete []m[j];
            }
            delete []m;
        }
    }

    ponerCeroMatriz(m, filas, columnas);
    mostrarMatriz(m, filas, columnas);

    for(int j=0;j<filas;j++){
              delete []m[j];
    }
    delete []m;

	system("pause");
	return 0;

}

void ponerCeroMatriz(int **m, int filas, int columnas){
    int i, j;
    for(i=0;i< filas; i++)
        for(j=0;j<columnas;j++)
            m[i][j]=0;
}


void mostrarMatriz(int **m, int filas, int columnas){
    int i, j;
    for(i=0;i< filas; i++){

        for(j=0;j<columnas;j++){
            cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }
}


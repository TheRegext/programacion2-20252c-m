#include <iostream>

using namespace std;

///int (*mat)[3]
///int mat[5][3]
///int mat[][3]

void cargarMatriz(int (*mat)[3],int filas, int columnas);
void mostrarMatriz(int mat[5][3],int filas, int columnas);

///El nombre de una matriz es también un puntero constante
///Pero es un puntero A LA PRIMERA FILA DE UNA MATRIZ con una
///cantidad de columnas definidas

void cargarVector(int *v, int cant){
    int i;
    for(i=0;i<cant;i++){
        v[i]=i+1;
    }
}

int main(){
    const int FILAS=5, COLUMNAS=3;
    int mat[FILAS][COLUMNAS];
//    cargarMatriz(mat,FILAS, COLUMNAS);
    cargarVector(*mat,FILAS*COLUMNAS);
    mostrarMatriz(mat,FILAS, COLUMNAS);
    cout<<endl;


	system("pause");
	return 0;

}


void cargarMatriz(int mat[][3],int filas, int columnas){
    int i, j;
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            mat[i][j]=i+j;
        }
    }
}

void mostrarMatriz(int mat[][3],int filas, int columnas){
    int i, j;
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            cout<<mat[i][j]<<"\t";
        }
        cout<<"\n";///igual que el endl
    }
}

//mat[i][j]=*(*(m+i)+j)

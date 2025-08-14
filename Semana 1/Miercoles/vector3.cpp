#include <iostream>

using namespace std;



void cargarVector(int v[], int cant);/// prototipo o declaración de la función
void mostrarVector(int v[], int cant);
int main(){
    const int TAM=5;
    int vec[TAM];
    cargarVector(vec, TAM);
    mostrarVector(vec, TAM);
    cout<<endl;
	system("pause");
	return 0;

}

void cargarVector(int *v, int cant){
    int i;
    for(i=0;i<cant;i++){
        *(v+i)=i+5;
    }
}

void mostrarVector(int *v, int cant){
    int i;
    for(i=0;i<cant;i++){
        cout<<*(v+i)<<"\t";
    }
}



/*
ARITMETICA DE PUNTEROS
Si a una dirección de memoria le sumamos un valor entero,
esa dirección de memoria se desplaza una cantidad de bytes
equivalente a el resultado de multiplicar el número entero por el tamaño del tipo de datos.

	v=&v[0]
	v+1=&v[0]+1 >&v[1]

	v+1=&v[1]

	v+2=&v[2]

	v+N=&v[N]

	*(v+N)=*&v[N]

	*(v+N)=v[N]
*/

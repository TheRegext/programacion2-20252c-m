#include <iostream>

using namespace std;

///* multiplicar
///int *algo->declarando un puntero
/// *v-> operador de indirecci�n


///& operador de direcci�n &var;
///& al momento de la declaraci�n de una variable int &nombre, para crear una referencia a una variable


void cargarVector(int v[], int cant);/// prototipo o declaraci�n de la funci�n
void mostrarVector(int v[], int cant);
///Hacer una funci�n que devuelva la suma de los valores positivos contenidos en el vector
///Adem�s debe calcular cu�ntos valores positivos est�n contenidos dentro del vector.

int sumarContarPositivos(int *v, int tam, int &cuentaPos){
    int i;
    int sumaPos=0;
    cuentaPos=0;
    for(i=0;i<tam; i++){
        if(v[i]>0){
            sumaPos+=v[i];
            cuentaPos++;
        }
    }
    return sumaPos;
}


int main(){
   // char *pChar;
    const int TAM=5;
    int vec[TAM], totalPositivos;
    /*char letra;
    cout<<sizeof var<<endl;
    cout<<sizeof vec<<endl;
    cout<<sizeof letra<<endl;
    cout<<sizeof(double)<<endl;
    system("pause");*/

    cargarVector(vec, TAM);
    mostrarVector(vec, TAM);
    cout<<endl;
    cout<<"SUMA DE POSITIVOS EN EL VECTOR "<<sumarContarPositivos(vec, TAM, totalPositivos)<<endl;
    cout<<"CANTIDAD DE POSITIVOS "<<totalPositivos;
    cout<<endl;
	system("pause");
	return 0;

}

void cargarVector(int *v, int cant){
    int i;
    for(i=0;i<cant;i++){
        *(v+i)=i-5;
    }
}

void mostrarVector(int *v, int cant){
    int i;
    for(i=0;i<cant;i++){
        cout<<*(v+i)<<"\t";
    }
}




/*ARITMETICA DE PUNTEROS
Si a una direcci�n de memoria le sumamos un valor entero,
esa direcci�n de memoria se desplaza una cantidad de bytes
equivalente a el resultado de multiplicar el n�mero entero por el tama�o del tipo de datos.

	v=&v[0]
	v+1=&v[0]+1 >&v[1]

	v+1=&v[1]

	v+2=&v[2]

	v+N=&v[N]

	*(v+N)=*&v[N]

	*(v+N)=v[N]
*/

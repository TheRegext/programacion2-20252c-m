#include <iostream>

using namespace std;

void cargarVector(int v[], int cant);/// prototipo o declaración de la función
void mostrarVector(int v[], int cant);
///Hacer una función que me devuelva la suma de los valores contenidos en
///en un vector de enteros, y además me permita saber cuántos de esos valores son positivos
///La función no debe informar nada

int sumarContar(int v[], int cant, int &sumaPos);

///El nombre de un vector contiene una dirección de memoria
///Es la dirección de memoria del primer elemento de ese vector
///Las variables que almacenan direcciones se denominan punteros

///El nombre de un vector es un puntero constante que contiene la dirección del primer
///elemento de ese vector

///& antepuesto al nombre de una variable, me da la dirección de esa variable.
///& es el operador de dirección en este contexto

int main(){
    const int TAM=5;
    int vec[TAM] ;///vec[0..4]
    cout<<vec<<endl;
    cout<<&vec[0]<<endl;
    system("pause");
    cargarVector(vec, TAM);
    mostrarVector(vec, TAM);
    cout<<endl;
	system("pause");
	int contPos=0, &refe=contPos;
	///
	vec=&contPos;
	int sumaVector=sumarContar(vec, TAM, contPos);
	cout<<"SUMA DEL VECTOR "<<sumaVector<<endl;
	cout<<"CANTIDAD DE POSITIVOS DEL VECTOR "<<contPos<<endl;
	cout<<endl;
	system("pause");
	return 0;

}

void cargarVector(int v[], int cant){
    int i;
    for(i=0;i<cant;i++){
        v[i]=i+5;
    }
}

void mostrarVector(int v[], int cant){
    int i;
    for(i=0;i<cant;i++){
        cout<<v[i]<<"\t";
    }
}

int sumarContar(int v[], int cant, int &sumaPos){
    int i, suma=0;
    sumaPos=0;
    for(i=0;i<cant;i++){
        suma+=v[i];
        if(v[i]>0){
            sumaPos++;
        }
    }
    return suma;
}

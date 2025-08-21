///Fecha:
///Autor:
///Comentario:

#include <iostream>

using namespace std;

void cargarVector(int *v, int tam);
void mostrarVector(int *v, int tam);

int main(){
    int tam;
    char *vec;
    cout<<"INGRESAR EL TAMANIO DEL VECTOR ";
    cin>>tam;
    vec=new char[tam];
    if(vec==nullptr){///NULL
        cout<<"NO SE PUDO ASIGNAR MEMORIA"<<endl;
        return -1;
    }
    //cargarVector(vec, tam);
    //mostrarVector(vec,tam);
    cin>>vec;
    cout<<vec;
    cout<<endl;
    delete []vec;

	system("pause");
	return 0;

}

void cargarVector(int *v, int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i]=3+i;
    }
}

void mostrarVector(int *v, int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<"\t";
    }
}

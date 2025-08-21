#include <iostream>
using namespace std;

// side effect
/// ocurre cunado una funcion modifica un argunmento 
/// y vos no lo esperabas

void ordenar(int vec[], int cant){
   
   for (int i=0; i < cant - 1; i++){
      for(int j=0; j< cant - 1 - i; j++ ){
         if(vec[j] > vec[j+1]){
            int aux = vec[j];
            vec[j] = vec[j+1];
            vec[j+1] = aux;
         }
      }
   } 
}

void mostrar(int vec[], int cant){
   for(int i=0; i<cant; i++){
      cout << i+1 << " = " << vec[i] << endl;
   }
}

/// side effect
void mostrarOrdenado(int vec[], int cant){
   int *vecAux;
   
   vecAux = new int[cant];
   
   if(vecAux == nullptr){
      cout << "No pude pedir memoria... compa mas en www.masmemoria.depp.web.onion" << endl;
      exit(101);
   }
   
   /// copiamos todos los datos
   for(int i=0; i<cant; i++){
      vecAux[i] = vec[i];
   }
   
   ordenar(vecAux, cant);
   mostrar(vecAux, cant);
   
   /// delete [] vecAux;
}

int main() {
   
   int vector[5] = {2,6,5,4,8};
	
   mostrar(vector, 5);
   cout << "--------" << endl;
   mostrarOrdenado(vector, 5);
   
   cout << vector[1] << endl;
	return 0;
}


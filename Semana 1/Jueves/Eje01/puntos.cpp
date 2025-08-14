#include <iostream>
#include "puntos.h"

using namespace std;

void mostrarCantidadIngresosDeMarzo(string nombresMaterias[20], int pa_cantidadIngresos[20][31]){
 for(int i=0; i<20; i++){
    cout << "Materia " << nombresMaterias[i] << " ------- " << endl;
    for(int j=0; j<31; j++){
      cout << "Dia #" << j+1 <<": " << pa_cantidadIngresos[i][j] << endl; 
    }  
  }
}

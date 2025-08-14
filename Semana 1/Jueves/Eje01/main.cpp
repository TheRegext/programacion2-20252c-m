#include <iostream>
#include "puntos.h"

using namespace std;

int main()
{
  const int PROFESOR = 1;
  const int ALUMNO = 0;

  int numeroMateria, cantidades[20][2];
  string nombresMaterias[20];

  for(int i=1; i<=20; i++)
  {
    cout << "Ingrese el numero de materia: ";
    cin >> numeroMateria;

    cout << "Ingrese el nombre de la materia: ";
    cin >> nombresMaterias[numeroMateria - 1];

    cout << "Ingrese la cantidad de alumnos";
    cin >> cantidades[numeroMateria - 1][ALUMNO];

    cout << "Ingrese la cantidad de profesores";
    cin >> cantidades[numeroMateria - 1][PROFESOR];
  }
  int legajo, dia, mes;
  float cantidadHoras;
  
  int pc_cantidadIngresos[20][31]{};

  cout << "Ingrese legajo: ";
  cin >> legajo;

  while(legajo != 0)
  {
    cout << "Ingrese Mes: ";
    cin >> mes;
    cout <<  "Ingrese dia: ";
    cin >> dia;

    cout << "Ingrese el numero de materia: ";
    cin >> numeroMateria;

    cout << "Ingrese cantidad de horas: ";
    cin >> cantidadHoras;
    
    if(mes == 3){
      pc_cantidadIngresos[numeroMateria-1][dia-1]++;  
    }
    
    cout << "Ingrese legajo: ";
    cin >> legajo;
  }

  mostrarCantidadIngresosDeMarzo(nombresMaterias, pc_cantidadIngresos);

  return 0;
}

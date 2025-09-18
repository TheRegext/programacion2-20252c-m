#include <iostream>
#include "TareaMenu.h"
using namespace std;

TareaMenu::TareaMenu(){
  _cantidadOpciones = 5;
}

void TareaMenu::mostrar(){
  int opcion;
  
  do{
    system("cls");
    opcion = seleccionarOpciones();
    system("cls");
    ejecutarOpcion(opcion);
    system("pause");
  }while(opcion != 0);
}

void TareaMenu::mostrarOpciones(){
  cout << "--- MENU TAREAS ---" << endl;
  cout << "1 - CREAR TAREA " << endl;
  cout << "2 - MOSTRAR TAREAS " << endl;
  cout << "3 - ELEMINAR TAREA " << endl;
  cout << "4 - MODIFICAR TAREA " << endl;
  cout << "5 - MOSTRAR TAREAS PENDIENTES " << endl;
  cout << "--------------------"<<endl;
}

int TareaMenu::seleccionarOpciones(){
  int opcion;
  mostrarOpciones();
  cout << "Opcion: ";
  cin >> opcion;

  while(opcion < 0 || opcion > _cantidadOpciones){
      cout << "opcion incorrecta"<<endl;
      cout << "Opcion: ";
      cin >> opcion;
  }
  
  return opcion;
}

void TareaMenu::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    _tareaManager.cargarTarea();
  break;
  case 2:
    _tareaManager.mostrarTareas();
  break;
  case 3:
  break;
  case 4:
  break;
  case 5:
    _tareaManager.mostrarTareasFaltantes();
  break;
  }
}

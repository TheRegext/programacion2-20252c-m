#include <iostream>
#include "AppMenu.h"
using namespace std;

AppMenu::AppMenu(){
  _cantidadOpciones = 1;
}

void AppMenu::mostrar(){
  int opcion;
  
  do{
    system("cls");
    opcion = seleccionarOpciones();
    system("cls");
    ejecutarOpcion(opcion);
  }while(opcion != 0);
}

void AppMenu::mostrarOpciones(){
  cout << "--- MENU PRINCIPAL ---" << endl;
  cout << "1 - TAREAS " << endl;
  cout << "--------------------"<<endl;
}

int AppMenu::seleccionarOpciones(){
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

void AppMenu::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    _tareaMenu.mostrar();
  break;
  }
}

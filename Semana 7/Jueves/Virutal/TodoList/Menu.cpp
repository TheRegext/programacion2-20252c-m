#include <iostream>
#include "Menu.h"
using namespace std;

Menu::Menu(){
  _cantidadOpciones = 1;
}

void Menu::mostrar(){
  int opcion;
  
  do{
    system("cls");
    opcion = seleccionarOpciones();
    system("cls");
    ejecutarOpcion(opcion);
    system("pause");
  }while(opcion != 0);
}

void Menu::mostrarOpciones(){
  cout << "--- MENU GENERICO ---" << endl;
  cout << "---------------------------------" << endl;
  cout << "0 - SALIR" << endl;
  cout << "--------------------"<<endl;
}

int Menu::seleccionarOpciones(){
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

void Menu::ejecutarOpcion(int opcion){
  switch(opcion){
  
  }
}

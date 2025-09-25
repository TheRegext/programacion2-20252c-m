#include <iostream>
#include "AppMenu.h"
using namespace std;

AppMenu::AppMenu(){
  _cantidadOpciones = 3;
}

void AppMenu::mostrarOpciones(){
  cout << "--- MENU PRINCIPAL ---" << endl;
  cout << "1 - TAREAS " << endl;
  cout << "2 - PERSONAL " << endl;
  cout << "3 - REPORTES" << endl;
  cout << "----------------------" << endl;
  cout << "0 - SALIR" << endl;
  cout << "----------------------"<<endl;
}

void AppMenu::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    _tareaMenu.mostrar();
  break;
  case 2:
    _personalMenu.mostrar();
    break;  
  case 3:
    _reporteMenu.mostrar();
    break;  
  }
}

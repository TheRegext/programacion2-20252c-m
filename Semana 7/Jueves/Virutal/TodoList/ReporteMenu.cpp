#include <iostream>
#include "ReporteMenu.h"
using namespace std;

ReporteMenu::ReporteMenu(){
  _cantidadOpciones = 2;
}

void ReporteMenu::mostrarOpciones(){
  cout << "--- MENU REPORTES ---" << endl;
  cout << "1 - TAREAS ASIGNADAS POR PERSONAL " << endl;
  cout << "2 - PERSONAL CON MAYOR TAREAS TERMINADAS " << endl;
  cout << "---------------------------------" << endl;
  cout << "0 - SALIR" << endl;
  cout << "--------------------"<<endl;
}

void ReporteMenu::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    _reporteManager.tareasAsignadasPersonal();
  break;
  case 2:
    _reporteManager.personalMayorTareasTerminadas();
  break;
  }
}

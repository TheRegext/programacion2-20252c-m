#include <iostream>
#include "TareaMenu.h"
using namespace std;

TareaMenu::TareaMenu(){
  _cantidadOpciones = 6;
}

void TareaMenu::mostrarOpciones(){
  cout << "--- MENU TAREAS ---" << endl;
  cout << "1 - CREAR TAREA " << endl;
  cout << "2 - MOSTRAR TAREAS " << endl;
  cout << "3 - ELEMINAR TAREA " << endl;
  cout << "4 - MARCAR TAREA " << endl;
  cout << "5 - MOSTRAR TAREAS PENDIENTES " << endl;
  cout << "6 - MOSTRAR TAREAS ORDENADAS" << endl;
  cout << "---------------------------------" << endl;
  cout << "0 - SALIR" << endl;
  cout << "--------------------"<<endl;
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
    _tareaManager.eliminarTarea();
  break;
  case 4:
    _tareaManager.marcarTarea();
  break;
  case 5:
    _tareaManager.mostrarTareasFaltantes();
  break;
  case 6:
    _tareaManager.mostrarTareasOrdenadas();
  break;  
  }
}

#include <iostream>
#include "ReporteManager.h"
#include "utils.h"
using namespace std;

void ReporteManager::tareasAsignadasPersonal()
{
  /// por cada personal, mostrar la cantidad de tareas que fueron asignadas
  Personal *vPersonal;
  int cantidadPersonal;
  cantidadPersonal = _repoPersonal.getCantidadRegistros();
  vPersonal = new Personal[cantidadPersonal];
  _repoPersonal.leerTodos(vPersonal, cantidadPersonal);

  for(int i=0; i<cantidadPersonal; i++)
  {
    /*
    if(vPersonal[i].getEliminado()){
      continue;
    }
    */
    cout << "-----------------------" << endl;
    cout << "Nombre: " << vPersonal[i].getNombre() << endl;

    int cantidadTareas = _repoTareas.getCantidadRegistros();
    int cantidad = 0;
    for(int j=0; j<cantidadTareas; j++)
    {
      Tarea tarea = _repoTareas.leer(j);

      if(tarea.getEliminado())
      {
        continue;
      }

      if(tarea.getIDPersonal() == vPersonal[i].getID())
      {
        cantidad++;
      }
    }

    cout << "Cantidad de tareas asignadas: " << cantidad << endl;


  }
  cout << "-----------------------" << endl;

  delete [] vPersonal;
}

int ReporteManager::cantidadTareasTerminadas(int id)
{
  int cantidadTareas = _repoTareas.getCantidadRegistros();
  int cant = 0;
  
  for(int j=0; j<cantidadTareas; j++)
  {
    Tarea tarea = _repoTareas.leer(j);

    if(tarea.getEliminado())
    {
      continue;
    }

    if(tarea.getIDPersonal() == id && tarea.getEstado()==true)
    {
      cant++;
    }
  }
  
  return cant;
}

void ReporteManager::personalMayorTareasTerminadas()
{
  /// los personales que hayan obtenido la mayor cantidad de tareas terminadas.

  Personal *vPersonal;
  int cantidadPersonal, *vCantidadTerminados;
  cantidadPersonal = _repoPersonal.getCantidadRegistros();
  vPersonal = new Personal[cantidadPersonal];
  vCantidadTerminados = new int [cantidadPersonal] {};

  _repoPersonal.leerTodos(vPersonal, cantidadPersonal);

  for(int i=0; i<cantidadPersonal; i++)
  {
    vCantidadTerminados[i] = cantidadTareasTerminadas(vPersonal[i].getID());
  }

  /// vCantidadTerminados tengo para cada personal, la cantidad terminada
  
  int posMax = buscarMaximo(vCantidadTerminados, cantidadPersonal);
  
  cout << "Los personales con mayor cantidad de terminados son: " << endl;
  for(int i=0; i<cantidadPersonal; i++){
    if(vCantidadTerminados[i] == vCantidadTerminados[posMax]){
      cout << "Nombre: " << vPersonal[i].getNombre() << endl;    
    }  
  }

  delete [] vPersonal;
  delete [] vCantidadTerminados;
}


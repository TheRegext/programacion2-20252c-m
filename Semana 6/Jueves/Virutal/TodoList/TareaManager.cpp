#include <iostream>
#include "TareaManager.h"
#include "Tarea.h"

using namespace std;

std::string cargarCadena()
{
  std::string texto;

  if(std::cin.peek() == '\n')
  {
    std::cin.ignore();
  }

  std::getline(std::cin, texto);

  return texto;
}


TareaManager::TareaManager()
{

}

void TareaManager::cargarTarea()
{
  int id;
  string descripcion;

  id = _repo.getNuevoID();

  cout << "Nueva Tarea #" << id << endl;
  cout << "Ingrese descripcion: ";
  descripcion = cargarCadena();

  if(_repo.guardar(Tarea(id, descripcion, false)))
  {
    cout << "La tarea fue guardad con exito!" << endl;
  }
  else
  {
    cout << "Ocurrio un error al intentar guardar la tarea " << endl;
  }
}

void TareaManager::mostrarTareas()
{
  cout << "Lista de tareas ------  ";
  int cantidad = _repo.getCantidadRegistros();

  for(int i=0; i<cantidad; i++)
  {
    mostrarTareaLista(_repo.leer(i));
  }

}

void TareaManager::mostrarTareasFaltantes()
{
  cout << "Lista de tareas pendientes  ------  ";
  int cantidad = _repo.getCantidadRegistros();

  for(int i=0; i<cantidad; i++)
  {
    Tarea reg = _repo.leer(i);

    if(!reg.estaTerminado())
    {
      mostrarTareaLista(reg);
    }
  }
}

void TareaManager::mostrarTareaLista(const Tarea &tarea)
{
  cout << tarea.getID()
       << " - "  << tarea.getDescripcion()
       << " ---> " << (tarea.getEstado() ? "Realizada" : "No realizada") << endl;
}


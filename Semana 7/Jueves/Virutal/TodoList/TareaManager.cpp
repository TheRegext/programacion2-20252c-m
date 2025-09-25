#include <iostream>
#include "TareaManager.h"
#include "Tarea.h"
#include "utils.h"
#include "Personal.h"
using namespace std;


TareaManager::TareaManager()
{

}

void TareaManager::cargarTarea()
{
  int id;
  string descripcion;
  int idPersonal, posPersonal;
  Personal personal;
  posPersonal = -1;


  id = _repo.getNuevoID();

  cout << "Nueva Tarea #" << id << endl;
  cout << "Ingrese descripcion: ";
  descripcion = cargarCadena();

  do
  {
    cout << "ID Personal (0 sin asignar): ";
    cin >> idPersonal;

    if(idPersonal != 0)
    {
      posPersonal = _repoPersonal.buscarID(idPersonal);

      if(posPersonal == -1)
      {
        cout << "El personal no existe!" << endl;
      }
    }
  }
  while(posPersonal == -1 && idPersonal != 0);

  if(idPersonal == 0)
  {
    cout << "Sin personal asignado" << endl;
  }
  else
  {
    Personal p;
    p=_repoPersonal.leer(posPersonal);
    cout << "El personal asignado es: " << p.getNombre() << endl;
  }

  if(_repo.guardar(Tarea(id, descripcion, idPersonal, false)))
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
  cout << "Lista de tareas ------  "<<endl;;
  int cantidad = _repo.getCantidadRegistros();

  for(int i=0; i<cantidad; i++)
  {
    mostrarTareaLista(_repo.leer(i));
  }
}

void TareaManager::mostrarTareasFaltantes()
{
  cout << "Lista de tareas pendientes  ------  "<<endl;
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
  cout << "-----------------------------------" << endl;
  cout << "ID: " << tarea.getID() << endl;
  cout << "Descripcion: " << tarea.getDescripcion() << endl;
  cout << "Personal: ";
  if(tarea.getIDPersonal() == 0)
  {
    cout << "Sin personal asignado.";
  }
  else
  {
    int pos = _repoPersonal.buscarID(tarea.getIDPersonal());
    if(pos != -1)
    {
      cout << _repoPersonal.leer(pos).getNombre();
    }
    else
    {
      cout << "Personal no encontrado (#"<<tarea.getIDPersonal()<<")";
    }
  }
  cout << endl;
  cout << "Estado: " << (tarea.getEstado() ? "Realizada" : "No realizada") << endl;
  cout << "Eliminado: " << (tarea.getEliminado() ? "Eliminado" : "Activo")  << endl;
}


void TareaManager::marcarTarea()
{
  int id, pos;
  Tarea tarea;
  bool estado;
  cout << "---- Marcar Tarea "<<endl;
  cout << "Ingrese ID tarea: ";
  cin >> id;

  pos = _repo.buscarID(id);

  if(pos != -1)
  {
    tarea = _repo.leer(pos);

    cout << "Tarea a Modificar: "<<endl;
    mostrarTareaLista(tarea);

    cout << "Ingrese 1- completo, 0- pendiente :";
    cin >> estado;

    tarea.setEstado(estado);

    if(_repo.guardar(pos, tarea))
    {
      cout << "La tarea fue actualizada con exito!" << endl;
    }
    else
    {
      cout << "Ocurrio un error al intentar actualizar la tarea." <<endl;
    }
  }
  else
  {
    cout << "La tarea no existe en el archivo" << endl;
  }
}

void TareaManager::eliminarTarea()
{
  int id, pos;
  Tarea tarea;
  char respuesta;
  cout << "---- Eliminar Tarea "<<endl;
  cout << "Ingrese ID tarea: ";
  cin >> id;

  pos = _repo.buscarID(id);

  if(pos != -1)
  {
    tarea = _repo.leer(pos);

    cout << "Tarea a eliminar: "<<endl;
    mostrarTareaLista(tarea);

    cout << "Esta segudro de que lo queire eliminar ? (S/N):";
    cin >> respuesta;

    if(respuesta == 'S' || respuesta == 's')
    {
      if(_repo.eliminar(pos))
      {
        cout << "La tarea fue eliminada con exito!" << endl;
      }
      else
      {
        cout << "Ocurrio un error al intentar actualizar la tarea." <<endl;
      }
    }
  }
  else
  {
    cout << "La tarea no existe en el archivo" << endl;
  }
}


void TareaManager::mostrarTareasOrdenadas()
{
  cout << "Lista de tareas ------  "<<endl;;
  int cantidad = _repo.getCantidadRegistros();
  /// usar memoria dinamica con objetos

  Tarea *tareas;

  tareas = new Tarea[cantidad];

  _repo.leerTodos(tareas, cantidad);

  ///
  for(int i=0; i<cantidad-1; i++)
  {
    bool intercambio = false;
    for(int j=0; j < cantidad - i - 1; j++)
    {
      if(tareas[j].getDescripcion() > tareas[j+1].getDescripcion())
      {
        Tarea aux = tareas[j];
        tareas[j] = tareas[j+1];
        tareas[j+1] = aux;
        intercambio = true;
      }
    }
    if(!intercambio)
    {
      break;   /// corta el ciclo si ya esta ordenado
    }
  }

  for(int i=0; i<cantidad; i++)
  {
    mostrarTareaLista(tareas[i]);
  }

  delete [] tareas;
}


#include <iostream>
#include "PersonalManager.h"
#include "Personal.h"
#include "utils.h"

using namespace std;



PersonalManager::PersonalManager(){
  
}

void PersonalManager::cargar(){
  int id;
  string nombre;
  id = _repo.getNuevoID();
  
  cout << "Cargar Nuevo Personal ----" << endl;
  cout << "ID: " << id << endl;
  cout << "Ingrese nombre: ";
  nombre = cargarCadena();
  
  if(_repo.guardar(Personal(id, nombre))){
    cout << "Se agrego correctamente" << endl;  
  }
  else{
    cout << "Error al intentar guardar el personal." << endl;  
  }
  
}

void PersonalManager::mostrar(){
  int cantidad = _repo.getCantidadRegistros();
  Personal *vPersonal = new Personal[cantidad];
  if(vPersonal == nullptr){
    cout << "No se pudo asignar memoria..." << endl;
    exit(-100);
  }
  
  _repo.leerTodos(vPersonal, cantidad);
  
  for(int i=0; i<cantidad; i++){
    mostrarLista(vPersonal[i]);  
  }
  
  delete [] vPersonal;
}

void PersonalManager::eliminar(){
  
}

void PersonalManager::actualizar(){
  
}

void PersonalManager::mostrarLista(const Personal &personal){
  cout << "ID: "<< personal.getID() << endl;
  cout << "Nombre: "<< personal.getNombre() << endl;
  cout << "------------" <<endl;
}

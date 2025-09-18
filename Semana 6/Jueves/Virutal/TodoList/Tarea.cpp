#include "Tarea.h"
#include <cstring>
using namespace std;

/***
  case
  
  varaibles y funciones 
  camelCase -> LOWER CAMEL CASE
  snake_case -> fecha_actual
  
  Clases 
  PascalCase -> UPPER CAMEL CASE -> React obligatorio...

*/

Tarea::Tarea()
: _id(0), _descripcion(""),_estado(false){
  
}

Tarea::Tarea(int id, string descripcion, bool estado){
  setID(id);
  setDescripcion(descripcion);
  setEstado(estado);
}

int Tarea::getID() const{
  return _id;
}

void Tarea::setID(int id){
  _id = id;
}

bool Tarea::getEstado() const{
  return _estado;
}

void Tarea::setEstado(bool estado){
  _estado = estado;
}

string Tarea::getDescripcion() const{
  return string(_descripcion);
}

void Tarea::setDescripcion(string descripcion){
  strncpy(_descripcion, descripcion.c_str(), 299);
}

bool Tarea::estaTerminado(){
  return getEstado();
}

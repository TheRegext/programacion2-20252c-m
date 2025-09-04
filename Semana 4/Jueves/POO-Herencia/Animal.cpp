#include "Animal.h"
using namespace std;

Animal::Animal()
:_edad(0), _nombre("SIN NOMBRE"){
  // _edad = 0;
  /// _nombre = "SIN NOMBRE";
}

Animal::Animal(std::string nombre, int edad)
: Animal::Animal(){
  setEdad(edad);
  setNombre(nombre);
}

int Animal::getEdad()
{
  return _edad;
}

void Animal::setEdad(int edad)
{
  /// operador ternario (programacion funcional)
  _edad = (edad >= 0) ? edad : _edad;
  
  
  /*
  if(edad >= 0){
    _edad = edad;
  }
  else{
    _edad = 0;
  }
  */
}

string Animal::getNombre()
{
  return _nombre;
}

void Animal::setNombre(string nombre)
{
  _nombre = nombre;
}

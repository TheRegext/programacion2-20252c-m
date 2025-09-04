#include <iostream>
#include "Perro.h"

using namespace std;

Perro::Perro()
: Animal::Animal(), _raza("SIN RAZA"){
  /// logica
}

Perro::Perro(string nombre, int edad, string raza)
: Animal::Animal(nombre, edad), _raza(raza) {
  /// Logica
}

void Perro::ladrar(){
  cout << _raza << "::Woof!" << endl;
  setEdad(getEdad() - 1);
}

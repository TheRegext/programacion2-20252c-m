#pragma once
#include <string>
#include "Animal.h"

class Perro: public Animal{
public:
  Perro();
  Perro(std::string nombre, int edad, std::string raza);
  void ladrar();
private:
  std::string _raza;
};

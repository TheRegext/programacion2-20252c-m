#pragma once
/// incluir las depencias
#include <string>
// include propios
/// using namespace std; /// very mal!

class Animal
{
public:
  Animal();
  Animal(std::string nombre, int edad);
  int getEdad();
  void setEdad(int edad);
  std::string getNombre();
  void setNombre(std::string nombre);
protected:
  
private:
  int _edad;
  std::string _nombre;
};


/***


*/

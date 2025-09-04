#include <iostream>
#include "Perro.h"
#include "Gato.h"
using namespace std;

int main()
{
  Perro p, p02("Mancha", -10, "Criollo");
  
  p.ladrar();
  cout << "Nombre del perro: " << p.getNombre() << endl;
  cout << "Edad del perro: " << p.getEdad() << endl;
  p02.setEdad(-5);
  p02.ladrar();
  cout << "Nombre del perro: " << p02.getNombre() << endl;
  cout << "Edad del perro: " << p02.getEdad() << endl;
   
    return 0;
}

#pragma once
#include <string>
#include "Personal.h"

class PersonalArchivo
{
  public:
    PersonalArchivo(std::string nombreArchivo = "personal.dat");
    bool guardar(const Personal &registro);
    int buscarID(int id);
    Personal leer(int pos);
    
    int leerTodos(Personal tareas[], int cantidad);
    int getCantidadRegistros();
    int getNuevoID();

  private:
    std::string _nombreArchivo;
};

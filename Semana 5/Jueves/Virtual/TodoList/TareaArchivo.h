#pragma once
#include "Tarea.h"

class TareaArchivo
{
  public:
    TareaArchivo(std::string nombreArchivo = "tareas.dat");
    bool guardar(const Tarea &registro);
    Tarea leer(int pos);
    int getCantidadRegistros();
    int getNuevoID();

  private:
    std::string _nombreArchivo;
};

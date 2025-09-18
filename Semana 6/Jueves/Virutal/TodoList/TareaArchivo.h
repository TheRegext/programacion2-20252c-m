#pragma once
#include "Tarea.h"

class TareaArchivo
{
  public:
    TareaArchivo(std::string nombreArchivo = "tareas.dat");
    bool guardar(const Tarea &registro);
    bool guardar(int pos, const Tarea &registro);
    
    int buscarID(int id);
    
    /// bool eliminar(Tarea reg);
    bool eliminar(int pos);
    
    Tarea leer(int pos);
    int getCantidadRegistros();
    int getNuevoID();

  private:
    std::string _nombreArchivo;
};

#pragma once
#include "TareaArchivo.h"


class TareaManager
{
  public:
    TareaManager();
    
    void cargarTarea();
    void mostrarTareas();
    void mostrarTareasFaltantes();
    
  protected:
    void mostrarTareaLista(const Tarea &tarea);
  private:
    TareaArchivo _repo;
};

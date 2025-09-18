#pragma once
#include "TareaArchivo.h"


class TareaManager
{
  public:
    TareaManager();
    
    void cargarTarea();
    void mostrarTareas();
    void mostrarTareasFaltantes();
    void marcarTarea();
    void eliminarTarea();
    
  protected:
    void mostrarTareaLista(const Tarea &tarea);
  private:
    TareaArchivo _repo;
};

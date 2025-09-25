#pragma once
#include "TareaArchivo.h"
#include "PersonalArchivo.h"

class ReporteManager
{
  public:
   void tareasAsignadasPersonal();
   void personalMayorTareasTerminadas();
    
  protected:
    int cantidadTareasTerminadas(int id);
  private:
    TareaArchivo _repoTareas;
    PersonalArchivo _repoPersonal;
};

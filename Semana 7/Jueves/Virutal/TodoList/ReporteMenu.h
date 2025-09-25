#pragma once 
#include "Menu.h"
#include "ReporteManager.h"

class ReporteMenu: public Menu
{
  public:
    ReporteMenu();

  protected:
    void mostrarOpciones();
    void ejecutarOpcion(int opcion);
    
    ReporteManager _reporteManager;
};
  

#pragma once 
#include "Menu.h"
#include "TareaManager.h"

class TareaMenu: public Menu
{
  public:
    TareaMenu();

  protected:
    void mostrarOpciones();
    void ejecutarOpcion(int opcion);
    
    TareaManager _tareaManager;
};
  

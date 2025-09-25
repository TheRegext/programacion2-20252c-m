#pragma once
#include "Menu.h"
#include "TareaMenu.h"
#include "PersonalMenu.h"

class AppMenu: public Menu
{
   public:
    AppMenu();
void mostrarOpciones();
  protected:
    
    void ejecutarOpcion(int opcion);
    
    TareaMenu _tareaMenu;
    PersonalMenu _personalMenu;
};

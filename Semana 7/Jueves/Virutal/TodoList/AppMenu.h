#pragma once
#include "Menu.h"
#include "TareaMenu.h"
#include "PersonalMenu.h"
#include "ReporteMenu.h"

class AppMenu: public Menu
{
   public:
    AppMenu();
void mostrarOpciones();
  protected:
    
    void ejecutarOpcion(int opcion);
    
    TareaMenu _tareaMenu;
    PersonalMenu _personalMenu;
    ReporteMenu _reporteMenu;
};

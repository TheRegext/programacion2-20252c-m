#pragma once 
#include "Menu.h"
#include "PersonalManager.h"

class PersonalMenu: public Menu
{
  public:
    PersonalMenu();

  protected:
    void mostrarOpciones();
    void ejecutarOpcion(int opcion);
  private:
  PersonalManager _personalManager;  
};
  

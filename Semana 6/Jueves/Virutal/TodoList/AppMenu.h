#pragma once
#include "TareaMenu.h"

class AppMenu
{
   public:
    AppMenu();
    void mostrar();

  protected:
    void mostrarOpciones();
    int seleccionarOpciones();
    void ejecutarOpcion(int opcion);
    
    TareaMenu _tareaMenu;

  private:
    int _cantidadOpciones;
};

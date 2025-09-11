#include <iostream>
#include "Tarea.h"
#include "TareaArchivo.h"
#include "TareaManager.h"
using namespace std;

int main()
{
    /// TareaArchivo ta;
    /// Tarea t(ta.getNuevoID(), "Desaprobar alumnos"); /// objeto nombrado o con identidad
    /*
    ta.guardar(Tarea(ta.getNuevoID(), "Objeto anonimo"));
    
    for(int i=0; i<ta.getCantidadRegistros(); i++){
      Tarea registro = ta.leer(i);
      
      cout << registro.getID() << " - " << registro.getDescripcion() << endl;
    }
    */
    
    TareaManager tm;
    
    ///tm.cargarTarea();
///      tm.mostrarTareas();
    tm.mostrarTareasFaltantes();
    
    
    return 0;
}

#pragma once
#include <string>

class Tarea
{
  public: /// interface del objeto
    Tarea();
    Tarea(int id, std::string descripcion, bool estado = false);
    int getID() const;
    void setID(int id);
    
    bool getEstado() const;
    void setEstado(bool estado);
    
    std::string getDescripcion() const;
    void setDescripcion(std::string descripcion);
    
    bool getEliminado() const;
    void setEliminado(bool eliminado);
    
    /// helpers
    bool estaTerminado();
  private:
    int _id;
    char _descripcion[300];
    bool _estado;
    bool _eliminado;   
};



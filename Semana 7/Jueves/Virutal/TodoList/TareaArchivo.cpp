#include <iostream>

#include "TareaArchivo.h"

using namespace std;

TareaArchivo::TareaArchivo(std::string nombreArchivo)
  : _nombreArchivo(nombreArchivo)
{
  /// validar
}

bool TareaArchivo::guardar(const Tarea &registro)
{
  bool result;
  FILE *pFile;
  
  pFile = fopen(_nombreArchivo.c_str(), "ab");

  if(pFile == nullptr)
  {
    return false;
  }

  result = fwrite(&registro, sizeof(Tarea), 1, pFile);

  fclose(pFile);

  return result;
}

bool TareaArchivo::guardar(int pos, const Tarea &registro)
{
  bool result;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb+");

  if(pFile == nullptr)
  {
    return false;
  }

  fseek(pFile, sizeof(Tarea)*pos, SEEK_SET);

  result = fwrite(&registro, sizeof(Tarea), 1, pFile);

  fclose(pFile);

  return result;
}

Tarea TareaArchivo::leer(int pos)
{
  Tarea registro;
  bool result;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr)
  {
    registro.setID(-1);
    return registro;
  }

  fseek(pFile, sizeof(Tarea)*pos, SEEK_SET);

  fread(&registro, sizeof(Tarea), 1, pFile);

  fclose(pFile);

  return registro;
}



int TareaArchivo::leerTodos(Tarea tareas[], int cantidad)
{
  int result;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr)
  {
    return 0;
  }

  result = fread(tareas, sizeof(Tarea), cantidad, pFile);

  fclose(pFile);

  return result;
}

int TareaArchivo::getCantidadRegistros()
{
  int cantidad;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr)
  {
    return 0;
  }

  fseek(pFile, 0, SEEK_END);
  cantidad = ftell(pFile) / sizeof(Tarea);

  fclose(pFile);

  return cantidad;
}

int TareaArchivo::getNuevoID(){
  return getCantidadRegistros() + 1;
}


int TareaArchivo::buscarID(int id){
  Tarea registro;
  FILE *pFile;
  int pos = -1;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr)
  {
    return pos;
  }

  while(fread(&registro, sizeof(Tarea), 1, pFile)){
    if(registro.getID() == id){
      pos = ftell(pFile) / sizeof(Tarea) - 1;
      break; /// corta el ciclo repetitivo
    }  
  }
  
  fclose(pFile);

  return pos;
}

bool TareaArchivo::eliminar(int pos){
  Tarea registro = leer(pos);
  if(registro.getID() == -1){
    return false;  
  }
  
  registro.setEliminado(true);
  
  return guardar(pos, registro);
}

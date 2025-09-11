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
  
  // registro.setID(getNuevoID());

  pFile = fopen(_nombreArchivo.c_str(), "ab");

  if(pFile == nullptr)
  {
    return false;
  }

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

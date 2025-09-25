#include <iostream>

#include "PersonalArchivo.h"

using namespace std;

PersonalArchivo::PersonalArchivo(std::string nombreArchivo)
  : _nombreArchivo(nombreArchivo)
{
  /// validar
}

bool PersonalArchivo::guardar(const Personal &registro)
{
  bool result;
  FILE *pFile;
  
  pFile = fopen(_nombreArchivo.c_str(), "ab");

  if(pFile == nullptr)
  {
    return false;
  }

  result = fwrite(&registro, sizeof(Personal), 1, pFile);

  fclose(pFile);

  return result;
}


Personal PersonalArchivo::leer(int pos)
{
  Personal registro;
  bool result;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr)
  {
    registro.setID(-1);
    return registro;
  }

  fseek(pFile, sizeof(Personal)*pos, SEEK_SET);

  fread(&registro, sizeof(Personal), 1, pFile);

  fclose(pFile);

  return registro;
}


int PersonalArchivo::leerTodos(Personal personales[], int cantidad)
{
  int result;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr)
  {
    return 0;
  }

  result = fread(personales, sizeof(Personal), cantidad, pFile);

  fclose(pFile);

  return result;
}

int PersonalArchivo::getCantidadRegistros()
{
  int cantidad;
  FILE *pFile;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr)
  {
    return 0;
  }

  fseek(pFile, 0, SEEK_END);
  cantidad = ftell(pFile) / sizeof(Personal);

  fclose(pFile);

  return cantidad;
}

int PersonalArchivo::getNuevoID(){
  return getCantidadRegistros() + 1;
}


int PersonalArchivo::buscarID(int id){
  Personal registro;
  FILE *pFile;
  int pos = -1;

  pFile = fopen(_nombreArchivo.c_str(), "rb");

  if(pFile == nullptr)
  {
    return pos;
  }

  while(fread(&registro, sizeof(Personal), 1, pFile)){
    if(registro.getID() == id){
      pos = ftell(pFile) / sizeof(Personal) - 1;
      break; /// corta el ciclo repetitivo
    }  
  }
  
  fclose(pFile);

  return pos;
}

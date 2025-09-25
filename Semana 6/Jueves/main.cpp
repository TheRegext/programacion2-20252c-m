#include <iostream>
#include <cstring>
#include "menus.h"

using namespace std;

/**
Realizar un sistema de gestión para registrar usuarios,
juegos y juegos jugados por usuarios.
Para los usuarios se registra:
- ID, Nombre, fecha de creación de la cuenta.
Para los juegos:
-ID, Nombre, fecha de lanzamiento, puntuación, categoria (1 a 20),
desarrolladora
Para los accesos se registra:
-ID de acceso, ID de usuario, ID de juego, fecha del acceso,
duracion del acceso.
Crear un menu principal con distintos submenues para cada
archivo. En cada submenu debo poder agregar, listar, modificar
y dar de baja los registros.
*/

class ejemplo{
private:
    int numero;
    char texto[30];
public:
    void Cargar(){
        cin>>numero;
        cin>>texto;
    }
    void Mostrar(){
        cout<<numero<<endl;
        cout<<texto<<endl;
    }
};


void cargarCadena(char *cad, int tam){
  string texto;
  if(cin.peek() == '\n'){
    cin.ignore();
  }
  getline(cin, texto);
  strncpy(cad, texto.c_str(), tam);
}

int main()
{
    int num;
    char cadena[30];
    cin>>num;
    cargarCadena(cadena, 29);
    cout<<cadena<<endl;
    cargarCadena(cadena, 29);
    cout<<cadena<<endl;
    return 0;
    menuPrincipal();
    return 0;
}

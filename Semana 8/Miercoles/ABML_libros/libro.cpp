#include <iostream>
#include <cstring>



using namespace std;
#include "Fecha.h"
#include "Libro.h"
#include "funciones_globales.h"

void Libro::Cargar(){
    cout<<"NUMERO ISBN ";
    cin>>ISBN;
    cin.get();
    cout<<"NOMBRE DEL LIBRO ";
    cargarCadena(nombreLibro, 40);
    cout<<"NOMBRE DEL AUTOR ";
    cargarCadena(nombreAutor,40);
    cout<<"ID DEL PAIS DE PUBLICACION ";
    cin>>IDPais;
    cout<<"ID DEL GENERO DEL LIBRO ";
    cin>>IDGenero;
    cout<<"FECHA DE PUBLICACION "<<endl;
    fechaPublicacion.Cargar();
    cout<<"INGRESAR STOCK ";
    cin>>stock;
    estado=true;
}

void Libro::Mostrar(){
    cout<<"NUMERO ISBN "<<ISBN<<endl;
    cout<<"NOMBRE DEL LIBRO "<<nombreLibro<<endl;
    cout<<"NOMBRE DEL AUTOR "<<nombreAutor<<endl;
    cout<<"ID DEL PAIS DE PUBLICACION "<<IDPais<<endl;
    cout<<"ID DEL GENERO DEL LIBRO "<<IDGenero<<endl;

    cout<<"FECHA DE PUBLICACION ";
    fechaPublicacion.Mostrar();
    cout<<"STOCK "<<stock<<endl;
}

        ///gets
int Libro::getISBN(){return ISBN;}
Fecha Libro::getFechaPublicacion(){return fechaPublicacion;}
const char* Libro::getNombreLibro(){return nombreLibro;}
const char* Libro::getNombreAutor(){return nombreAutor;}
int Libro::getStock(){return stock;}
bool Libro::getEstado(){return estado;}
int Libro::getIDPais(){return IDPais;}
int Libro::getIDGenero(){return IDGenero;}

///sets
void Libro::setISBN(int isbn){ISBN=isbn;}
void Libro::setFechaPublicacion(Fecha fe){fechaPublicacion=fe;}
void Libro::setNombreLibro(const char *l){strcpy(nombreLibro, l);}
void Libro::setNombreAutor(const char *l){strcpy(nombreAutor, l);}
void Libro::setEstado(bool e){estado=e;}
void Libro::setIDPais(int e){IDPais=e;}
void Libro::setIDGenero(int e){IDGenero=e;}
void Libro::setStock(int cant){stock=cant;}


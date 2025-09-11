#include <iostream>
#include <cstring>
#include "cargarCadena.h"
#include "clsDomicilio.h"

using namespace std;

void Domicilio::Cargar(){
    cout<<"INGRESE EL NOMBRE DE LA CALLE: ";
    cargarCadena(calle,29);
    cout<<"INGRESE LA ALTURA: ";
    cin>>altura;
    cout<<"INGRESE EL CODIGO POSTAL: ";
    cargarCadena(codigoPostal,5);
    cout<<"INGRESE LA LOCALIDAD: ";
    cargarCadena(localidad,29);
    cout<<"INGRESE EL PARTIDO: ";
    cargarCadena(partido,29);
    cout<<"INGRESE LA PROVINCIA: ";
    cargarCadena(provincia,29);
}

void Domicilio::Mostrar(){
    cout<<"CALLE: "<<calle<<endl;
    cout<<"ALTURA: "<<altura<<endl;
    cout<<"CODIGO POSTAL: "<<codigoPostal<<endl;
    cout<<"LOCALIDAD: "<<localidad<<endl;
    cout<<"PARTIDO: "<<partido<<endl;
    cout<<"PROVINCIA: "<<provincia<<endl;
}

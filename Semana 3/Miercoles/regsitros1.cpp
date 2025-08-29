///Fecha:
///Autor:
///Comentario:

#include <iostream>

using namespace std;

struct fecha{
    int dia, mes, anio;
};


void mostrarFecha(fecha hoy){
    cout<<endl<<hoy.dia<<"/"<<hoy.mes<<"/"<<hoy.anio<<endl;
}


void mostrarFechas(fecha *v, int cant){
    int i;
    for(i=0;i<cant;i++){
        mostrarFecha(v[i]);
    }
}

int main(){
    fecha hoy, ayer, vDias[5];
    cout<<"INGRESAR DIA ";
/*    cin>>hoy.dia;
    cout<<"INGRESAR MES ";
    cin>>hoy.mes;
    cout<<"INGRESAR ANIO ";
    cin>>hoy.anio;
    cout<<endl<<hoy.dia<<"/"<<hoy.mes<<"/"<<hoy.anio<<endl;
*/
	vDias[0].dia=4;
	vDias[0].mes=3;
	vDias[0].anio=2025;
	mostrarFechas(vDias, 5);
	system("pause");
	return 0;

}

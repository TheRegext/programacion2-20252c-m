///Fecha:
///Autor:
///Comentario:

#include <iostream>

using namespace std;

class Fecha{
    private:///modificadores de acceso, indican donde son accesibles los componentes
       int dia, mes, anio;///propiedades o variables de la clase
    public:///métodos determinan el comportamiento de los objetos. Funciones de la clase
        ///constructor/es se ejecuta de manera automáticamente al momento de la declaración del objeto
        Fecha(int _dia=0, int _mes=1, int _anio=1){
            dia=_dia;
            mes=_mes;
            anio=_anio;
        }

        void Cargar();
        void Mostrar();
       ///sets-> se usan para darle valor a cada una de las propiedades
        void setDia(int d){
            if(d>=1 && d<=31) dia=d;
            else dia=-1;
        }
        void setMes(int d){
            if(d>=1 && d<=12) mes=d;
            else mes=-1;
        }
        void setAnio(int d){
            if(d>0) anio=d;
            else anio=-1;
        }

       ///gets-> se usan para que el mundo externo conozca el valor de cada propiedad
       int getDia(){return dia;}
       int getMes(){return mes;}
       int getAnio(){return anio;}

       ///
       bool esCorrecta();
       ///
       ~Fecha(){
            cout<<"SE MURIO EL OBJETO :-("<<endl;
       }
};

///Desarrollo de los métodos
void Fecha::Cargar(){
    int _dia, _mes, _anio;
    cout<<"INGRESAR EL DIA ";
    cin>>_dia;
    setDia(_dia);
    cout<<"INGRESAR EL MES ";
    cin>>_mes;
    setMes(_mes);
    cout<<"INGRESAR EL ANIO ";
    cin>>_anio;
    setAnio(_anio);
}

void Fecha::Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

bool Fecha::esCorrecta(){
    if(dia!=-1 && mes!=-1 && anio!= -1)return true;
    return false;
}

///FIN METODOS


///private: sólo accesible dentro de la clase
///public: accesible dentro y fuera de la clase

///Clase: molde en el que se define las propiedades y el comportamiento de los objetos
/// de esa clase.

///Objeto: una variables de una clase. Se dice que es una instancia de una clase

///Encapsulamiento: para preservar los datos contenidos en las propiedades, éstas
///se ubican dentro de la parte privada de la clase. La única manera de acceder
///es mediante los mecanismos provistos por la misma clase

int main(){
    Fecha hoy(27), ayer, v[10];
    hoy.Mostrar();
    ayer.Mostrar();
    ///Cargar();///funciones globales. Están fuera de toda clase
    hoy.Cargar();///Método de la clase. Es llamada por un objeto de esa clase
    //hoy.setDia(34);
    //hoy.setMes(8);
    //hoy.setAnio(2025);
    hoy.Mostrar();
    if(hoy.esCorrecta())hoy.Mostrar();
    else cout<<"FECHA INCORRECTA"<<endl;
    if(hoy.getDia()==27){
        cout<<"EL DIA ES 27"<<endl;
    }



	system("pause");
	return 0;

}

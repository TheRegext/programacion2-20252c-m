///Fecha:
///Autor:
///Comentario:

#include <iostream>

using namespace std;

///COMPOSICION: es un mecanismo que permite que una clase tenga como propiedad OBJETOS DE otra CLASE
///Cuando una clase usa este mecanismo NO PUEDE ACCEDER DIRECTAMENTE a las propiedades del objeto
/// de la clase añadida por composición.DEBE USAR LOS METODOS DEFINIDOS EN LA CLASE A LA QUE ESE
///OBJETO PERTENECE

class Fecha{
    private:
       int dia, mes, anio;
    public:
        Fecha(int _dia=0, int _mes=1, int _anio=1){
            dia=_dia;
            mes=_mes;
            anio=_anio;
        }

        void Cargar();
        void Mostrar();

        void setDia(const  int d){
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
       int getDia(){return dia;}
       int getMes(){return mes;}
       int getAnio(){return anio;}
       bool esCorrecta();
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

///FIN CLASE Fecha

///CLASE Direccion

class Direccion{
private:
    char calle[30];
    int numero;
    char localidad[30];
public:
    void Cargar();
    void Mostrar();

};

void Direccion::Cargar(){
    cout<<"CALLE ";
    cin>>calle;
    cout<<"NUMERO ";
    cin>>numero;
    cout<<"LOCALIDAD ";
    cin>>localidad;
}

void Direccion::Mostrar(){
    cout<<"CALLE "<<calle<<endl;
    cout<<"NUMERO "<<numero<<endl;
    cout<<"LOCALIDAD "<<localidad<<endl;
}

///CLASE Socio
class Socio{
private:
    int DNI, IdSocio;
    char nombre[30];
    char apellido[30];
    char telefono[15];
    char email[40];
    Fecha fechaNacimiento;
///    int diaNac, mesNac, anioNac; alternativa sin composición
    Direccion domicilio;
public:
    void Cargar();
    void Mostrar();
    ///gets
    int getIdSocio(){return IdSocio;}
    Fecha getFechaNacimiento(){return fechaNacimiento;}
    Direccion getDomicilio(){return domicilio;}
    ///sets
    void setIdSocio(int id){IdSocio=id;}
    void setFechaNacimiento(Fecha nac){fechaNacimiento=nac;}
    void setDomicilio(Direccion dom){domicilio=dom;}
    void setDiaNacimiento(int d){
        fechaNacimiento.setDia(d);
    }

};
///Métodos de Socio
void Socio::Cargar(){
    cout<<"IDSOCIO ";
    cin>>IdSocio;
    cout<<"NOMBRE ";
    cin>>nombre;
    cout<<"APELLIDO ";
    cin>>apellido;
    cout<<"FECHA DE NACIMIENTO ";
    fechaNacimiento.Cargar();///
    cout<<"DOMICILIO ";
    domicilio.Cargar();///

}

void Socio::Mostrar(){
    cout<<"IDSOCIO "<<IdSocio<<endl;
    cout<<"NOMBRE "<<nombre<<endl;
    cout<<"APELLIDO "<<apellido<<endl;
    cout<<"FECHA DE NACIMIENTO "<<endl;
    fechaNacimiento.Mostrar();///
    cout<<"DOMICILIO "<<endl;
    domicilio.Mostrar();///
    cout<<endl;
}

int main(){
    Socio nuevo;
    nuevo.Cargar();
    cout<<endl<<endl;
    nuevo.Mostrar();
    cout<<endl<<endl;
    cout<<nuevo.getFechaNacimiento().getAnio()<<endl;

	system("pause");
	return 0;

}

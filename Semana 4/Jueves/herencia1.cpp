///Fecha:
///Autor:
///Comentario:

#include <iostream>
#include <cstring>

using namespace std;

class Fecha{
    private:
       int dia, mes, anio;
    public:
        Fecha(int _dia=0, int _mes=0, int _anio=0){
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
    if(esCorrecta()) cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    else cout<<"FECHA INCORRECTA. CORREGIR!!!"<<endl;
}

bool Fecha::esCorrecta(){
    if(dia!=-1 && mes!=-1 && anio!= -1)return true;
    return false;
}

///FIN CLASE Fecha

class Persona{
protected:///mantiene el acceso dentro de la clase, pero permite el acceso a las clases derivadas
    char nombre[30], apellido[30];
    int DNI;
    Fecha fechaNacimiento;
    char email[40];
public:
    void Cargar();
    void Mostrar();
    ///gets
    const char* getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    int getDNI(){return DNI;}
    Fecha getFechaNacimiento(){return fechaNacimiento;}
    ///sets
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *n){strcpy(apellido,n);}
    void setDNI(int dni){DNI=dni;}
    void setFechaNacimiento(Fecha fn){fechaNacimiento=fn;}
    ///
    void MostrarNombre(){
        cout<<nombre<<" "<<apellido<<endl;
    }

};
void Persona::Cargar(){
    cout<<"NOMBRE ";
    cin>>nombre;
    cout<<"APELLIDO ";
    cin>>apellido;
    cout<<"DNI ";
    cin>>DNI;
    cout<<"FECHA DE NACIMIENTO "<<endl;
    fechaNacimiento.Cargar();

}

void Persona::Mostrar(){
    cout<<"NOMBRE "<<nombre<<endl;
    cout<<"APELLIDO "<<apellido<<endl;
    cout<<"DNI "<<DNI<<endl;
    cout<<"FECHA DE NACIMIENTO "<<endl;
    fechaNacimiento.Mostrar();
}
///fin de la clase base Persona

class Alumno: public Persona{
private:
    int legajoAlumno;
    int IdCarrera;
public:
    ///gets
    int getLegajo(){return legajoAlumno;}
    int getIdCarrera(){return IdCarrera;}
    ///sets
    void setLegajo(int l){legajoAlumno=l;}
    void setIdCarrera(int id){IdCarrera=id;}
    void cambiarNombre(const char *_nombre){strcpy(nombre,_nombre);}
    ///
    void Cargar();
    void Mostrar();
    int devolverLegajo(){return getLegajo();}
    void MostrarNombre(int queMostrar){
        if(queMostrar==1) cout<<nombre<<" "<<apellido<<endl;
        else cout<<nombre;
    }
   /* void MostrarNombre(){
        cout<<nombre<<" "<<apellido<<endl;
    }*/
};

void Alumno::Cargar(){
    Persona::Cargar();
    cout<<"LEGAJO ";
    cin>>legajoAlumno;
    cout<<"ID CARRERA ";
    cin>>IdCarrera;
}

void Alumno::Mostrar(){
    Persona::Mostrar();
    cout<<"LEGAJO "<<legajoAlumno<<endl;
    cout<<"ID CARRERA "<<IdCarrera<<endl;
}


int main(){
    Alumno obj;
    /*obj.setNombre("LIONEL");
    obj.setLegajo(10);
    cout<<obj.getLegajo()<<endl;
    cout<<obj.getNombre()<<endl;
*/
    obj.Cargar();
    obj.Persona::MostrarNombre();

    cout<<endl;
    obj.MostrarNombre(2);
	system("pause");
	return 0;

}

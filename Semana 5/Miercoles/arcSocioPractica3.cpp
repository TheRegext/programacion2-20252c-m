///Fecha:
///Autor:
///Comentario:

#include <iostream>
#include <string.h>

using namespace std;

///Agregar un menu con las opciones:
/*
    * Agregar registro
    * Mostrar registros
    * Buscar registro

Al agregar un registro se debe impedir que haya 2 socios con el mismo ID

Buscar registro: debe pedir el ingreso de un DNI, y mostrar si existe un socio con ese DNI.
Caso contrario debe informar que no existe ese socio.
*/

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
///    int diaNac, mesNac, anioNac; alternativa sin composici�n
    Direccion domicilio;
public:
    void Cargar();
    void Mostrar();
    ///gets
    int getIdSocio(){return IdSocio;}
    const char* getApellido(){return apellido;}
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
///FIN CLASE SOCIO
///PROTOTIPO FUNCIONES GLOBALES
bool agregarRegistroSocio();
bool escribirRegistroSocio(Socio reg);
bool mostrarRegistroSocio();
int buscarRegistroSocio(int idSocio);///si encuentra el id, que devuelva la pos del reg dentro del archivo. Si no -1
void buscarRegistro(const char* apellido);

int contarRegistrosSocios();///si devuelve 0 es porque no tiene registros y existe; -1 si no existe
void buscarSocio();
Socio leerRegistroSocio(int posReg);
///FIN PROTOTIPOS

int main(){
    Socio nuevo;
    int opcion;
    //int idSocio=0;
    //char _apellido[30];

    while(true){
        system("cls");

        cout<<"Seleccione opcion del menu: "<<endl;
        cout<<"1. Agregar registro"<<endl;
        cout<<"2. Listar registros"<<endl;
        cout<<"3. Buscar registro"<<endl;
        cout<<"4. Contar registros"<<endl;
        cout<<"0. Salir"<<endl;

        cin>>opcion;
        system("cls");
        switch (opcion){
            case 1: if(agregarRegistroSocio()){
                    cout<<"Registro agregado"<<endl;
                    }
                    else{
                        cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
                    }
                break;
            case 2:
                mostrarRegistroSocio();
                break;
            case 3: buscarSocio();
                    break;

            case 4: cout<<contarRegistrosSocios()<<endl;
                    break;
            case 0:
                return 0;
                break;
            default:
                cout<<"Opcion incorrecta!"<<endl;
        }
        system("pause");
        system("cls");
    }
    //nuevo.Cargar();
    ///nuevo.Mostrar();
    if(escribirRegistroSocio(nuevo)) cout<<"REGISTRO AGREGADO "<<endl;
    else cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
	mostrarRegistroSocio();
	system("pause");
	return 0;

}

bool agregarRegistroSocio(){
    Socio reg;
    reg.Cargar();
    int id=reg.getIdSocio();
    int posReg=buscarRegistroSocio(id);
    if(posReg!=-1){
        cout<<"NO SE PUEDE REPETIR EL ID";
        return false;
    }
    bool escribio= escribirRegistroSocio(reg);
    return escribio;
}


bool escribirRegistroSocio(Socio reg){
    FILE *pSocio;
    pSocio=fopen("socios.dat","ab");///wb->(write) escritura SIEMPRE CREA UN ARCHIVO NUEVO
                                 ///rb-> (read) solo lectura
                                 ///ab-> (append) para agregar registros. Si el archivo no existe lo crea
    if(pSocio==nullptr)return false;
    bool escribio=fwrite(&reg,sizeof(Socio),1, pSocio);
    //fwrite(&reg,sizeof reg,1, pSocio)
    fclose(pSocio);
    return escribio;
}

bool mostrarRegistroSocio(){
    Socio reg;
    FILE *pSocio;
    pSocio=fopen("socios.dat","rb");
    if(pSocio==nullptr)return false;

    while(fread(&reg,sizeof(Socio),1, pSocio)==1){
        reg.Mostrar();
        cout<<endl;
    }

    fclose(pSocio);
    return true;
}


int buscarRegistroSocio(int idSocio){
    Socio reg;
    FILE *pSocio;
    pSocio=fopen("socios.dat","rb");
    if(pSocio==nullptr){
        return -1;
    }
    int pos=0;
    while(fread(&reg,sizeof(Socio),1, pSocio)==1){
        if(reg.getIdSocio()==idSocio){
            fclose(pSocio);
            return pos;
        }
        pos++;
    }
    fclose(pSocio);
    return -1;
}

void buscarRegistro(const char* apellido){
    Socio reg;
    FILE *pSocio;
    pSocio=fopen("socios.dat","rb");
    if(pSocio==nullptr);

    while(fread(&reg,sizeof(Socio),1, pSocio)==1){
        if(strcmp(reg.getApellido(),apellido)==0){
            reg.Mostrar();
        }
    }

    fclose(pSocio);
}

int contarRegistrosSocios(){
    FILE *pSocio;
    pSocio=fopen("socios.dat","rb");
    if(pSocio==nullptr){
        return -1;
    }
    /*
    fseek(puntero_file, cuánto_quiero_desplazar, desde_donde)

            0   SEEK_SET-> desde el principio del archivo
            1   SEEK_CUR-> posición actual del archivo
            2   SEEK_END-> eof (fin del archivo)

    fssek(p, 0, 0);-> el puntero al principio del archivo
    fseek(p, 0, 2),-> el puntero va al final del archivo
    fseek(p, sizeof(Socio), SEEK_CUR);-> SE ADELANTA UN REGISTRO
      */
    fseek(pSocio,0,2);/// permite manipular la posición del puntero en el archivo
    int cantBytes=ftell(pSocio);///me dice la cantidad de bytes que hay desde el principio del archivo a la posición actual
    int cantReg=cantBytes/sizeof(Socio);
    fclose(pSocio);
    return cantReg;
}


/*
int contarRegistrosSocios(){
    Socio reg;
    FILE *pSocio;
    pSocio=fopen("socios.dat","rb");
    if(pSocio==nullptr){
        return -1;
    }
    int pos=0;
    while(fread(&reg,sizeof(Socio),1, pSocio)==1){
        pos++;
    }
    fclose(pSocio);
    return pos;
}
*/
void buscarSocio(){
    Socio reg;
    int id;
    cout<<"INGRESE LA ID DEL SOCIO A BUSCAR ";
    cin>>id;
    int pos=buscarRegistroSocio(id);
    if(pos==-1){
        cout<<"NO EXISTE EL SOCIO "<<endl;
        return;
    }
    reg=leerRegistroSocio(pos);
    reg.Mostrar();
}


/*Socio leerRegistroSocio(int posReg){
    Socio reg;
    reg.setIdSocio(-1);
    FILE *pSocio;
    pSocio=fopen("socios.dat","rb");
    if(pSocio==nullptr){
        return reg;
    }

    int pos=0;
    while(fread(&reg,sizeof(Socio),1, pSocio)==1){
        if(pos==posReg){
            fclose(pSocio);
            return reg;
        }
        pos++;
    }
    fclose(pSocio);
    reg.setIdSocio(-1);
    return reg;

}
*/

Socio leerRegistroSocio(int posReg){
    Socio reg;
    reg.setIdSocio(-1);
    FILE *pSocio;
    pSocio=fopen("socios.dat","rb");
    if(pSocio==nullptr){
        return reg;
    }
    fseek(pSocio, posReg*sizeof(Socio),0);///ubico el puntero al inicio del registro que quiero leer

    fread(&reg,sizeof(Socio),1, pSocio);///leo el registro

    fclose(pSocio);

    return reg;

}

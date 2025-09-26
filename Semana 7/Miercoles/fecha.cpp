///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstring>

///SOBRECARGA DE OPERADORES:es un mecanismo que nos permite agregarle funcionalidad a los operadores del lenguaje.
///Esto se consigue escribiendo el c�digo correspondiente dentro de la clase

///Sobrecargar el operador != de tal manera que sea verdadero si ambos objetos Fecha son distintos
using namespace std;

class Fecha{
    private:
        int dia, mes, anio;
    public:
         Fecha(int d=0, int m=0, int a=0);

         void Cargar();
         void Mostrar(void);
        ///sets
         void setDia(int dia){
             if(dia>=1 &&dia<=31)this->dia=dia;
             else this->dia=0;
             }
        void setMes(const int m){mes=m;}
        void setAnio(int a){anio=a;}
        ///gets
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
        ///SOBRECARGAS
        bool operator==(Fecha obj);
        bool operator==(string mesBuscado);

        ///DESTRUCTOR
        ~Fecha(){

        }

};
 ///fin de la definici�n de la clase

///desarrollo de los m�todos
void Fecha::Cargar(){
            int d;
            cout<<"DIA ";
            cin>>d;
            setDia(d);
            cout<<"MES ";
            cin>>mes;
            cout<<"ANIO ";
            cin>>anio;
         }

void Fecha::Mostrar(){
             cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
         }

Fecha::Fecha(const int d,const int m,const int a){
            dia=d;
            mes=m;
            anio=a;
}

///Sobrecargas
bool Fecha::operator==(Fecha obj){
    if(dia!=obj.dia) return false;
    if(mes!=obj.mes) return false;
    if(anio!=obj.anio) return false;
    return true;
}
/*
bool Fecha::operator==(const char *mesBuscado){
    char meses[12][11]={"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO","SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};
    if(strcmp(mesBuscado,meses[mes-1])==0) return true;
    return false;

}
*/

bool Fecha::operator==(string mesBuscado){
    string meses[12]={"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO","SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};
    if(mesBuscado==meses[mes-1]) return true;
    return false;

}
///FIN SOBRECARGAS
///FIN DESARROLLO METODOS

int main(){
    Fecha aux(2,8,5), otra(2,4,5);

    aux.Mostrar();
	cout<<endl;
	otra.Mostrar();
	cout<<endl;

	///if(aux==otra){
	/*if(aux.operator==(otra)){
        cout<<"SON IGUALES "<<endl;
	}
	else{
        cout<<"SON DISTINTOS "<<endl;
	}*/

   if(aux=="SEPTIEMBRE"){
        cout<<"PRIMAVERA!!!"<<endl;
   }




	system("pause");
	return 0;
}

/*Operadores Unarios:

++ --

Operadores Binarios:

+      +=      -      -=
*      *=      /      /=
%      %=      ^      ^=
&      &=      |      |=
=      ==      !      !=
<      <=      >      >=
&&     ||      ()     []
*/

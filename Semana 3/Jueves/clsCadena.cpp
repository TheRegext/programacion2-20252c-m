///Fecha:
///Autor:
///Comentario:

#include <iostream>
#include <cstring> ///string.h

using namespace std;
///Agregar los siguientes métodos:
    /// aMayusculas()-> que ponga todos los caracteres en mayúsculas
    /// aMinusculas()-> que ponga todos los caracteres en minúsculas
    /// primeraMayuscula()-> que ponga la primera letra en mayúscula
    /// int buscarCaracter(char aBuscar) que devuelva la posición de la  primera aparicion del
    /// caracter aBuscar en la cadena. Si no lo encuentra que devuelva -1


class Cadena{
    private:
        char *p;
        int tam;
    public:
        Cadena(const char *inicio){
            tam=strlen(inicio)+1;
            p=new char[tam];
            if(p==nullptr)exit(1);
            strcpy(p,inicio);
            p[tam-1]='\0';
        }
        ///set
        void setP(const char *nuevo){
            delete []p;
            tam=strlen(nuevo)+1;
            p=new char[tam];
            if(p==nullptr)exit(1);
            strcpy(p,nuevo);
            p[tam-1]='\0';
        }
        ///gets
        int getTam(){return tam;}
        const char *getP(){return p;}

        void Mostrar(){
            cout<<p<<endl;
        }

        ~Cadena(){
            delete []p;
        }

};


int main(){
    Cadena palabra("HOLA A TODOS LOS DORMIDOS/AS INCLUIDO EL PROFESOR!");
    palabra.Mostrar();
    palabra.setP("otra palabra");
    palabra.Mostrar();
    cout<<endl;
    cout<<palabra.getP()<<endl;

	system("pause");
	return 0;

}

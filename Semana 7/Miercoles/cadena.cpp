///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstring>
///Hacer una clase de nombre Cadena para almacenar palabras,
///que ajuste su tamaño a la cantidad de caracteres estrictamente necesarios

using namespace std;

class Cadena{
private:
    char *p;
    int tam;
public:
    Cadena(const char *texto="NADA"){
        tam=strlen(texto)+1;
        p=new char[tam];
        if(p==nullptr)exit(1);
        strcpy(p,texto);
        p[tam-1]='\0';
    }

    Cadena(const Cadena &aux){
        if(this!=&aux){
            tam=aux.tam;
            p=new char[tam];
            if(p==nullptr)exit(1);
            strcpy(p,aux.p);
            p[tam-1]='\0';
        }
    }

    void Mostrar(){
        cout<<p<<endl;
    }
    int getTamanio(){return tam;}
    const char *getP(){return p;}
    ///SOBRECARGAS
    bool operator==(Cadena aux);
    Cadena & operator=(Cadena aux);
    ///void operator=(string aux);
    void operator=(const char* aux);
    char operator[](int pos);
    ///FIN SOBRECARGAS
    ~Cadena(){
        delete []p;
    }
};
///desarrollo de métodos
///sobrecargas

bool Cadena::operator==(Cadena aux){
    if(strcmp(p, aux.p)==0) return true;
    return false;

}

Cadena & Cadena::operator=(Cadena aux){
    delete []p;
    tam=aux.tam;
    p=new char[tam];
    if(p==nullptr)exit(1);
    strcpy(p,aux.p);
    return *this;
}

void Cadena::operator=(const char* aux){
    delete []p;
    tam=strlen(aux)+1;
    p=new char[tam];
    if(p==nullptr)exit(1);
    strcpy(p,aux);

}

char Cadena::operator[](int pos){
    if(pos>=0 && pos<tam) return p[pos];
    return '\0';
}
///fin métodos




int main(){
    Cadena palabra("HOLA A TODOS/AS!"), otra("CHAU!"), ultima("veremos si funciona");
    /*palabra.Mostrar();
    if(palabra==otra){
        cout<<"IGUALES"<<endl;
    }
    else{
        cout<<"DISTINTAS"<<endl;
    }
    otra=palabra;
    if(palabra==otra){
        cout<<"IGUALES"<<endl;
    }
    else{
        cout<<"DISTINTAS"<<endl;
    }

    palabra="algo de manera directa";
    palabra.Mostrar();
    */
    palabra=otra=ultima;

    palabra.Mostrar();
    otra.Mostrar();
    ultima.Mostrar();

    cout<<ultima[3]<<endl;
    cout<<endl;
	system("pause");
	return 0;
}

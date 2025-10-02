#include <iostream>
#include <cstring>

using namespace std;
#include "Fecha.h"
#include "Libro.h"
#include "ArchivoLibro.h"

ArchivoLibros::ArchivoLibros(const char *n){
    strcpy(nombre, n);
    tamanioRegistro=sizeof(Libro);
}

int ArchivoLibros::agregarRegistro(Libro reg){
    FILE *p;
    p=fopen(nombre,"ab");
    if(p==nullptr){
        return -1;
    }

    int escribio=fwrite(&reg, tamanioRegistro,1,p);

    fclose(p);
    return escribio;
}

bool ArchivoLibros::listarRegistros(){
    Libro obj;
    FILE *p;
    p=fopen(nombre,"rb");

    if(p==nullptr){
       return false;
    }
    while(fread(&obj, tamanioRegistro,1,p)==1){
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }
    fclose(p);
    return true;
}

int ArchivoLibros::buscarRegistro(int _ISBN){
    Libro obj;
    FILE *p;
    p=fopen(nombre,"rb");

    if(p==nullptr){
       return -1;
    }
    int cantReg=contarRegistros();
    for(int i=0;i<cantReg;i++){
        fread(&obj, tamanioRegistro,1,p);
        if(obj.getEstado() && obj.getISBN()==_ISBN){
            fclose(p);
            return i;
        }
    }

    fclose(p);
    return -2;

}
Libro ArchivoLibros::leerRegistro(int pos){
    Libro obj;
    FILE *p;
    p=fopen(nombre,"rb");

    if(p==nullptr){
       return obj;
    }
    fseek(p, tamanioRegistro*pos,0);
    fread(&obj, tamanioRegistro,1,p);
    fclose(p);
    return obj;

}


bool ArchivoLibros::modificarRegistro(Libro reg, int pos){
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==nullptr){
       return false;
    }
    fseek(p, pos*tamanioRegistro,0);
    bool escribio=fwrite(&reg, tamanioRegistro,1,p);
    fclose(p);
    return escribio;


}

int ArchivoLibros::contarRegistros(){
    Libro obj;
    FILE *p;
    p=fopen(nombre,"rb");

    if(p==nullptr){
       return 0;
    }
    fseek(p,0,2);
    int cantReg=ftell(p)/tamanioRegistro;
    fclose(p);
    return cantReg;
}

bool ArchivoLibros::bajaLogica(int pos){
    Libro reg;
    reg=leerRegistro(pos);
    reg.setEstado(false);
    return modificarRegistro(reg,pos);
}


bool ArchivoLibros::activarRegistro (int pos){
    Libro reg;
    reg=leerRegistro(pos);
    reg.setEstado(true);
    return modificarRegistro(reg,pos);

}

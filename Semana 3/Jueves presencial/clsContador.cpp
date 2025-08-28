#include <iostream>
#include "clsContador.h"

using namespace std;

Contador::Contador(int val){
    valor = val;
    valorInicial = val;
}
void Contador::setValor(int val){
    valor = val;
}
int Contador::getValor(){
    return valor;
}
void Contador::Mostrar(){
    cout<<valor<<endl;
}
void Contador::incrementar(int val){
    valor+=val;
}
void Contador::decrementar(){
    if(valor>0)valor--;
}
void Contador::reiniciar(){
    valor = valorInicial;
}
Contador::~Contador(){
    cout<<"SE MURIO EL OBJETO. POBRE OBJETO =("<<endl;
}

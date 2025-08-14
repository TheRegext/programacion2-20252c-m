#include <iostream>

using namespace std;
///Las funciones en C++ admiten valores por omisión para sus
///parámetros void cartelSaludo(int tipo=2);.

void cartelSaludo(int tipo=2);
void cartelSaludo(const char *texto);

int main(){


    cartelSaludo(1);
    cartelSaludo("ENSEGUIDA VIENE EL BREAK!!!!");

	system("pause");
	return 0;

}

void cartelSaludo(int tipo){

    if(tipo==1)cout<<"HOLA A TODOS!!!"<<endl;
    else cout<<"HASTA LA PROXIMA!!!"<<endl;

}


void cartelSaludo(const char *texto){
    cout<<texto<<endl;
}

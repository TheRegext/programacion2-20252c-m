///Fecha:
///Autor:
///Comentario:

#include <iostream>

using namespace std;

void ingresarDatos(float mat[][31]);
void recaudacionPaisDia(float mat[][31], int filas, int columnas);
void diasPaisSinRecaudacion(float mat[][31], int filas, int columnas);
void diasSinRecaudacion(float mat[][31], int filas, int columnas);

int main(){
    int opc;
    float paisesDias[3][31]={};
    while(true){
        system("cls");
        cout<<"*********************************"<<endl;
        cout<<"1. INGRESAR DATOS"<<endl;
        cout<<"2. RECAUDACION POR PAIS Y DIA"<<endl;
        cout<<"3. DIAS SIN RECAUDACION POR PAIS"<<endl;
        cout<<"4. DIAS SIN RECAUDACION GENERAL"<<endl;
        cout<<"0. FIN DEL PROGRAMA"<<endl;
        cout<<"*********************************"<<endl;
        cout<<"ELEGIR OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: ingresarDatos(paisesDias);
                    break;
            case 2: recaudacionPaisDia(paisesDias, 3, 31);
                    break;
            case 3: diasPaisSinRecaudacion(paisesDias, 3, 31);
                    break;
            case 4: diasSinRecaudacion(paisesDias, 3, 31);
                    break;
            case 0: return 0;
                break;
            default: cout<<"INGRESO INCORRECTO"<<endl;
        }
        system("pause");
    }

	system("pause");
	return 0;

}

void ingresarDatos(float mat[][31]){
    int pais, dia;
    float monto;
    cout<<"INGRESAR EL PAIS ";
    cin>>pais;
    while(pais!=-1){
        cout<<"INGRESAR EL DIA ";
        cin>>dia;
        cout<<"INGRESAR EL MONTO DE LA VENTA ";
        cin>>monto;
        mat[pais-1][dia-1]+=monto;

        cout<<"INGRESAR EL PAIS ";
        cin>>pais;
    }
}

void recaudacionPaisDia(float mat[][31], int filas, int columnas){
    int i, j;
    for(i=0;i<filas; i++){
        cout<<"PAIS "<<i+1<<endl;
        for(j=0;j<columnas;j++){
            if(mat[i][j]!=0){
                cout<<"DIA "<<j+1<<" RECAUDACION "<<mat[i][j]<<"\t";
            }
        }
        cout<<endl;
    }
}

void diasPaisSinRecaudacion(float mat[][31], int filas, int columnas){
    int i, j;
    int cantSinVentas;
    for(i=0;i<filas; i++){
        cout<<"PAIS "<<i+1<<endl;
        cantSinVentas=0;
        for(j=0;j<columnas;j++){
            if(mat[i][j]==0){
                cantSinVentas++;
            }
        }
        cout<<"CANTIDAD DE DIAS SIN VENTAS "<<cantSinVentas<<endl;
        cout<<endl;
    }
}

void diasSinRecaudacion(float mat[][31], int filas, int columnas){
    int i, j;
    int cantSinVentas;
    for(i=0;i<columnas; i++){
        cantSinVentas=0;
        for(j=0;j<filas;j++){
            if(mat[j][i]==0){
                cantSinVentas++;
            }
        }
        if(cantSinVentas==3){
                cout<<"EN EL DIA "<<i+1<<" NO HUBO VENTAS "<<endl;
        }
        cout<<endl;
    }
}

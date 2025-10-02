#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
private:
    int dia,mes,anio;
public:
    Fecha(int d=0, int m=0, int a=0);
    void Cargar();
    void Mostrar();
    int getDia();
    int getMes();
    int getAnio();

    void setDia(int a);
    void setMes(int a);
    void setAnio(int a);

};

#endif // FECHA_H_INCLUDED

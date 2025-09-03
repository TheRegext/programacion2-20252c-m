#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

#include <cstring>

class Materia{
    private:
        ///Propiedades privadas de mi clase
        ///SON VARIABLES DE LA CLASE (ALMACENAN INFORMACION)
        int numero;
        char nombre[50];
        int cantidadParciales;
        int cantidadAlumnos;
        int cantidadDocentes;
    public:
        ///Métodos públicos de mi clase
        ///SON FUNCIONES DE LA CLASE
        void setNumero(int n);
        void setNombre(const char *n);
        void setCantidadParciales(int cP);
        void setCantidadAlumnos(int cA);
        void setCantidadDocentes(int cD);
        int getNumero();
        const char *getNombre();
        int getCantidadParciales();
        int getCantidadAlumnos();
        int getCantidadDocentes();
        void Cargar();
        void Mostrar();
};



#endif // TIPOS_H_INCLUDED

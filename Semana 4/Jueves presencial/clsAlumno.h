#ifndef CLSALUMNO_H_INCLUDED
#define CLSALUMNO_H_INCLUDED

/**
DESARROLLAR UNA CLASE Contador, QUE NOS PERMITA CONTAR
COSAS.
PENSAR QUE PROPIEDADES Y COMPORTAMIENTOS NECESITA.
*/

//class Contador{
//    private:
//        int valor;
//    public:
//        void incrementar();
//        void decrementar();
//        void setValor(int);
//        int getValor();
//        void Mostrar();
//};

class Alumno{
    private:
        int legajo;
        char nombre[30];
        char apellido[30];
        int dni;
        int diaNacimiento;
        int mesNacimiento;
        int anioNacimiento;
        char email[30];
    public:
        ///SETTERS
        void setLegajo(int);
        void setNombre(const char *);
        void setApellido(const char *);
        void setDni(int);
        void setDiaNacimiento(int);
        void setMesNacimiento(int);
        void setAnioNacimiento(int);
        void setEmail(const char *);
        ///GETTERS
        int getLegajo();
        const char *getNombre();
        const char *getApellido();
        int getDni();
        int getDiaNacimiento();
        int getMesNacimiento();
        int getAnioNacimiento();
        const char *getEmail();
        ///OTROS METODOS
        void Cargar();
        void Mostrar();
};

/**
DESARROLLAR LA CLASE ALUMNO PARA INSTANCIAR OBJETOS CON
LAS SIGUIENTES CARACTERISTICAS:
-LEGAJO
-NOMBRE
-APELLIDO
-DNI
-DIA, MES Y AÑO DE NACIMIENTO
-EMAIL
Y COMO COMPORTAMIENTO:
-SETTERS Y GETTERS PARA TODAS LAS PROPIEDADES
-UN CARGAR QUE LE SOLICITE AL USUARIO EL INGRESO DE VALORES
PARA TODAS LAS PROPIEDADES
-UN MOSTRAR QUE MUESTRE POR CONSOLA LOS VALORES DE TODAS
LAS PROPIEDADES
*/

#endif // CLSALUMNO_H_INCLUDED

#ifndef CLSALUMNO_H_INCLUDED
#define CLSALUMNO_H_INCLUDED

#include "clsFecha.h"
#include "clsDomicilio.h"

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

/**
AGREGARLE LA FUNCIONALIDAD NECESARIA PARA TRABAJAR CON
LA PROPIEDAD fechaInscripcion.
ADEMAS MODIFICAR LA CLASE PARA AGREGARLE EL DOMICILIO AL
ALUMNO. UN DOMICILIO NECESITA ALMACENAR LO SIGUIENTE:
-CALLE.
-ALTURA.
-CODIGO POSTAL.
-LOCALIDAD.
-PARTIDO.
-PROVINCIA.
*/

class Alumno{
    private:
        int legajo;
        char nombre[30];
        char apellido[30];
        int dni;
        Fecha fechaNacimiento;
        Fecha fechaInscripcion;
        Domicilio domicilio;
        char email[30];
    public:
        ///SETTERS
        Alumno(int leg=0, const char *nom="S/N", const char *ape="S/A", int d=0, Fecha fN=Fecha(3,3,1989), Fecha fI=Fecha(12,12,2010), const char *e="S/E");
        void setLegajo(int);
        void setNombre(const char *);
        void setApellido(const char *);
        void setDni(int);
        void setFechaNacimiento(Fecha);
        void setEmail(const char *);
        ///GETTERS
        int getLegajo();
        const char *getNombre();
        const char *getApellido();
        int getDni();
        Fecha getFechaNacimiento();
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

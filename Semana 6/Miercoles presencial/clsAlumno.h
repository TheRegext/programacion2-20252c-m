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


class Persona{
    protected:
        char nombre[30];
        char apellido[30];
        int dni;
        char telefono[15];
        Fecha fechaNacimiento;
        Domicilio domicilio;
        char email[30];
    public:
        Persona(const char *nom="S/N", const char *ape="S/A", int d=0, Fecha fN=Fecha(3,3,1989), const char *e="S/E");
        ///SETTERS
        void setNombre(const char *);
        void setApellido(const char *);
        void setDni(int);
        void setFechaNacimiento(Fecha);
        void setDomicilio(Domicilio);
        void setEmail(const char *);
        ///GETTERS
        const char *getNombre();
        const char *getApellido();
        int getDni();
        Fecha getFechaNacimiento();
        Domicilio getDomicilio();
        const char *getEmail();
        ///OTROS METODOS
        void Cargar();
        void Mostrar();
};

//class AlumnoVieja : public Persona{
//    private:
//        int legajo;
//        Fecha fechaInscripcion;
//    public:
//        int getLegajo(){return legajo;}
//        Fecha getFechaInscripcion(){return fechaInscripcion;}
//};

class Alumno : public Persona{
    private:
        int legajo;
        Fecha fechaInscripcion;
        bool estado;
    public:
        Alumno(int leg=0, Fecha fI=Fecha(12,12,2010));
        void setLegajo(int);
        void setFechaInscripcion(Fecha);
        void setEstado(bool);
        int getLegajo();
        bool getEstado();
        void Cargar(int l=-999);
        void Mostrar();
};
/**
DESARROLLAR LA CLASE ALUMNO PARA INSTANCIAR OBJETOS CON
LAS SIGUIENTES CARACTERISTICAS:
-LEGAJO
-NOMBRE
-APELLIDO
-DNI
-DIA, MES Y A�O DE NACIMIENTO
-EMAIL
Y COMO COMPORTAMIENTO:
-SETTERS Y GETTERS PARA TODAS LAS PROPIEDADES
-UN CARGAR QUE LE SOLICITE AL USUARIO EL INGRESO DE VALORES
PARA TODAS LAS PROPIEDADES
-UN MOSTRAR QUE MUESTRE POR CONSOLA LOS VALORES DE TODAS
LAS PROPIEDADES
*/

#endif // CLSALUMNO_H_INCLUDED

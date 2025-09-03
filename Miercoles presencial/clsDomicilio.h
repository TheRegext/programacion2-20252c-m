#ifndef CLSDOMICILIO_H_INCLUDED
#define CLSDOMICILIO_H_INCLUDED

class Domicilio{
    private:
        char calle[30];
        int altura;
        char codigoPostal[6];
        char localidad[30];
        char partido[30];
        char provincia[30];
    public:
        ///SETTERS Y GETTERS
        void Cargar();
        void Mostrar();
};

#endif // CLSDOMICILIO_H_INCLUDED

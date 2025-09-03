#ifndef CLSCONTADOR_H_INCLUDED
#define CLSCONTADOR_H_INCLUDED

class Contador{
    private:
        int valor;
        int valorInicial;
    public:
        Contador(int val=0);
        void setValor(int);
        int getValor();
        void Mostrar();
        void incrementar(int val=1);
        void decrementar();
        void reiniciar();
        ~Contador();
};

#endif // CLSCONTADOR_H_INCLUDED

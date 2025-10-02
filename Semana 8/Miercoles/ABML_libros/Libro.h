#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED

class Libro{
    private:
        int ISBN;
        char nombreLibro[40];
        char nombreAutor[40];
        Fecha fechaPublicacion;
        int IDPais; //(1 a 100)
        int IDGenero;///(1 a 10)
        int stock;
        bool estado;
    public:
        void Cargar();
        void Mostrar();

        ///gets
        int getISBN();
        Fecha getFechaPublicacion();
        const char *getNombreLibro();
        const char *getNombreAutor();
        int getStock();
        bool getEstado();
        int getIDPais();
        int getIDGenero();

        ///
        void setISBN(int isbn);
        void setFechaPublicacion(Fecha fe);
        void setNombreLibro(const char *l);
        void setNombreAutor(const char *l);
        void setEstado(bool e);
        void setIDPais(int p);
        void setIDGenero(int g);
        void setStock(int cant);

};



#endif // LIBRO_H_INCLUDED

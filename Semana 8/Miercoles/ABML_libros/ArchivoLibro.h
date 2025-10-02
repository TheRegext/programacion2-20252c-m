#ifndef ARCHIVOLIBRO_H_INCLUDED
#define ARCHIVOLIBRO_H_INCLUDED


class ArchivoLibros{
    private:
        char nombre[30];
        int tamanioRegistro;
    public:
        ArchivoLibros(const char *n="Libros.dat");
        int agregarRegistro(Libro reg);
        bool listarRegistros();
        int buscarRegistro(int _ISBN);
        Libro leerRegistro(int pos);
        bool modificarRegistro(Libro reg, int pos);
        int contarRegistros();
        bool bajaLogica(int _ISBN);
        bool activarRegistro (int _ISBN);
    };

#endif // ARCHIVOLIBRO_H_INCLUDED

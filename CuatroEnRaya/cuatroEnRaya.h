// archivo.h
#ifndef CuatroEnRayaH
#define CuatroEnRayaH
#include <iostream>
using namespace std ;

class CuatroEnRaya {

    public:
        CuatroEnRaya(); // Constructor por defecto
        CuatroEnRaya(int fils, int cols); // Constructor
        ~CuatroEnRaya(); //Destructor
        void comenzar(); //Comenzar el cuatro en raya
        void InicializarTablero(int fils, int cols); // Inicializa el tablero
        void pintarLimitesSuperiorInferior();//Pintar limites -----
        void pintarContenido(); // Pintar el contenido de la matriz
        void mostrarTablero();//Muestra el tablero 

    private:
        int fils; // Filas del tablero
        int cols; // Columnas del tablero
        char **tablero; //Tablero del cuatro en raya
};

#endif // ARCHIVO_H
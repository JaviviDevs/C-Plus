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

        /*Logica del juego*/
        void insertarficha(char ficha,int columna); //Inserta una ficha dado una columna 
        int gravedad(int columna); //Dado una columna, calcula la fila que le corresponde a la ficha a insertar
        int comprobarGanador(); // Comprueba si ha habido 4 en raya
        bool compruebaEnHorizontal(char ficha,int fila, int columna); //Comprueba si hay 4 en raya de forma horizontal
        bool compruebaEnVertical(char ficha,int fila, int columna); //Comprueba si hay 4 en raya de forma vertical
        bool compruebaEnDiagonal(char ficha,int fila, int columna); //Comprueba si hay 4 en raya de forma diagonal
    private:
        int fils; // Filas del tablero
        int cols; // Columnas del tablero
        char **tablero; //Tablero del cuatro en raya
        const int numeroRaya=4;
};  

#endif // ARCHIVO_H
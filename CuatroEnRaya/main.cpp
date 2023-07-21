// main.cpp
#include "cuatroEnRaya.h" // Incluimos la declaración de la clase

int main() {
    CuatroEnRaya *cuatro_en_raya=new CuatroEnRaya(); // Creamos un objeto de la clase MiClase

    cuatro_en_raya->comenzar(); // Llamamos a comenzar
    delete cuatro_en_raya; // Liberamos la memoria
    return 0;
}
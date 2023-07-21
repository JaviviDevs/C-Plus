// archivo.cpp
#include "cuatroEnRaya.h"

/********************************************************************************************/
/*************************** Creación del tablero y mostrarlo ******************************/
/*******************************************************************************************/

// Constructor por defecto
CuatroEnRaya::CuatroEnRaya() {
    this->fils=8;
    this->cols=8;
    this->InicializarTablero(this->fils,this->cols);
}

// Constructor por parámetros
// fils: numero de filas
// cols: numero de columnas
CuatroEnRaya::CuatroEnRaya(int fils, int cols){
    this->fils=fils;
    this->cols=cols;
    this->InicializarTablero(this->fils,this->cols);
}

// Inicialización del tablero
// fils: numero de filas
// cols: numero de columnas
void CuatroEnRaya::InicializarTablero(int fils, int cols){
    //Reserva del espacio dinamico
    this->tablero=new char*[fils];
    for(int i=0;i<fils;i++){
        this->tablero[i]=new char[cols];
    }

    //Inicializa la matriz a ' '
    for(int fil=0;fil<this->fils;fil++){
        for(int col=0;col<this->cols;col++){
            this->tablero[fil][col]=' ';
        }
    }
}

//Destructor
CuatroEnRaya::~CuatroEnRaya(){
    // Liberar la memoria utilizada por la matriz
    for (int i = 0; i < this->fils; ++i) {
        delete[] tablero[i];
    }
    delete[] tablero;
}

//Pinta cuando se muestra el table los limites horizontales (------)
void CuatroEnRaya::pintarLimitesSuperiorInferior(){
    for(int col=0;col<this->cols;col++){
        if(col==0){
                cout<<'-'<<'-'<<'-'<<'-'<<'-';
            }else{
                cout<<'-'<<'-'<<'-'<<'-';
        }
    }
    cout<<"\n";
}

//Pinta el contenido de la matriz en un formato adecuado visualmente | X | X | ...
void CuatroEnRaya::pintarContenido(){
    for(int fil=0;fil<this->fils;fil++){
        for(int col=0;col<this->cols;col++){
            if(col==0){
                cout<<'|'<<' '<< this->tablero[fil][col]<<' '<<'|';
            }else{
                cout<<' '<<this->tablero[fil][col]<<' '<<'|';
            }
           
        }
        cout<<"\n";
    }
}

// Muestra el tablero completo, tanto los limites como su contenido
void CuatroEnRaya::mostrarTablero(){
    this->pintarLimitesSuperiorInferior();
    this->pintarContenido();
    this->pintarLimitesSuperiorInferior();
}


/********************************************************************************************/
/*******************************************************************************************/

/********************************************************************************************/
/*********************************** Lógica del programa ************************************/
/*******************************************************************************************/

int CuatroEnRaya::gravedad(int columna){
    int fila=0;
    bool encontrado=false;

    //Se recorre la columna entera
    for(int pos_fila=0;pos_fila<this->fils && !encontrado;pos_fila++){
        if(this->tablero[pos_fila][columna]!=' '){ // Si encuentras una ficha
            fila=pos_fila-1; //Devuelves la fila superior
            encontrado=true;
        }else{
            fila=this->fils-1;
        }
    }
    return fila;
}

void CuatroEnRaya::insertarficha(char ficha,int columna){
    int fila=gravedad(columna);
    if(fila >-1){
        this->tablero[fila][columna]=ficha;
    }
   
}

// Comienza la partida
void CuatroEnRaya::comenzar() {
    int posicion_ficha=0;
    this->mostrarTablero();
    cout<<"Introduce un número del 0 al "<<(this->fils-1)<<" para insertar una ficha: " << "\n";
    cin>>posicion_ficha;
    while(posicion_ficha!=-1){
        this->insertarficha('X',posicion_ficha);
        this->mostrarTablero();
        cout<<"Introduce un número del 0 al "<<(this->fils-1)<<" para insertar una ficha: " << "\n";
        cin>>posicion_ficha;
    }
}
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
// @param fils: numero de filas
// @param cols: numero de columnas
CuatroEnRaya::CuatroEnRaya(int fils, int cols){
    this->fils=fils;
    this->cols=cols;
    this->InicializarTablero(this->fils,this->cols);
}

// Inicialización del tablero
// @param fils: numero de filas
// @param cols: numero de columnas
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
    this->fils,this->cols=0;
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

//Dado una columna, calcula la fila que le corresponde a la ficha a insertar
//@param columna: columna en la que calcula la fila
//@return fila: fila donde tiene que colocarse la ficha
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

//Inserta una ficha dado una columna 
//@param ficha: ficha a insertar (X o O)
//@param columna: columna donde insertar la ficha
void CuatroEnRaya::insertarficha(char ficha,int columna){
    int fila=gravedad(columna);
    if(fila >-1){
        this->tablero[fila][columna]=ficha;
    }
   
}

/* ############################# Logica para comprobar el ganador #########################*/

/*
//Comprueba si hay 4 en raya de forma horizontal. 
Como se recorre el tablero de izquierda a derecha, en cuanto encuentre un simbolo (X o O) 
solo comprobará si tiene otros 3 adyacentes a su derecha pues este símbolo será el 
extremo izquierdo del cuatro en raya, es decir, no puede haber a su izquierda otro símbolo igual.

@param fila: fila en la que se ha encontrado el primer simbolo
@param columna: columna en la que se ha encontrado el primer simbolo
@param ficha: X o O
@return ganador, true si hay cuatro en raya, false si no.
*/
bool CuatroEnRaya::compruebaEnHorizontal(char ficha,int fila, int columna){
    bool ganador=true;
    // Si la columna + 3 < numero de columnas, ya que si no se saldria del tablero 
    if(columna + 3 < this->cols){
        for(int pos_sig=1;pos_sig<this->numeroRaya;pos_sig++){
            if(this->tablero[fila][columna+pos_sig]!=ficha){
                ganador=false;
            }
        }
    }else{
        ganador=false;
    }

    return ganador;
} 

bool CuatroEnRaya::compruebaEnVertical(char ficha,int fila, int columna){
   bool ganador=true;
    // Si la fila - 3 < la fila 0, ya que si no se saldria del tablero 
    if(fila - 3 > 0){
        for(int pos_sig=1;pos_sig<this->numeroRaya;pos_sig++){
            if(this->tablero[fila-pos_sig][columna]!=ficha){
                ganador=false;
            }
        }
    }else{
        ganador=false;
    }

    return ganador;
} 

bool CuatroEnRaya::compruebaEnDiagonal(char ficha,int fila, int columna){
    bool ganador=false;
    return ganador;
}


/*
Comprobar ganador, empieza desde la esquina inferior izquierda, hacia la derecha y hacia arriba.
De manera que primero analiza si hay cuatro en raya en horizontal, si no hay, comprueba si hay en vertical 
y si no en diagonal.
@return cuatroEnRaya: 0 si empate, 1 si gana jugador 1, 2 si gana jugador 2
*/
int CuatroEnRaya::comprobarGanador(){
    int cuatroEnRaya=-1;
    for(int fil=this->fils-1; fil>=0 && cuatroEnRaya==-1; fil--){
        for(int col=0;col<this->cols;col++){
            if(this->tablero[fil][col]!=' '){
                if(this->compruebaEnHorizontal(this->tablero[fil][col],fil,col)){
                    cuatroEnRaya=1;
                }else if(this->compruebaEnVertical(this->tablero[fil][col],fil,col)){
                    cuatroEnRaya=1;
                }else if(this->compruebaEnDiagonal(this->tablero[fil][col],fil,col)){
                    cuatroEnRaya=1;
                }
            }
        }
    }
    return cuatroEnRaya;
} 
/*####################################################################################*/


// Comienza la partida
void CuatroEnRaya::comenzar() {
    int posicion_ficha=0;
    int ganador=-1;
    int turno=0;
    this->mostrarTablero();
    cout<<"Jugador " << turno+1 <<": Introduce un número del 0 al "<<(this->fils-1)<<" para insertar una ficha: " << "\n";
    cin>>posicion_ficha;
    while(posicion_ficha!=-1 && ganador==-1){
        if(turno%2==0){
            this->insertarficha('X',posicion_ficha);
        }else{
             this->insertarficha('O',posicion_ficha);
        }

        this->mostrarTablero();
        ganador=this->comprobarGanador();
        turno=(turno+1)%2;
        if(ganador==-1){ 
            cout<<"Jugador " << turno+1 <<": Introduce un número del 0 al "<<(this->fils-1)<<" para insertar una ficha: " << "\n";
            cin>>posicion_ficha;
        }
        
    }
    cout<<ganador;
}
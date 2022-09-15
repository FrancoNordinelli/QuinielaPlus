#include <cstddef>
#include <iostream>
#include <cstdlib>
#include "carton.h"
#include "jugador.h"
using namespace std;

struct CartonGanador{



};
struct CartonE{

    int numeros[NUMEROS_CARTON];
    string direccion = "La Timba";
    Jugador j;
};

Carton crearCartonAleatorio(){
    Carton c = new CartonE;
    c->j = crearJugador();

    c->numeros[0] = rand()%99;

    for(int i = 1; i < NUMEROS_CARTON; i++){
        int num = rand()%99;

        while(repetido(num, i, c->numeros)){
            num = rand()%99;
        }
        c->numeros[i] = num;
    }
    ordenamientoInsercion(c->numeros);
    return c;
}


Carton crearCartonManual(){

    Carton c = new CartonE;

    c->j = crearJugador();

    int num = 0;
    for(int i = 0; i < NUMEROS_CARTON ; i++){
        cout<<"Ingrese un numero: "<<endl;
        cin>>num;
        while(repetido(num, i, c->numeros)){
            cout<<"Ingrese otro numero: "<<endl;
            cin>>num;
        }
        c->numeros[i] = num;

    }
    ordenamientoInsercion(c->numeros);
    return c;
}

bool repetido(int num, int pos, int vec[]){

    bool bandera = false;

    for(int i = 0; i < pos; i++){
        if(num == vec[i]){
            bandera = true;
        }
    }

    return bandera;

}


void ordenamientoInsercion(int vector[]){

    for(int i = 1; i < NUMEROS_CARTON ; i++){
        int aux1 = vector[i];
        int k = i - 1;
        bool bandera = false;
        while(! bandera && k>=1){
            if(aux1 < vector[k]){
                vector[k+1] = vector[k];
                k = k - 1;
            }else{
                bandera = true;
            }
        }
        vector[k+1] = aux1;


    }



}


void imprimirCarton(Carton c){

    cout<<"Direccion--->"<<c->direccion<<endl;

    cout<<"[";
    for(int i = 0; i < NUMEROS_CARTON; i++){
        cout<<" "<<c->numeros[i];
    }
    cout<<"]";
}


int * getCartonNumero(Carton c){
    return c->numeros;
}

void setCartonNumero(Carton c, int n, int pos){
    c->numeros[pos] = n;
}

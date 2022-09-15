#include <cstddef>
#include <iostream>
#include <cstdlib>
#include "jugador.h"
using namespace std;


struct JugadorE{
    string nombre, apellido;
    double dni;
};

Jugador crearJugador(){

    Jugador j = new JugadorE;
    cout<<"Ingrese el nombre: ";
    cin>>j->nombre;
    cout<<"Ingrese el apellido: ";
    cin>>j->apellido;
    cout<<"Ingrese el dni: ";
    cin>>j->dni;


    return j;
}

void imprimirJugador(Jugador j){
    cout<<"Apellido: "<<j->apellido;
    cout<<"Nombre: "<<j->nombre;
    cout<<"DNI: "<<j->dni;

}

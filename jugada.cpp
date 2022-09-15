#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "jugada.h"
#include "carton.h"

using namespace std;


int * jugadas(int vector[]){

    for(int i = 0; i < BOLILLAS ; i++){
        int  num = rand()%99;


      vector[i] = num;
    }

    return vector;

}

void imprimirJugada(int vector[]){

    for(int i = 0; i < BOLILLAS; i++){
        cout<<"Bolilla "<<i<<" tiene el numero--->"<<vector[i]<<endl;
    }

}

void juego(){

    int opc = 0;
    Carton c;
    while(opc!=1 && opc!=2){
        cout<<"--------------Escoja una opcion---------"<<endl;
        cout<<"1---Escoger numeros del carton"<<endl;
        cout<<"2---Carton con números aleatorios"<<endl;
        cin>>opc;
    }
        switch(opc){
            case 1: c = crearCartonManual(); break;
            case 2: c = crearCartonAleatorio();break;
            default: cout<<"Opcion invalida"; break;

    }

    cout<<"Sus numeros"<< endl;
    imprimirCarton(c);
    printf("\n");
    cout<<"BOLILLAS"<<endl;

    int vector[BOLILLAS];
    jugadas(vector);
    imprimirJugada(vector);
    resultado(c,vector);
}

void resultado(Carton c, int vector[]){


    int acierto = 0;
    for(int i = 0; i < NUMEROS_CARTON; i++){

        for(int j = 0; j < BOLILLAS; j++){
            if(getCartonNumero(c)[i] == vector[j]){
                acierto++;
                setCartonNumero(c, 0, i);
            }
        }

    }

    printf("\n");
    if(acierto == 8){
        cout<<"FELICIDADES. GANO 11 MILLONES!!!!"<<endl;
    }
    if(acierto == 7){
        cout<<"FELICIDADES. GANO 20 MIL!!!!"<<endl;
    }
    if(acierto == 6){
        cout<<"FELICIDADES. GANO 500!!!!"<<endl;
    }
    if(acierto == 5){
        cout<<"FELICIDADES. GANO 50!!!!"<<endl;
    }
    printf("\n");
    cout<<"Aciertos---->"<<acierto;
    printf("\n");
    ofstream file;
    file.open("C:/Users/Usuario/Desktop/AYED2022/QuinielaPlus/quiniela.txt");
    //file<< "imprimirCarton(c)";
    file.close();
}

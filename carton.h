#ifndef CARTON_H_INCLUDED
#define CARTON_H_INCLUDED
#define NUMEROS_CARTON 8



struct CartonE;

typedef struct CartonE * Carton;

Carton crearCartonAleatorio();

Carton crearCartonManual();

bool repetido(int num, int pos, int vec[]);

void ordenamientoInsercion(int vector[]);

void imprimirCarton(Carton c);

void imprimirJugada(int vector[]);

int * getCartonNumero(Carton c);

void setCartonNumero(Carton c, int n, int pos);
#endif

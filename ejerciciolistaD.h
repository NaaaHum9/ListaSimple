#ifndef _listaDoble_
#define _listaDoble_

#define TRUE 1
#define FALSE 0

#include <stdlib.h>
#include <stdio.h>

typedef struct Nodo_ListaD{
    int dato;
    struct Nodo_ListaD * sig;
    struct Nodo_ListaD * ant;

}Nodo_ListaD;

typedef Nodo_ListaD* LISTA_D;

LISTA_D crearListaD();
int es_vaciaListaD(LISTA_D L);
Nodo_ListaD * crearNodoListaD();
LISTA_D insertar(LISTA_D L, int e);
void mostrarListaD(LISTA_D L);
void mostrarListaD2(LISTA_D L);
void buscarElemD(LISTA_D L, int e);
LISTA_D borrarD(LISTA_D, int e);

#endif
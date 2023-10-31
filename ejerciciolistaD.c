#include "ejerciciolistaD.h"

void manejaError(int);
void mensajes(int, int, int);

//crea una lista vacia
LISTA_D crearListaD(){
    LISTA_D L;
    L = NULL;
    return L;
}

//esta vacia la lista
int es_vaciaListaD(LISTA_D L){
    if (L == NULL){
        return TRUE;
    }else{
        return FALSE;
    }
    
}

//crea un elemento de la lista
Nodo_ListaD * crearNodoListaD(){
    Nodo_ListaD * nvo;
    nvo = (Nodo_ListaD *)malloc(sizeof(Nodo_ListaD));
    if (nvo == NULL){
        manejaError(0);
        exit(0);
    }
    nvo->sig = NULL;
    nvo->ant = NULL;
    return nvo;

}

//agrega un elemento a la lista
LISTA_D insertar(LISTA_D L, int e){
    Nodo_ListaD * nvo;
    Nodo_ListaD * aux, * aux2;
    nvo = crearNodoListaD();
    nvo->dato = e;
    if (es_vaciaListaD(L) == TRUE){
        L = nvo;
    }else{
        aux = L;
        while (aux != NULL){
            aux2 = aux;
            aux = aux->sig;
        }
        aux2->sig = nvo;
        nvo->ant = aux2;
        nvo->sig = aux;
    }
    return L;
}

//agrega elementos a la pila
void mostrarListaD(LISTA_D L){
    Nodo_ListaD * aux;
    int pos;
    aux = L;
    if (es_vaciaListaD(L) == TRUE){
        manejaError(7);//lista doble vacia
        exit(0);
    }
    pos = 1;
    while (aux != NULL){
        mensajes(aux->dato, 1, pos);
        pos++;
        aux = aux->sig;
    }
    
}

void mostrarListaD2(LISTA_D L){
    Nodo_ListaD * aux, * aux2;
    int pos;
    aux = NULL;
    aux2 = L;
    pos = 10;
    if (es_vaciaListaD(L) == TRUE){
        manejaError(7);
        exit(0);
    }
    while (aux2 != NULL){
        mensajes(aux2->dato, 1, pos);
        pos--;
        aux2 = aux2->sig;
        
    }
    L = aux2;
}

//buscar un elemento de la lista
void buscarElemD(LISTA_D L, int e){
    Nodo_ListaD * aux;
    int pos=1;
    aux = L;
    if (es_vaciaListaD(L) == TRUE){
        manejaError(7);//lista doble vacia
        exit(0);
    }
    while (aux != NULL && e != aux->dato){
        aux = aux->sig;
        pos++;
    }
    if (aux == NULL){
        mensajes(e, 0, 0);//no se encuentra
    }else{
        mensajes(e, 2, pos);//indica la posicion
    }
    
}

//borra un elemento de la lista
LISTA_D borrarD(LISTA_D L, int e){
    Nodo_ListaD * aux, *aux2;
    if (es_vaciaListaD(L) == TRUE){
        manejaError(7);//lista doble vacia
        exit(0);
    }
    aux = aux2 = L;
    while (aux != NULL && e != aux->dato){
        aux2 = aux;
        aux = aux->sig;
    }
    if (aux == NULL){
        mensajes(e, 0, 0);
    } else if (aux2 == aux){
        L = aux2->sig;
        if (aux2->sig != NULL){
            L->ant = NULL;
            free(aux2);
        }
        
    }else{
        aux2->sig = aux->sig;
        if (aux->sig != NULL){
            aux->sig->ant = aux->ant;
        }
        free(aux);
    }
    return L;
}
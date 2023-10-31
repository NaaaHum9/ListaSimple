#include "ejerciciolistaD.h"

int pedirDatos(LISTA_D);
void liberarMem(LISTA_D);
void mensajes(int, int, int);
void manejaError(int);

int main(){
    LISTA_D L1, L2;

    L1 = crearListaD();
    pedirDatos(L1);
    liberarMem(L1);

    return 0;
}

int pedirDatos(LISTA_D L1){
    int num=0, elem, aux;

    do{
        printf("\nSeleccione una opcion: \n");
        printf("1 - Insertar elemento a la lista\n");
        printf("2 - Mostrar lista\n");
        printf("3 - Buscar elemento en la lista\n");
        printf("4 - Borrar elemento de la lista\n");
        printf("5 - Salir\n");
        scanf("%i", &num);
        printf("\n");
        switch (num){
        case 1:
            printf("Ingrese un elemento: ");
            scanf("%i", &aux);
            L1 = insertar(L1, aux);
            break;
        case 2:
            mostrarListaD(L1);
            printf("\n\n\nLista invertida:\n");
            mostrarListaD2(L1);
            break;
        case 3:
            printf("Ingrese el elemento a buscar: ");
            scanf("%i", &aux);
            buscarElemD(L1, aux);
            break;
        case 4: 
            printf("Ingrese el elemento a borrar: ");
            scanf("%i", &aux);
            borrarD(L1, aux);
            break;
        case 5:
            break;
        }
    } while (num != 5);
    
}

void liberarMem(LISTA_D L1){
    free(L1);
    manejaError(1);
}

void mensajes(int e, int msg, int p){
    int i;
    if (msg == 0){
        printf("El elemento %i no se encuantra en la lisat\n", e);
    }else if (msg == 1){
        printf("\nDatos de la lista\n Nodo %i = %i\n", p, e);
    }else{
        printf("El elemento %i se encuantra en la posicion %i\n", e, p);
    }

}

void manejaError(int msg){
    char * mensajes[] = {"\n\nNo hay memoria disponible", "\n\nSe ha liberado la memoria", 
                        "\n\nPila llena", "\n\nPila vacia", "\n\nCola llena", "\n\nCola vacia",
                        "\n\nLista llena", "\n\nLista vacia"};
    printf("%s", mensajes[msg] );
}

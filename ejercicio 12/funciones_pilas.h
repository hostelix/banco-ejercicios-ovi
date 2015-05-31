#include <stdlib.h>
#include <stdio.h>
#include <string.h>



#define TIPO_PASEO 1
#define TIPO_CAMBIO 2


typedef struct{
    char marca[20];
    int tipo;
    float valor;
}Moto;

typedef struct{
    char nombre[10];
    int cedula;
    Moto *moto_comprada;
}Factura;


typedef struct _nodo{
    Factura factura;
    struct _nodo *siguiente;
}Nodo;

typedef Nodo *TNodo;
typedef Nodo *Pila;

void anadir_pila(Pila *pila, Factura datos){
    TNodo nodo = (TNodo)malloc(sizeof(Nodo));

    nodo->siguiente = *pila;
    nodo->factura = datos;

    *pila = nodo;
}

void mostrar_pila(Pila *pila){
    TNodo nodo;

    nodo = *pila;

    while(nodo){
        printf("[%d - %s] -> {%s - %s - %f}\n",nodo->factura.cedula,nodo->factura.nombre,nodo->factura.moto_comprada->marca
        ,(nodo->factura.moto_comprada->tipo == TIPO_CAMBIO)?("CAMBIO"):("PASEO"), nodo->factura.moto_comprada->valor);
        nodo = nodo->siguiente;
    }
}


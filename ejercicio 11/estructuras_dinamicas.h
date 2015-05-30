#include <stdlib.h>
#include <stdio.h>

typedef struct{
	char nombre[10];
	int cedula;
	char institucion[30];
	unsigned short int gremio;
}Persona;



/* PILAS */
typedef struct _pnodo{
	Persona datos;
	struct _pnodo *siguiente;
}Nodo;

typedef Nodo *TNodo;
typedef Nodo *Pila;


/* COLAS */

typedef struct{
	Nodo *primero;
	Nodo *ultimo;
}TCola;

typedef Nodo *TNodo;
typedef TCola *Cola;


/* LISTA */

typedef Nodo *TLNodo;
typedef Nodo *Lista;

/* Funciones Pilas */

void anadir_pila(Pila *pila, Persona _persona){
	TNodo nuevo_nodo = (TNodo)malloc(sizeof(Nodo));

	nuevo_nodo->datos = _persona;
	nuevo_nodo->siguiente = *pila;

	*pila = nuevo_nodo;
}

Persona eliminar_elemento_pila(Pila *pila){
    TNodo nodo;
    Persona tmp;
    nodo = *pila;

    if(nodo){
        tmp = nodo->datos;
        *pila = nodo->siguiente;

        free(nodo);
    }
    return tmp;
}

void mostrar_pila(Pila *pila){
	TNodo nodo = (TNodo)malloc(sizeof(Nodo));

	nodo = *pila;
	while(nodo){
		printf("[%s - %d - %s - %d]\n",nodo->datos.nombre,nodo->datos.cedula,nodo->datos.institucion,nodo->datos.gremio);
		nodo = nodo->siguiente;
	}
}

/* Funciones Colas */
void anadir_cola(Cola *cola, Persona datos){
	TNodo nuevo_nodo = (TNodo)malloc(sizeof(Nodo));
	nuevo_nodo->datos = datos;

	if((*cola)->ultimo){
		(*cola)->ultimo->siguiente = nuevo_nodo;
	}

	if((*cola)->primero == NULL){
		(*cola)->primero = nuevo_nodo;
	}
	(*cola)->ultimo = nuevo_nodo;
}

Persona eliminar_elemento_cola(Cola *cola){
    TNodo nodo;
    Persona tmp;

    nodo = (*cola)->primero;
    if(nodo == NULL){
        return tmp;
    }
    (*cola)->primero = nodo->siguiente;
    tmp = nodo->datos;

    free(nodo);

    if((*cola)->primero == NULL){
        (*cola)->ultimo = NULL;
    }
    return tmp;
}

void mostrar_cola( Cola *cola){
	TNodo nodo = (TNodo)malloc(sizeof(Nodo));

	nodo = (*cola)->primero;
	while(nodo){
		printf("[%s - %d - %s - %d]\n",nodo->datos.nombre,nodo->datos.cedula,nodo->datos.institucion,nodo->datos.gremio);
		nodo = nodo->siguiente;
	}
}

/*Funciones Lista */

void anadir_lista(Lista *lista, Persona datos){
   TLNodo nuevo, anterior;

   /* Crear un nodo nuevo */
   nuevo = (TLNodo)malloc(sizeof(Nodo));
   nuevo->datos = datos;


   if(!*lista || ((*lista)->datos.cedula > datos.cedula)) {
      nuevo->siguiente = *lista;
      *lista = nuevo;
   }
   else {
      anterior = *lista;

      while(anterior->siguiente && (anterior->siguiente->datos.cedula <= datos.cedula)){
         anterior = anterior->siguiente;
      }
      nuevo->siguiente = anterior->siguiente;
      anterior->siguiente = nuevo;
    }
}


void mostrar_lista(Lista *lista, int tipo){
    TNodo nodo = (TNodo)malloc(sizeof(Nodo));

	nodo = *lista;
	while(nodo){
        if(nodo->datos.gremio == tipo){
            printf("[%s - %d - %s - %d]\n",nodo->datos.nombre,nodo->datos.cedula,nodo->datos.institucion,nodo->datos.gremio);
        }
        if(tipo == 3){
            printf("[%s - %d - %s - %d]\n",nodo->datos.nombre,nodo->datos.cedula,nodo->datos.institucion,nodo->datos.gremio);
        }
		nodo = nodo->siguiente;
	}
}

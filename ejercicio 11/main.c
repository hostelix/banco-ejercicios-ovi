#include "estructuras_dinamicas.h"

#define ESTUDIANTE 1
#define DOCENTE 2
#define TODO 3


Persona registrar_persona();
void llenar_lista(Pila *pila, Cola *cola, Lista *lista);

int main(int argc, char *argv[]) {
	int op;
	int generada_lista = 0;
	Pila pila_docentes = NULL;
	Cola cola_estudiantes = (Cola)malloc(sizeof(TCola));
	cola_estudiantes->primero = NULL;
	cola_estudiantes->ultimo = NULL;
	Lista lista = NULL;

	do{
		printf("###### OLIMPIADAS VENEZOLANAS DE INFORMATICA #####\n");
		printf("1) Registrar docente\n");
		printf("2) Registrar estudiante\n");
		printf("3) Generar listado\n");
		printf("4) Mostrar listado de docentes\n");
		printf("5) Mostrar listado de estudiantes\n");
		printf("6) Mostrar listado completo\n");
		printf("7) Salir\n");
		scanf("%d",&op);

		switch(op){
			case 1:
				anadir_pila(&pila_docentes,registrar_persona(DOCENTE));
			break;
			case 2:
                anadir_cola(&cola_estudiantes,registrar_persona(ESTUDIANTE));
            break;
			case 3:
				llenar_lista(&pila_docentes,&cola_estudiantes,&lista);
				generada_lista = 1;
			break;
			case 4:
                if(lista == NULL){
                    printf("No hay personas registradas\n");
                }
                else{
                    mostrar_lista(&lista,DOCENTE);
                }
			break;
			case 5:
                if(lista == NULL){
                    printf("No hay personas registradas\n");
                }
                else{
                    mostrar_lista(&lista,ESTUDIANTE);
                }
			break;
			case 6:
                (generada_lista)?(mostrar_lista(&lista,TODO)):(printf("No has seleccionado la opcion 3 del menu\n"));
			break;
			case 7:
				exit(EXIT_SUCCESS);
			break;
		}

	}while(1);

	return 0;
}

Persona registrar_persona(int tipo_gremio){
	Persona tmp;

	printf("\n-------- Registro de persona --------\n");
	printf("Introduce tu nombre >");
	scanf("%s",tmp.nombre);

	printf("Introduce el numero cedula >");
	scanf("%d",&tmp.cedula);

	printf("Introduce el nombre de la institucion >");
	scanf("%s",tmp.institucion);

	tmp.gremio = tipo_gremio;

	return tmp;
}

void llenar_lista(Pila *pila, Cola *cola, Lista *lista){
    TNodo nodo;

    nodo = *pila;
    while(nodo){
        anadir_lista(lista,eliminar_elemento_pila(pila));
        nodo = nodo->siguiente;
    }

    nodo = (*cola)->primero;
    while(nodo){
        nodo = nodo->siguiente;
        anadir_lista(lista,eliminar_elemento_cola(cola));
    }
}

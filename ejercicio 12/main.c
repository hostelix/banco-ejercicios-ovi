#include "funciones_pilas.h"

#define MAX_INVENT 4

#define SALTO_LINEA printf("\n");

void llena_inventario(Moto *motos);
void mostrar_motos(Moto *motos);
void registrar_factura(Pila *pila, Moto *motos);

int contar_motos_tipo(Pila *pila, int tipo);
int contar_motos_marca(Pila *pila, const char *marca);
int contar_motos(Pila *pila);

float total_vendido(Pila *pila);

int main(){
    int op;
    Moto *lista_motos = (Moto*)malloc(sizeof(Moto)*MAX_INVENT);
    Pila pila_facturas = NULL;

    llena_inventario(lista_motos);

    do{
        SALTO_LINEA
        printf("$$$$$$------ TIENDA DE MOTOS --------$$$$$$\n");
        printf("1)Comprar moto\n");
        printf("2)Cantidad de motos vendidas por marca\n");
        printf("3)Cantidad de motos vendidas por tipo\n");
        printf("4)Cantidad de motos vendidas por marca y tipo\n");
        printf("5)Mostrar facturas\n");
        printf("6)Ingresos de la empresa\n");
        printf("7)Salir\n");
        scanf("%d",&op);


        switch(op){
            case 1:
                registrar_factura(&pila_facturas,lista_motos);
            break;
            case 2:
                SALTO_LINEA
                printf("Cantidad de motos vendidas 'HONDA' >> %d\n",contar_motos_marca(&pila_facturas,"HONDA"));
                printf("Cantidad de motos vendidas 'DUCATY' >> %d\n",contar_motos_marca(&pila_facturas,"DUCATY"));
                printf("Cantidad de motos vendidas 'BERA' >> %d\n",contar_motos_marca(&pila_facturas,"BERA"));
                printf("Cantidad de motos vendidas 'EMPIRE' >> %d\n",contar_motos_marca(&pila_facturas,"EMPIRE"));
            break;

            case 3:
                SALTO_LINEA
                printf("Cantidad de motos vendidas tipo 'PASEO' >> %d\n",contar_motos_tipo(&pila_facturas,TIPO_PASEO));
                printf("Cantidad de motos vendidas tipo 'CAMBIO' >> %d\n",contar_motos_tipo(&pila_facturas,TIPO_CAMBIO));
            break;

            case 4:
                SALTO_LINEA
                printf("Total de motos venedidas >> %d\n",contar_motos(&pila_facturas));
            case 5:
                SALTO_LINEA
                printf("FACTURAS\n");
                mostrar_pila(&pila_facturas);
            break;

            case 6:
                SALTO_LINEA
                printf("La industria genero una ganancia de %f\n",total_vendido(&pila_facturas));
            break;
            case 7:
                exit(1);
            break;
        }
    }while(1);


    return 0;
}

void llena_inventario(Moto *motos){

    strcpy(motos[0].marca,"BERA");
    motos[0].tipo = TIPO_PASEO;
    motos[0].valor = 19.7868;

    strcpy(motos[1].marca,"EMPIRE");
    motos[1].tipo = TIPO_CAMBIO;
    motos[1].valor = 16.76;

    strcpy(motos[2].marca,"HONDA");
    motos[2].tipo = TIPO_PASEO;
    motos[2].valor = 35.548;

    strcpy(motos[3].marca,"DUCATY");
    motos[3].tipo = TIPO_CAMBIO;
    motos[3].valor = 23.778;
}

void mostrar_motos(Moto *motos){
    int i;
    for(i=0;i<MAX_INVENT;i++){
        printf("[%d] >> %s - %f\n",i+1,motos[i].marca,motos[i].valor);
    }
}


void registrar_factura(Pila *pila, Moto *motos){
    int num;
    Factura fac;

    printf("Que moto desea comprar?\n");
    mostrar_motos(motos);
    scanf("%d",&num);

    if(num > 0 && num <= MAX_INVENT){
        printf("Nombre del cliente: ");
        scanf("%s",fac.nombre);

        printf("Cedula del cliente: ");
        scanf("%d",&fac.cedula);

        fac.moto_comprada = &motos[num-1];

        anadir_pila(pila,fac);

    }else{
        printf("opcion no valida\n");
    }
}

int contar_motos_tipo(Pila *pila, int tipo){
    TNodo nodo;
    int tmp = 0;
    nodo = *pila;
    for(nodo;nodo;nodo = nodo->siguiente){
        if(nodo->factura.moto_comprada->tipo == tipo) tmp++;
    }
    return tmp;
}

int contar_motos_marca(Pila *pila, const char *marca){
 TNodo nodo;
    int tmp = 0;
    nodo = *pila;
    for(nodo;nodo;nodo = nodo->siguiente){
        if(strcmp(nodo->factura.moto_comprada->marca,marca) == 0) tmp++;
    }
    return tmp;
}

int contar_motos(Pila *pila){
TNodo nodo;
    int tmp = 0;
    nodo = *pila;
    for(nodo;nodo;nodo = nodo->siguiente){
        tmp++;
    }
    return tmp;
}

float total_vendido(Pila *pila){
    TNodo nodo;
    float tmp = 0;
    nodo = *pila;
    for(nodo;nodo;nodo = nodo->siguiente){
        tmp+=nodo->factura.moto_comprada->valor;
    }
    return tmp;
}

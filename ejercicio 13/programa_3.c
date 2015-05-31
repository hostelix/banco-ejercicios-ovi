#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}Fecha;

typedef struct{
    int id;
    char nombre[10];
    char apellido[15];
    Fecha fecha_ingreso;
    float sueldo;
}Vigilante;

int generar_id(int *id);
Fecha get_fecha();
Vigilante registrar_vigilante(int *id);
void cargar_vigilantes();
void mostrar_vigilantes(Vigilante *lista,int dia, int mes, int max);
void mostrar_todos_vigilantes(Vigilante *lista, int max);

int main(){
    int num, id = 1, op, dia, mes;



    printf("Introduce el numero de vigilantes que se registraran >");
    scanf("%d",&num);

    Vigilante lista[num];

    cargar_vigilantes(&lista,num,&id);

    do{
        printf("\n \tVigilantes Centinelas \n");
        printf("1)Mostrar vigilantes por fecha\n");
        printf("2)Mostrar todos los vigilantes registrados \n");
        printf("3)Salir\n");
        scanf("%d",&op);

        switch(op){

            case 1:
                printf("Ingrese el dia y el mes que desea realizar la busqueda\n");
                printf(">");scanf("%d",&dia);
                printf(">");scanf("%d",&mes);
                mostrar_vigilantes(lista,dia,mes,num);
            break;

            case 2:
                mostrar_todos_vigilantes(lista,num);
            break;

            case 3:
                exit(EXIT_SUCCESS);
            break;
        }
    }while(1);

    return 0;
}


int generar_id(int *id){
    *id++;
    return *id;
}

Fecha get_fecha(){
    Fecha tmp;
    printf("Introduce el dia >");
    scanf("%d",&tmp.dia);

    printf("Introduce el mes >");
    scanf("%d",&tmp.mes);

    printf("Introduce el anio >");
    scanf("%d",&tmp.ano);

    return tmp;
}

Vigilante registrar_vigilante(int *id){
    Vigilante tmp;

    tmp.id = generar_id(id);
    printf("Nombre del vigilante >");
    scanf("%s",tmp.nombre);
    printf("Apellido del vigilante >");
    scanf("%s",tmp.apellido);
    printf("Fecha de ingreso\n");
    tmp.fecha_ingreso = get_fecha();
    printf("Sueldo del vigilante >");
    scanf("%f",&tmp.sueldo);

    return tmp;
}

void cargar_vigilantes(Vigilante *lista, int max, int *id){
    int i;
    for(i=0;i<max;i++){
        printf("\n### Datos del vigilate [%d] ###\n",i+1);
        *(lista+i) = registrar_vigilante(id);
    }
}

void mostrar_todos_vigilantes(Vigilante *lista, int max){
    int i;
    printf("\n### Vigilantes registrados ###\n");
    for(i=0;i<max;i++){
        printf("(%d)[%s %s][%f][%d/%d/%d]\n",lista->id,lista->nombre,lista->apellido,lista->sueldo,lista->fecha_ingreso.dia,lista->fecha_ingreso.mes,lista->fecha_ingreso.ano);
    }
}

void mostrar_vigilantes(Vigilante *lista,int dia, int mes, int max){
    int i;
    printf("\n### Resultados de busqueda dia %d mes %d###\n",dia,mes);
    for(i=0;i<max;i++){
        if(dia == lista->fecha_ingreso.dia && mes == lista->fecha_ingreso.mes){
            printf("(%d)[%s %s][%f][%d/%d/%d]\n",lista->id,lista->nombre,lista->apellido,lista->sueldo,lista->fecha_ingreso.dia,lista->fecha_ingreso.mes,lista->fecha_ingreso.ano);
        }
    }
}


#include <stdlib.h>
#include <stdio.h>


typedef struct{
    char nombre[20];
    char apellido[20];
    int cedula;
    int edad;
    float nota;
}Alumno;

typedef struct{
    int maximo;
    Alumno *estudiantes;
}Aula;


void buscar_mayor_nota(Aula *salon);
Alumno registrar_alumno();
void registrar_salon(Aula *salon);
void buscar_reprobados(Aula *salon);
void buscar_aprobados(Aula *salon);

int main(){
    Aula salon;
    int op;

    do{
        printf("\nRegistro de salor de clase\n");
        printf("1)Registrar salon\n");
        printf("2)Ver estudiante con mayor nota\n");
        printf("3)Ver estudiantes aprobados\n");
        printf("4)Ver estudiantes reprobados\n");
        printf("5)Salir\n");
        scanf("%d",&op);

        switch(op){
            case 1:
                registrar_salon(&salon);
            break;
            case 2:
                buscar_mayor_nota(&salon);
            break;
            case 3:
                buscar_aprobados(&salon);
            break;
            case 4:
                buscar_reprobados(&salon);
            break;
            case 5:
                exit(EXIT_SUCCESS);
            break;
        }

    }while(1);

}


Alumno registrar_alumno(){
    Alumno tmp;

    printf("Nombre del alumno >");
    scanf("%s",tmp.nombre);

    printf("Apellido del alumno >");
    scanf("%s",tmp.apellido);

    printf("Cedula del alumno >");
    scanf("%d",&tmp.cedula);

    printf("Edad del alumno >");
    scanf("%d",&tmp.edad);

    do{
        printf("Nota del alumno >");
        scanf("%f",&tmp.nota);

        if(!(tmp.nota>0 && tmp.nota<=20)){
            printf("Nota invalida\n");
        }
    }while(!(tmp.nota>0 && tmp.nota<=20));

    return tmp;
}


void registrar_salon(Aula *salon){
    int max,i;

    do{
        printf("Introduzca el maximo numero de estudiante que tendra el salon > ");
        scanf("%d",&max);
        if(max > 0 && max <= 10){
            salon->maximo = max;

            salon->estudiantes = (Alumno*)malloc(sizeof(Alumno)*max);

            for(i=0;i<max;i++){
                printf("\n Estudiante [%d]\n",i+1);
                salon->estudiantes[i] = registrar_alumno();
            }
        }
    }while(!(max > 0 && max <= 10));

}

void buscar_mayor_nota(Aula *salon){
    int i;
    Alumno tmp;
    tmp.nota = 0.0;

    for(i=0;i<salon->maximo;i++){
        if(salon->estudiantes[i].nota > tmp.nota){
            tmp = salon->estudiantes[i];
        }
    }

    printf("\nEl estudiante con la mayor calificacion [%f] >> {%s %s - %d [%d]}\n",tmp.nota,tmp.nombre,tmp.apellido,tmp.cedula,tmp.edad);
}

void buscar_reprobados(Aula *salon){
    int i;
    Alumno tmp;
    for(i=0;i<salon->maximo;i++){
        if(salon->estudiantes[i].nota < 10){
        tmp = salon->estudiantes[i];
            printf("\nEstudiante calificacion [%f] >> {%s %s - %d [%d]}\n",tmp.nota,tmp.nombre,tmp.apellido,tmp.cedula,tmp.edad);
        }
    }
}

void buscar_aprobados(Aula *salon){
    int i;
    Alumno tmp;
    for(i=0;i<salon->maximo;i++){
        if(salon->estudiantes[i].nota >= 10){
            tmp = salon->estudiantes[i];
            printf("\nEstudiante calificacion [%f] >> {%s %s - %d [%d]}\n",tmp.nota,tmp.nombre,tmp.apellido,tmp.cedula,tmp.edad);
        }
    }
}


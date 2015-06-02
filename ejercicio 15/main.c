#include <stdlib.h>
#include <stdio.h>


#define FEMENINO 1
#define MASCULINO 2
#define TODOS 3

typedef struct{
    float altura;
    float peso;
    int sexo;
}Persona;


Persona registrar_persona();
void procesar_censo(Persona *arreglo, int tam);
float promedio_peso(Persona *arreglo, int sexo, int tam);
float promedio_altura(Persona *arreglo, int sexo, int tam);


int main(){
    int op, num;
	Persona *vector = NULL;
	
    printf("Ingrese la cantidad de personas que seran censadas >");
    scanf("%d",&num);

    vector = (Persona*)malloc(sizeof(Persona)*num);

    procesar_censo(vector,num);

    do{
        printf("\n BIENVENIDO A FUNDACOMUNAL\n");
        printf("1)Peso promedio de la poblacion masculina\n");
        printf("2)Peso promedio de la poblacion femenina\n");
        printf("3)Estatura promedio de la poblacion masculina\n");
        printf("4)Estatura promedio de la poblacion femenina\n");
        printf("5)Peso promedio de la poblacion\n");
        printf("6)Estatura promedio de la poblacion\n");
        printf("7)Salir\n");
        scanf("%d",&op);


        switch(op){
            case 1:
                printf("$ El peso promedio de la poblacion masculina [%f]\n",promedio_peso(vector,MASCULINO,num));
            break;
            case 2:
				printf("$ El peso promedio de la poblacion femenina[%f]\n",promedio_peso(vector,FEMENINO,num));
            break;
            case 3:
				printf("$ La estatura promedio de la poblacion masculina [%f]\n",promedio_altura(vector,MASCULINO,num));
            break;
            case 4:
				printf("$ La estatura promedio de la poblacion femenina [%f]\n",promedio_altura(vector,FEMENINO,num));
            break;
            case 5:
				printf("$ El peso promedio de la poblacion [%f]\n",promedio_peso(vector,TODOS,num));
            break;
            case 6:
				printf("$ La estatura promedio de la poblacion [%f]\n",promedio_altura(vector,TODOS,num));
            break;
            case 7:
                exit(EXIT_SUCCESS);
            break;
        };
    }while(1);

}


Persona registrar_persona(){
    Persona tmp;

    do{
        printf("Introduce tu peso >");
        scanf("%f",&tmp.peso);

        if(tmp.peso < 0) printf("Error, peso no valido\n");
    }while(tmp.peso < 0);
	
	do{
		printf("Introduce tu estatura >");
		scanf("%f",&tmp.altura);
		
		if(tmp.altura < 0 || tmp.altura > 3) printf("Error, estatura no valida\n");
	}while(tmp.altura < 0 || tmp.altura > 3);
	
	do{
		printf("Introduce tu Sexo 1-[FEMENINO] ... 2-[MASCULINO] >");
		scanf("%d",&tmp.sexo);
		
		if(tmp.sexo <= 0 || tmp.sexo >= 3) printf("Error, sexo no sexo\n");
	}while(tmp.sexo <= 0 || tmp.sexo >= 3);
	
	return tmp;
	
}

void procesar_censo(Persona *arreglo, int tam){
	int i;
	for(i=0;i<tam;i++){
		printf("Datos persona Nro# %d\n",i+1);
		arreglo[i]=registrar_persona();
	}
}

float promedio_peso(Persona *arreglo, int sexo, int tam){
	int i,num_perso;
	float acum_tmp = 0.0;
	
	for(i=0;i<tam;i++){
		if(sexo == arreglo[i].sexo){
			num_perso++;
			acum_tmp+=arreglo[i].peso;
		}
		else if(sexo == TODOS){
			num_perso++;
			acum_tmp+=arreglo[i].peso;
		}
	}
	
	return (float)acum_tmp/num_perso;
}
float promedio_altura(Persona *arreglo, int sexo, int tam){
	int i,num_perso;
	float acum_tmp = 0.0;
	
	for(i=0;i<tam;i++){
		if(sexo == arreglo[i].sexo){
			num_perso++;
			acum_tmp+=arreglo[i].altura;
		}
		else if(sexo == TODOS){
			num_perso++;
			acum_tmp+=arreglo[i].altura;
		}
	}
	
	return (float)acum_tmp/num_perso;
}

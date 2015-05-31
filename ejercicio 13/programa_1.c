#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,cnt = 1;
    int *arreglo_pares = NULL;

   for(i =0 ; i<100; i++){
        if(i%2 == 0){
            if(arreglo_pares == NULL){
                arreglo_pares = (int*)malloc(sizeof(int)*cnt);
            }
            else{
                arreglo_pares = (int*)realloc(arreglo_pares,sizeof(int)*cnt);
            }
            arreglo_pares[cnt-1] = i;
            cnt++;
        }
    }

    for(i=0;i<cnt;i++){
        printf("[%d]",arreglo_pares[i]);
    }

}

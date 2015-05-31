#include <stdlib.h>
#include <stdio.h>

int main(){
    float total_pagar, descuento = 0.00;
    int total_compra;

    printf("##### Bienvenido a CASABLANCA ######\n");
    printf("Introduce el total de tu compra >");
    scanf("%d",&total_compra);

    if(total_compra > 0){
        if(total_compra < 5000){
            descuento = 0.20;
        }
        else if(total_compra >200000){
            descuento = 0.10;
        }
        else if(total_compra >=  5000 && total_compra <=20000){
            descuento = 0.15;
        }
    }else{
        printf("Tu compra tiene que ser mayor a cero\n");
    }

    total_pagar = total_compra - (total_compra*descuento);
    printf("El total de la compra: %d\n",total_compra);
    printf("El total a pagar: {%f} con descuento de {%0.f porciento}\n",total_pagar,descuento*100);
}

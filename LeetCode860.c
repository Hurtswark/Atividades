#include <stdio.h.>
#include <stdlib.h>
#include <stdbool.h>

bool lemonadeChange(int* bills, int billsSize) {

int cinco = 0;
int dez = 0;

    for(int i = 0; i < billsSize; i++){
        if(bills[i] == 5){
            cinco++;
        }
        else if(bills[i] == 10){
            if(cinco > 0){
                cinco--;
                dez++;
            }
            else{
                return false;
            }
        }else{
            if(cinco > 0 && dez > 0){
                cinco--;
                dez--;
            }
            else if(cinco >= 3){
                cinco -=3;
            }
        }
    }
    return true;
}



int main(){
    int contas[] = {5,5,5,10,5,20,5,10,5,20};
    bool resultado;
    int tamanho = 10;

    resultado = lemonadeChange(contas,tamanho);
    
    if(resultado){
        printf("TROCO BEM RECEBIDO");
    }
    else{
        printf("TROCO MAL RECEBIDO!");
    }
    
}
#include <stdio.h.>
#include <stdlib.h>
#include <stdbool.h>

bool lemonadeChange(int* bills, int billsSize) {

 int *troco = (int*) calloc(billsSize, sizeof(int));

 for(int i = 0; i < billsSize;i++){

    switch(bills[i]){

        case 5: troco[i] = bills[i];
        break;

        case 10:
                bool achouDez = false;
                for(int k = 0; k < billsSize;k++){
                    if(troco[k] == 5){
                        troco[k] = 10;
                        achouDez = true;
                        break;
                    }
                }
                if(achouDez){
                    break;
                }
                else{
                    return false;
                }
        case 20:
                bool achouVinte = false;
               for(int l = 0; l <billsSize; l++){
                    for(int j = l + 1; j < billsSize; j++){
                        if(troco[l] == 10 && troco[j] == 5){
                            troco[l] = 20;
                            troco[j] = 0;
                            achouVinte = true;
                            break;
                        }
                    }
                    break;
                }
                if(achouVinte){
                    break;
                }
                else{
                    return false;
                }
    }
}
    free(troco);
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
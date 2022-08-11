#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void merge_sort(int numeros[],int primeiro_indice,int tamanho);

int main(int argc, string argv[])
{
    int qte_nums = argc-1;
    int numeros[qte_nums];
    for (int i=0;i<qte_nums;i++) numeros[i] = atoi(argv[i+1]);
    printf("Original\n");
    for (int i=0;i<qte_nums;i++) printf("%i\n",numeros[i]);
    merge_sort(numeros,0,qte_nums-1);
    printf("Merged\n");
    for (int i=0;i<qte_nums;i++) printf("%i\n",numeros[i]);
}

void merge_sort(int numeros[],int primeiro_indice,int ultimo_indice){
    /*
    2 3 -> (3-2)/2=0 -> 2..2 / 3..3
    1 1 -> 1 == 1 -> return
    0 1 -> (1-0)/2=0 -> 0..0 / 1..1 
    0 4 -> (4-0)/2=2 -> 0..2 / 3..4
    0 3 -> (3-0)/2=1 -> 0..1 / 2..3*/
    if (primeiro_indice==ultimo_indice){
        return;
    }
    int indice_meio = (ultimo_indice-primeiro_indice)/2 + primeiro_indice;
    int indice_left = primeiro_indice;
    int indice_right = indice_meio+1;
    merge_sort(numeros,indice_left,indice_meio);
    merge_sort(numeros,indice_right,ultimo_indice);

    int index_temp = 0;
    int temp[ultimo_indice-primeiro_indice+1]; 
    //Realiza merge
    do{
        if (numeros[indice_left] < numeros[indice_right]){
            temp[index_temp++] = numeros[indice_left];
            indice_left++;
        }else{
            temp[index_temp++] = numeros[indice_right];
            indice_right++;
        }
        if (indice_left > indice_meio){
            for (int i=indice_right;i<=ultimo_indice;i++) temp[index_temp++] = numeros[i];
            break;
        }
        if (indice_right > ultimo_indice){
            for (int i=indice_left;i<=indice_meio;i++) temp[index_temp++] = numeros[i];
            break;
        }

    }while(indice_left >= 0 && indice_right >= 0);
    index_temp = 0;
    for (int i=primeiro_indice;i<=ultimo_indice;i++) {
        numeros[i] = temp[index_temp++];
    }
    
 
}
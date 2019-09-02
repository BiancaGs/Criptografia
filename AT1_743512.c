/* ==========================================================================
 * Universidade Federal de São Carlos - Campus Sorocaba
 *
 * Atividade 01
 *
 * RA: 743512
 * Aluno: Bianca Gomes Rodrigues
 * ========================================================================== */

/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Letra;
    int Num; //Número de incidência da letra no texto
} ln; // Letra e número de incidência

int main(){

    char Mensagem[4096];

    // Vetor com 26 posições para armazenar todas as letras do alfabeto e suas respectivas incidências
    ln Alfabeto[26];

    /* Valores ASCII
    Letra MAIÚSCULA 65 - 90
    Letra MINÚSCULA 97 - 122
    */
    int j = 0;
    for(int i = 97; i <= 122; i++ && j++){
        // Inicializa a letra e seu respectivo número de incidência.
        Alfabeto[j].Letra = i;
        Alfabeto[j].Num = 0;
    }

     
    scanf("%[^\n]s", Mensagem);

    // printf("%s\n", Mensagem);


    for(int i = 0; i < strlen(Mensagem); i++){   

        // printf("%c - %d ", Mensagem[i], Mensagem[i]);
    
        int Numero = Mensagem[i];
        // printf("%d ", Numero);

        Alfabeto[Numero-97].Num++;
        // printf("%c - %d ", Alfabeto[Numero-97].Letra, Alfabeto[Numero-97].Num);
    }

    j = 0;
    while(j < 26){
        printf("%c - %d\n", Alfabeto[j].Letra, Alfabeto[j].Num);
        j++;
    }
    printf("\n");


    return 0;

}



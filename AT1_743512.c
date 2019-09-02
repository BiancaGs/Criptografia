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

void Imprime(ln Alfabeto[]);

void Imprime_Ordem_Incidencia(ln Alfabeto[]);

void Inicializa(ln *Alfabeto);

int main(){

    char Mensagem[4096];

    // Vetor com 26 posições para armazenar todas as letras do alfabeto e suas respectivas incidências
    ln Alfabeto[26];

    Inicializa(Alfabeto);
     
    scanf("%[^\n]s", Mensagem);

    // printf("%s\n", Mensagem);


    for(int i = 0; i < strlen(Mensagem); i++){   

        // printf("%c - %d ", Mensagem[i], Mensagem[i]);
    
        int Numero = Mensagem[i];
        // printf("%d ", Numero);

        Alfabeto[Numero-97].Num++;
        // printf("%c - %d ", Alfabeto[Numero-97].Letra, Alfabeto[Numero-97].Num);
    }

    Imprime(Alfabeto);

    Imprime_Ordem_Incidencia(Alfabeto);

    return 0;

}

void Inicializa(ln *Alfabeto){
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
}

void Imprime(ln Alfabeto[]){
    int j = 0;
    while(j < 26){
        printf("%c - %d\n", Alfabeto[j].Letra, Alfabeto[j].Num);
        j++;
    }
    printf("\n");
}

void Imprime_Ordem_Incidencia(ln Alfabeto[]){

    ln tAlfabeto[26];
    for(int i = 0; i < 26; i++){
        tAlfabeto[i].Letra = Alfabeto[i].Letra;
        tAlfabeto[i].Num = Alfabeto[i].Num; 
    }

    for(int i = 26; i >= 0; i--){
        for(int j = 1; j < i; j++){
            if(tAlfabeto[j-1].Num < tAlfabeto[j].Num){
                ln Auxiliar = tAlfabeto[j-1];
                tAlfabeto[j-1] = tAlfabeto[j];
                tAlfabeto[j] = Auxiliar;
            }
        }
    }
    Imprime(tAlfabeto);
}


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

typedef struct {
    char Letra;
    int flag; // Indica se a letra já foi descriptografada
} dMensagem; 

void Imprime(ln Alfabeto[]);

void Imprime_Ordem_Incidencia(ln Alfabeto[]);

void Inicializa(ln *Alfabeto);

void Descriptografa(char Mensagem[], ln Alfabeto[]);

int main(){

    char Mensagem[4096];

    // Vetor com 26 posições para armazenar todas as letras do alfabeto e suas respectivas incidências
    ln Alfabeto[26];

    Inicializa(Alfabeto);
     
    scanf("%[^\n]s", Mensagem);
    // printf("%s\n", Mensagem);


    for(int i = 0; i < strlen(Mensagem); i++){   
    
        int Numero = Mensagem[i];

        Alfabeto[Numero-97].Num++;
    }

    // Imprime(Alfabeto);

    // Alfabeto temporário ordenado por incidência
    Imprime_Ordem_Incidencia(Alfabeto);

    Descriptografa(Mensagem, Alfabeto);

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

    // Realiza uma cópia temporária do alfabeto
    ln tAlfabeto[26];
    for(int i = 0; i < 26; i++){
        tAlfabeto[i].Letra = Alfabeto[i].Letra;
        tAlfabeto[i].Num = Alfabeto[i].Num; 
    }

    // BubbleSort 
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

void Descriptografa(char Mensagem[], ln Alfabeto[]){


 /* ========================================================================== */

    ln tAlfabeto[26];
    for(int i = 0; i < 26; i++){
        tAlfabeto[i].Letra = Alfabeto[i].Letra;
        tAlfabeto[i].Num = Alfabeto[i].Num; 
    }

    // BubbleSort 
    for(int i = 26; i >= 0; i--){
        for(int j = 1; j < i; j++){
            if(tAlfabeto[j-1].Num < tAlfabeto[j].Num){
                ln Auxiliar = tAlfabeto[j-1];
                tAlfabeto[j-1] = tAlfabeto[j];
                tAlfabeto[j] = Auxiliar;
            }
        }
    }

 /* ========================================================================== */

    char * Incidencias = "aeosrdnitmulcvpgqbfhjxzkyw";

    int Tamanho = strlen(Mensagem);
    // printf("%d", Tamanho);

    dMensagem dMensagem[Tamanho];

    for(int i = 0; i < Tamanho; i++){
        dMensagem[i].Letra = Mensagem[i];
        // printf("%c", dMensagem[i].Letra);
        dMensagem[i].flag = 0;
    }

    int i = 0 , j = 0, k = 0, Opcao;

    char Auxiliar;

    while(j < 26 && k < 26){

        // printf("j %d\n\n", j);

        for(i = 0; i < Tamanho; i++){

            if(dMensagem[i].Letra == tAlfabeto[j].Letra && dMensagem[j].flag == 0){

                Auxiliar = dMensagem[i].Letra; 

                // printf("Letra CIFRADA %c\n", dMensagem[i].Letra);
                // printf("Letra DECIFRADA %c\n", Incidencias[k]);

                dMensagem[i].Letra = Incidencias[k];
                // printf("%c\n", Incidencias[k]);

                dMensagem[i].flag = 1; 
            }
            
        }

        // for(int l = 0; l < Tamanho; l++)
        //     printf("%c", dMensagem[l].Letra);
        // printf("\n");
        
        // scanf("%d", &Opcao);

        // switch (Opcao){
        //     case 0:
        //         break;

        //     case 1:
        //         printf("\n Case 1 \n");
        //         for(i = 0; i < Tamanho; i++){
        //             if(dMensagem[i].Letra == Incidencias[k] && dMensagem[j].flag == 1){
        //                 dMensagem[i].Letra = Auxiliar;
        //                 dMensagem[i].flag = 0;
        //             }
        //         }
        //         for(int l = 0; l < Tamanho; l++)
        //             printf("%c", dMensagem[l].Letra);
        //         printf("\n");
                
        //         break;            
        // }
        j++;
        k++;

    }

    for(int i = 0; i < Tamanho; i++)
        printf("%c", dMensagem[i].Letra);
    

}

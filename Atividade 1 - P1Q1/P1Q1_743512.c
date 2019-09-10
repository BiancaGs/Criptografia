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

void Descriptografa_Automatico(char Mensagem[], ln Alfabeto[]);

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
    // Imprime_Ordem_Incidencia(Alfabeto);

    // Descriptografa(Mensagem, Alfabeto);
    Descriptografa_Automatico(Mensagem, Alfabeto);

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

    printf("\nINCIDENCIA\n\n");

    Imprime(tAlfabeto);

 /* ========================================================================== */

    // char * Incidencias = "aeosrdnitmulcvpgqbfhjxzkyw";
    char * Incidencias = "aeosrindtmuclvpgqbfhjxzkyw";

    int Tamanho = strlen(Mensagem);
    // printf("%d", Tamanho);

    dMensagem descMensagem[Tamanho];

    for(int i = 0; i < Tamanho; i++){
        descMensagem[i].Letra = Mensagem[i];
        // printf("%c", descMensagem[i].Letra);
        descMensagem[i].flag = 0;
    }

 /* ========================================================================== */

    printf("\nFREQUENCIA RELATIVA DAS LETRAS\n");

    for(int i = 0; i < 26; i++)
        printf("%c ", Incidencias[i]);
    printf("\n\n");

    char L;

    dMensagem mensagemAuxiliar[Tamanho];

    int j = 0, Opcao;
    while(j < 26){
        printf("\nLetra CIFRADA: %c\n", tAlfabeto[j].Letra);
        
        printf("Insira uma Letra:\n");
        
        getchar();
        scanf("%c", &L);
        
         for(int i = 0; i < Tamanho; i++){
            mensagemAuxiliar[i].Letra = descMensagem[i].Letra;
            mensagemAuxiliar[i].flag = descMensagem[i].flag;
        }


        printf("Letra DECIFRADA: %c\n", L);

        for(int i = 0; i < Tamanho; i++){
            if(descMensagem[i].Letra == tAlfabeto[j].Letra && descMensagem[i].flag == 0){

                descMensagem[i].Letra = L;
                descMensagem[i].flag = 1;
            }
        }    

        printf("\nMENSAGEM\n");

        for(int i = 0; i < Tamanho; i++)
            printf("%c", descMensagem[i].Letra);

        printf("\n\n");

        printf("REVERTER?\n");
        scanf("%d", &Opcao);

        if(Opcao == 1 ){

 /* ========================================================================== */
            while(Opcao != 0){

                for(int i = 0; i < Tamanho; i++){
                    descMensagem[i].Letra = mensagemAuxiliar[i].Letra;
                    descMensagem[i].flag = 0;
                }

                // printf("\nMENSAGEM\n");

                // for(int i = 0; i < Tamanho; i++)
                //     printf("%c", descMensagem[i].Letra);

                // printf("\n\n");

                printf("Letra CIFRADA: %c\n", tAlfabeto[j].Letra);
                
                printf("Insira uma Letra:\n");
                
                getchar();
                scanf("%c", &L);
                
                printf("Letra DECIFRADA: %c\n", L);

                for(int i = 0; i < Tamanho; i++){
                    if(descMensagem[i].Letra == tAlfabeto[j].Letra && descMensagem[i].flag == 0){

                        descMensagem[i].Letra = L;
                        descMensagem[i].flag = 1;
                    }
                }    

                printf("\nMENSAGEM\n");

                for(int i = 0; i < Tamanho; i++)
                    printf("%c", descMensagem[i].Letra);

                printf("\n\n");

                printf("REVERTER?\n");
                scanf("%d", &Opcao);

                if(Opcao == 0)
                    break;
                else    
                    for(int i = 0; i < Tamanho; i++){
                        descMensagem[i].Letra = mensagemAuxiliar[i].Letra;
                        descMensagem[i].flag = 0;
                    }

            }
 /* ========================================================================== */

        }
        j++;
        
        

        // printf("\nMENSAGEM\n");

        // for(int i = 0; i < Tamanho; i++)
        //     printf("%c", descMensagem[i].Letra);

        // printf("\n\n");

        
    }

}

void Descriptografa_Automatico(char Mensagem[], ln Alfabeto[]){

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

    printf("\n");
    Imprime(tAlfabeto);


 /* ========================================================================== */

    // char * Incidencias = "aeosrdnitmulcvpgqbfhjxzkyw";
    char * Incidencias = "aeosrindtmuclpgqvbfhjzxkyw";

    int Tamanho = strlen(Mensagem);
    // printf("%d", Tamanho);

    dMensagem dMensagem[Tamanho];

    for(int i = 0; i < Tamanho; i++){
        dMensagem[i].Letra = Mensagem[i];
        // printf("%c", dMensagem[i].Letra);
        dMensagem[i].flag = 0;
    }


    int j = 0;
    int k = 0;
    while(j < 26 && k < 26){

        for(int i = 0; i < Tamanho; i++){
            // printf("%c %c", dMensagem[i].Letra, tAlfabeto[i].Letra);
            if(dMensagem[i].Letra == tAlfabeto[j].Letra && dMensagem[i].flag == 0){

                // printf("%c\n", dMensagem[i].Letra);
                // printf("%c\n", tAlfabeto[i].Letra);

                dMensagem[i].Letra = Incidencias[k];
                // printf("%c - %c", dMensagem[i].Letra, Incidencias[k]);
                dMensagem[i].flag = 1; 

            }
        }

        j++;
        k++;
    }

    printf("\n");
     for(int i = 0; i < Tamanho; i++){
        printf("%c", dMensagem[i].Letra);
    }

}

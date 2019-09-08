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

void Inicializa(unsigned char *S, char *Key);

void swap(char *sI, char *sJ);

char *geraFluxo(char * Mensagem,unsigned  char * S);

int main(){
    
    /*  Key - Chave de tamanho variável.
        Mensagem
        S - Representa o estado interno do algoritmo.
    */ 
    char Key[256], Mensagem[256];
    unsigned char S[256];

    memset(Key, '\0', 256);
    memset(Mensagem, '\0', 256);
    memset(S, '\0', 256);

    scanf("%[^\n]x", Key);

    getchar();

    scanf("%[^\n]x", Mensagem);


    printf("MENSAGEM %s\n\n", Mensagem);

    Inicializa(S, Key);

    char *Resultado = geraFluxo(Mensagem, S);

    printf("RESULTADO %x\n\n", Resultado);

    return 0;
}

void swap(char *sI, char *sJ){

    char Auxiliar;

    Auxiliar = *sI;
    *sI = *sJ;
    *sJ = Auxiliar;

}

void Inicializa( unsigned char *S, char *Key){

    char Auxiliar[256];
    memset(Auxiliar, '\0', 256);

    for(int i = 0; i < 256; i++){
        S[i] = i;
        Auxiliar[i] = Key[i % strlen(Key)];
    }

    // 0 - 255
    // for(int i = 0; i < 256; i++)
    //     printf("%d ", S[i]);

    int j = 0;

    for(int i = 0; i < 256; i++ ){
        j = (j + S[i] + Auxiliar[i]) % 256; 
        swap(&S[i], &S[j]);
    }

    // for(int i = 0; i < 256; i++)
    //     printf("%d ", S[i]);
    
}

char *geraFluxo(char * Mensagem, unsigned char * S){

    char *Resultado = malloc (256 * sizeof (char));
    memset(Resultado, '\0', 256);

    char Auxiliar;

    int i = 0, j = 0;
    
    for(int k = 0; k < strlen(Mensagem); k++){

        i = (i + 1) % 256;
        j = (j + S[i]);
        swap(&S[i], &S[j]);
        Auxiliar = (S[i]+S[j]) % 256;

        Resultado[k] = Mensagem[k] ^ Auxiliar;
        // printf(" %x\n %x", Resultado[k], Mensagem[k]);

    }

    return Resultado;
}
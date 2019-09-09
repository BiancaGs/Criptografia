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

void Inicializa(unsigned char *S, char Key[]);

void swap(unsigned char *sI, unsigned char *sJ);

unsigned char *geraFluxo(char Mensagem[],unsigned  char S[]);

// void Imprimir(unsigned char Resultado[]);

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

    printf("CHAVE\n");
    // getchar();
    scanf("%[^\n]", &Key);
    getchar();

    printf("MENSAGEM\n");
    // getchar();
    scanf("%[^\n]", &Mensagem);


    // Converte de HEXADECIMAL para STRING

    int Tamanho = strlen(Mensagem);
    char *tMensagem = (char*) malloc (256 * sizeof (char));

    for (int i = 0, j = 0; j < Tamanho; ++i, j += 2) {
        int val[1];
        sscanf(Mensagem + j, "%2x", val);
        tMensagem[i] = val[0];
        tMensagem[i + 1] = '\0';
    }


    
    printf("\nMENSAGEM\n%s\n\n", Mensagem);

    Inicializa(S, Key);

    unsigned char *Resultado = geraFluxo(Mensagem, S);
    
    printf("RESULTADO\n");
    for(int i = 0; i < strlen(Resultado); i++)
        printf("%x", Resultado[i]);

    return 0;
}

void swap(unsigned char *sI, unsigned char *sJ){

    char Auxiliar;

    Auxiliar = *sI;
    *sI = *sJ;
    *sJ = Auxiliar;

}

void Inicializa( unsigned char *S, char Key[]){

    char Auxiliar[256];
    memset(Auxiliar, '\0', 256);

    for(int i = 0; i < 256; i++){
        S[i] = i;
        // Auxiliar[i] = Key[i % strlen(Key)];
    }

    // 0 - 255
    // for(int i = 0; i < 256; i++)
    //     printf("%d ", S[i]);

    int j = 0;

    for(int i = 0; i < 256; i++ ){

        j = (j + S[i] + Key[i % strlen(Key)]) % 256; 
        swap(&S[i], &S[j]);
    }

    // for(int i = 0; i < 256; i++)
    //     printf("%d ", S[i]);
    
}

// void Imprimir(unsigned char Resultado[]){

//     printf("RESULTADO\n");
//     for(int i = 0; i < strlen(Resultado); i++)
//         printf("%X", Resultado[i]);
// }

unsigned char *geraFluxo(char Mensagem[], unsigned char S[]){

    unsigned char *Resultado = (char*) malloc (256 * sizeof (char));
    memset(Resultado, '\0', 256);

    int Auxiliar;

    int i = 0, j = 0;
    
    for(int k = 0; k < strlen(Mensagem); k++){

        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        swap(&S[i], &S[j]);
        Auxiliar = (S[i]+S[j]) % 256;

        Resultado[k] = Mensagem[k] ^ S[Auxiliar];
        // printf(" %x\n %x", Resultado[k], Mensagem[k]);

    }

    return Resultado;

    // Imprimir(Resultado);
}
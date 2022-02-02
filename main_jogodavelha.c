
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogodavelha.h"

#define Linha 3
#define Coluna 3

int main()
{
    char aux;
    int linha, coluna, resultado;
    int contadorUsuario = 0;
    int contadorComputador = 0;
    int contadorEmpate = 0;
    char matriz[Linha][Coluna];          
    printf("\nBEM VINDO AO JOGO DA VELHA!\n");
    printf ("\nVAMOS DAR ÍNICIO AO JOGO!\n");


    for(int i = 0; i < 3; i++){ 
        int aux = jogar(matriz);
        if (aux == 1){
            contadorUsuario++;
        }
        else if (aux == 0){
            contadorComputador++;
        }
        else {
            contadorEmpate++;
        }
    }
    printf("\nO PLACAR É:\n");
    printf("USUARIO: %d  COMPUTADOR: %d  EMPATE: %d\n", contadorUsuario, contadorComputador, contadorEmpate);

    char continuar;
    printf("DIGITE (c) PARA CONTINUAR OU p");
    scanf("\n%c", &continuar);
    while (continuar == 'c'){
        for(int i = 0; i < 2; i++){ 
            int aux = jogar(matriz);
        if (aux == 1){
            contadorUsuario++;
        }
        else if (aux == 0){
            contadorComputador++;
        }
        else {
            contadorEmpate++;
        }
        }
        printf("DIGITE (c) PARA CONTINUAR OU p");
        scanf("\n%c", &continuar);
    }

    printf("\nO PLACAR TOTAL É:\n");
    printf("USUARIO: %d  COMPUTADOR: %d  EMPATE: %d\n", contadorUsuario, contadorComputador, contadorEmpate);


    return 0;
}
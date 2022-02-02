#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogodavelha.h"

#define Linha 3
#define Coluna 3

void zerar_jogo(char matriz_jogo[Linha][Coluna]){
    for(int i = 0; i < Linha; i++){
        for(int j = 0; j < Coluna; j++){
            matriz_jogo[i][j] = 'N';
        }
    }
}

void imprime_jogo(char matriz[Linha][Coluna]){
    printf("\nJOGO DA VELHA!\n");
    for (int i = 0; i < Linha; i++){
        for (int j = 0; j < Coluna; j++){
            printf(" %c ", matriz[i][j]);
        }
        printf("\n");
    }
}
int e_valido(char matriz[Linha][Coluna]){
    for(int i = 0; i < Linha; i++){
        for(int j = 0; j < Coluna; j++){
            if (matriz[i][j] == 'N'){
                return 1;
            } 
        }
    }
    return 0;
}
int jogar(char matriz[Linha][Coluna]){
    zerar_jogo(matriz);
    imprime_jogo(matriz);
    int linha, coluna;
    int resultado = 1;
    while (resultado == 1){
        printf("\nDIGITE A LINHA EM SEGUIDA DA COLUNA DE SUA JOGADA:\n");
        scanf("%d %d", &linha, &coluna);
        jogada_usuario(matriz, linha, coluna);
        imprime_jogo(matriz);
        printf("\nJOGADA COMPUTADOR!\n");
        jogada_computador(matriz);
        imprime_jogo(matriz);
        printf("\nresultado: %d\n", resultado);
        if(verifica_linha(matriz) == 1){
            printf("\nUSUARIO VENCEU linha!\n");
            return 1;
        }
        else if(verifica_linha(matriz) == 2){
            printf("\nCOMPUTADOR VENCEU linha!\n");
            return 0;
        }
        else if(verifica_coluna(matriz) == 1){
            printf("\nUSUARIO VENCEU coluna!\n");
            return 1;
        }
        else if(verifica_coluna(matriz) == 2){
            printf("\nCOMPUTADOR VENCEU coluna!\n");
            return 0;
        }
        else if(verifica_diagonalprin(matriz) == 1){
            printf("\nUSUARIO VENCEU diag prin!\n");
            return 1;
        }
        else if(verifica_diagonalprin(matriz) == 2){
            printf("\nCOMPUTADOR VENCEU diag princ!\n");
            return 0;
        }
        else if(verifica_diagonalsec(matriz) == 1){
            printf("\nUSUARIO VENCEU diag sec!\n");
            return 1;
        }
        else if(verifica_diagonalsec(matriz) == 2){
            printf("\nCOMPUTADOR VENCEU diasec!\n");
            return 0;
        }
        resultado = e_valido(matriz);
    }
    return -1;
}

void jogada_usuario(char matriz_jogo[Linha][Coluna], int l, int c){
    int movimento = 0;
    if (l >= 0 && c <= 2){
        for(int i = 0; i < Linha; i++){
            for(int j = 0; j < Coluna; j++){
                if (matriz_jogo[i][j] == 'N'){
                    matriz_jogo[l][c] = 'x';
                    movimento++;
                    break;
                }
            }
            if(movimento == 1){
                break;
            }
        }
    }
    else{
        printf("\nDigite linha e coluna válidos!\n");
    }
}
void jogada_computador(char matriz_jogo[Linha][Coluna]){
    int movimento = 0;
    for(int i = 0; i < Linha; i++){
        for(int j = 0; j < Coluna; j++){
            if(matriz_jogo[i][j] == 'N'){
                matriz_jogo[i][j] = 'o'; 
                movimento++;
                break;
            }
        }
        if(movimento == 1){
            break;
        }
    }
}

int verifica_linha(char matriz[Linha][Coluna]){
    if ((matriz[0][0] == 'x'&& matriz[0][1] == 'x' && matriz[0][2] == 'x') || 
        (matriz[1][0] == 'x'&& matriz[1][1] == 'x' && matriz[1][2] == 'x') ||
        (matriz[2][0] == 'x'&& matriz[2][1] == 'x' && matriz[2][2] == 'x')){
            return 1;
    }
    else if ((matriz[0][0] == 'o'&& matriz[0][1] == 'o' && matriz[0][2] == 'o') || 
        (matriz[1][0] == 'o'&& matriz[1][1] == 'o' && matriz[1][2] == 'o') ||
        (matriz[2][0] == 'o'&& matriz[2][1] == 'o' && matriz[2][2] == 'o')){
            return 2;
    }
    else {
        return 0;
    }
   
}

int verifica_coluna(char matriz[Linha][Coluna]){
    if ((matriz[0][0] == 'x'&& matriz[1][0] == 'x' && matriz[2][0] == 'x') || 
        (matriz[0][1] == 'x'&& matriz[1][1] == 'x' && matriz[2][1] == 'x') ||
        (matriz[0][2] == 'x'&& matriz[1][0] == 'x' && matriz[2][2] == 'x')){
            return 1;
    }
    else if ((matriz[0][0] == 'o'&& matriz[1][0] == 'o' && matriz[2][0] == 'o') || 
        (matriz[0][1] == 'o'&& matriz[1][1] == 'o' && matriz[2][1] == 'o') ||
        (matriz[0][2] == 'o'&& matriz[1][0] == 'o' && matriz[2][2] == 'o')){
            return 2;
    }
    else {
        return 0;
    }
}
int verifica_diagonalprin(char matriz[Linha][Coluna]){
    if ((matriz[0][0]=='x' && matriz[1][1] == 'x' && matriz[2][2] == 'x')){
        return 1;
    }
    else if((matriz[0][0]=='o' && matriz[1][1] == 'o' && matriz[2][2] == 'o')){
        return 2;
    }
    else {
        return 0;
    }
}
int verifica_diagonalsec(char matriz[Linha][Coluna]){
    if ((matriz[0][2]=='x' && matriz[1][1] == 'x' && matriz[2][0] == 'x')){
        return 1;
    }
    else if((matriz[0][2]=='o' && matriz[1][1] == 'o' && matriz[2][0] == 'o')){
        return 2;
    }
    else {
        return 0;
    }
    
}
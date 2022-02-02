#define Linha 3
#define Coluna 3

void zerar_jogo(char matriz_jogo[Linha][Coluna]);
void imprime_jogo(char matriz[Linha][Coluna]);
int e_valido(char matriz[Linha][Coluna]);
int jogar(char matriz[Linha][Coluna]);
void jogada_usuario(char matriz_jogo[Linha][Coluna], int l, int c);
void jogada_computador(char matriz_jogo[Linha][Coluna]);
int verifica_linha(char matriz[Linha][Coluna]);
int verifica_coluna(char matriz[Linha][Coluna]);
int verifica_diagonalprin(char matriz[Linha][Coluna]);
int verifica_diagonalsec(char matriz[Linha][Coluna]);
void vencedor_jogo(char matriz[Linha][Coluna]);
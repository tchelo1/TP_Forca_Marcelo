#ifndef FORCA_H
#define FORCA_H

#include <stdio.h>
#include <stdlib.h>

#define TAM_PALAVRA 50    // Tamanho maximo da palavra
#define MAX_PALAVRAS 30   // Maximo de palavras que podem ser carregadas
#define TAM_NOME 50       // Tamanho maximo do nome do jogador

// Carrega uma palavra aleatoria do arquivo palavras.txt
void carregarPalavras(char palavraSorteada[TAM_PALAVRA]);

// Mostra o historico salvo em resultados.txt
void mostrarHistorico(void);

// Desenha o boneco da forca baseado no numero de erros
void desenharForca(int erros);

// Roda a interface principal do jogo (uma partida)
void interfaceJogo(void);

// Registra o resultado da partida no arquivo resultados.txt
void registrarResultado(const char nome[TAM_NOME], const char palavra[TAM_PALAVRA], int venceu);

// Menu principal para o jogo
void menuJogo(void);

#endif /* FORCA_H */

#include "forca.h"
#include <string.h>
#include <time.h>

void carregarPalavras(char palavraSorteada[TAM_PALAVRA]) {
    FILE *file = fopen("palavras.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir arquivo palavras.txt. Usando palavra padrao.\n");
        strcpy(palavraSorteada, "computador");
        return;
    }

    char palavras[MAX_PALAVRAS][TAM_PALAVRA];
    int count = 0;

    while (fgets(palavras[count], TAM_PALAVRA, file) != NULL && count < MAX_PALAVRAS) {
        size_t len = strlen(palavras[count]);
        if (len > 0 && palavras[count][len - 1] == '\n') {
            palavras[count][len - 1] = '\0';  // Remove \n do final
        }
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("Arquivo palavras.txt vazio. Usando palavra padrao.\n");
        strcpy(palavraSorteada, "computador");
        return;
    }

    srand((unsigned)time(NULL));
    int indice = rand() % count;

    strcpy(palavraSorteada, palavras[indice]);
}

void mostrarHistorico(void) {
    FILE *file;
    char linha[TAM_PALAVRA + 100]; // buffer maior para linhas do arquivo

    file = fopen("resultados.txt", "r");
    if (file == NULL) {
        printf("Nenhum historico encontrado.\n");
        return;
    }

    printf("\n|| Historico da Partida ||\n");
    while (fgets(linha, sizeof(linha), file) != NULL) {
        printf("%s", linha);
    }
    fclose(file);
}

void desenharForca(int erros) {
    printf("\n");
    printf(" _______\n");
    printf(" |     |\n");
    if (erros >= 1) printf(" O     |\n");
    else printf("       |\n");

    if (erros == 2) printf(" |     |\n");
    else if (erros == 3) printf("/|     |\n");
    else if (erros >= 4) printf("/|\\    |\n");
    else printf("       |\n");

    if (erros == 5) printf("/      |\n");
    else if (erros >= 6) printf("/ \\    |\n");
    else printf("       |\n");

    printf("       |\n");
    printf("_______|___\n");
}

void registrarResultado(const char nome[TAM_NOME], const char palavra[TAM_PALAVRA], int venceu) {
    FILE *file = fopen("resultados.txt", "a");
    if (file == NULL) {
        printf("Erro ao salvar resultado.\n");
        return;
    }

    if (venceu)
        fprintf(file, "Jogador: %s | Palavra: %s | Resultado: Venceu\n", nome, palavra);
    else
        fprintf(file, "Jogador: %s | Palavra: %s | Resultado: Perdeu\n", nome, palavra);

    fclose(file);
}

void interfaceJogo(void) {
    char nome[TAM_NOME];
    char palavraSorteada[TAM_PALAVRA];
    char palavraEscondida[TAM_PALAVRA];
    char letra;
    int erros = 0, acertos = 0;

    carregarPalavras(palavraSorteada);
    int tam = (int)strlen(palavraSorteada);

    printf("\nDigite seu nome: ");
    scanf(" %49s", nome);  // Limita o tamanho para evitar overflow

    for (int i = 0; i < tam; i++) {
        palavraEscondida[i] = '_';
    }
    palavraEscondida[tam] = '\0';

    while (erros < 6 && acertos < tam) {
        printf("\nPalavra: ");
        for (int i = 0; i < tam; i++) {
            printf("%c ", palavraEscondida[i]);
        }

        printf("\nDigite uma letra: ");
        scanf(" %c", &letra);

        int acertou = 0;
        for (int i = 0; i < tam; i++) {
            if (letra == palavraSorteada[i] && palavraEscondida[i] == '_') {
                palavraEscondida[i] = letra;
                acertos++;
                acertou = 1;
            }
        }

        if (!acertou) {
            erros++;
            printf("Letra incorreta! Erros: %d/6\n", erros);
        }

        desenharForca(erros);
    }

    if (acertos == tam) {
        printf("\nParabens, %s! Voce venceu!\n", nome);
        registrarResultado(nome, palavraSorteada, 1);
    } else {
        printf("\nVoce perdeu, %s! A palavra era: %s\n", nome, palavraSorteada);
        registrarResultado(nome, palavraSorteada, 0);
    }
}

void menuJogo(void) {
    char opcao = '0';

    while (opcao != '3') {
        printf("\n===== Jogo da Forca =====\n");
        printf("1. Jogar\n");
        printf("2. Ver Historico\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &opcao);

        if (opcao == '1') {
            interfaceJogo();
        } else if (opcao == '2') {
            mostrarHistorico();
        } else if (opcao != '3') {
            printf("Opcao invalida! Tente novamente.\n");
        }
    }

    printf("Obrigado por jogar!\n");
}

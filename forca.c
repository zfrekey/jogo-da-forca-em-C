#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

char palavrasecreta[20];
char chutes[26];
int chutesdados = 0;

void abertura() {
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta() {
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[chutesdados] = chute;
    chutesdados++;
}

int jachutou(char letra) {
    int achou = 0;
    for(int j = 0; j < chutesdados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhaforca() {

    printf("Você já deu %d chutes\n", chutesdados);

    for(int i = 0; i < strlen(palavrasecreta); i++) {

        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");

}

int ganhou() {
    for(int i = 0; i<strlen(palavrasecreta); i++){
        if(!jachutou(palavrasecreta[i])){
            return 0;
        }
    }
    return 1;
}

int enforcou() {

    int erros = 0;
    for(int i =0; i < chutesdados; i++){
        int existe = 0;
        for(int j =0; j < strlen(palavrasecreta); j++){
            if (chutes[i] == palavrasecreta[j]);
            existe = 1;
            break;
        }
        if (!existe) erros++;
    }
    return erros >= 5;
}

void escolhepalavra() {
    FILE* f = NULL;
    
    f = fopen("palavras.txt", "r");

    int qntddepalavras;
    fscanf(f, "%d", &qntddepalavras);

    srand(time(0));
    int randomico = rand() % qntddepalavras;

    for(int i = 0; i<= randomico; i++) {
        fscanf(f, "s", palavrasecreta);
    }
    fclose(f);
}

int main() {

    abertura();
    escolhepalavra();

    do {

        desenhaforca();
        chuta();

    } while (!acertou() && !enforcou());

}
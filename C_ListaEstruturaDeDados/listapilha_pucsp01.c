#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Max 10
#define sinal -1
#define fantasma -1

typedef struct {
    int topo;
    unsigned char Vetor[Max];
} Pilha;

Pilha criarPilha(); // Prot�tipo da fun��o criarPilha
bool PilhaVazia(Pilha); // Prot�tipo da fun��o PilhaVazia
unsigned char acessarPilha(Pilha); // Prot�tipo da fun��o acessarPilha
Pilha pushPilha(Pilha, unsigned char); // Prot�tipo da fun��o pushPilha
Pilha popPilha(Pilha); // Prot�tipo da fun��o popPilha
void esvaziarPilha(Pilha*); // Prot�tipo da fun��o esvaziarPilha

int main() {
    Pilha p = criarPilha(); // Cria uma nova pilha usando a fun��o criarPilha

    printf("A pilha foi criada.\n");

    p = pushPilha(p, 'a'); // Insere o elemento 'a' na pilha usando a fun��o pushPilha
    printf("Elemento %c inserido na pilha.\n", acessarPilha(p));

    p = pushPilha(p, 'b'); // Insere o elemento 'b' na pilha usando a fun��o pushPilha
    printf("Elemento %c inserido na pilha.\n", acessarPilha(p));

    p = pushPilha(p, 'c'); // Insere o elemento 'c' na pilha usando a fun��o pushPilha
    printf("Elemento %c inserido na pilha.\n", acessarPilha(p));

    printf("Elemento %c removido da pilha.\n", acessarPilha(p));
    p = popPilha(p); // Remove o elemento do topo da pilha usando a fun��o popPilha
    printf("Elemento %c esta no topo da lista.\n", acessarPilha(p));

    if (PilhaVazia(p)) {
        printf("A pilha esta vazia.\n");
    } else {
        printf("A pilha nao esta vazia.\n");
    }

    esvaziarPilha(&p); // Esvazia a pilha usando a fun��o esvaziarPilha
    printf("A pilha foi esvaziada.\n");

    if (PilhaVazia(p)) {
        printf("A pilha esta vazia.\n");
    } else {
        printf("A pilha nao esta vazia.\n");
    }

    return 0;
}

Pilha criarPilha() {
    Pilha S;
    S.topo = sinal; // Inicializa o topo da pilha com o valor sinal (-1)
    S.Vetor[0] = Max - 1; // Define o tamanho m�ximo da pilha no �ndice 0 do vetor Vetor
    return S;
}

bool PilhaVazia(Pilha p) {
    if (p.topo == -1) { // Se o topo for igual a sinal (-1), a pilha est� vazia
        return true;
    } else {
        return false;
    }
}

unsigned char acessarPilha(Pilha S) {
    unsigned char y;
    int p;
    if (S.topo != sinal) { // Se o topo n�o for igual a s


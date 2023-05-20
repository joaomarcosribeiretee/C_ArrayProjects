#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ghost 0

typedef struct Celula{
    int elemento;
    struct Celula* next;
} Celula;

typedef Celula* Lista;

// Função para criar uma lista vazia
Lista criarLista();

// Função para inserir um elemento no início da lista
Lista inserir(Lista L, int y);

// Função para inserir um elemento no fim da lista
Lista inserirFim(Lista L, int y);

// Função para mostrar os elementos da lista
void mostrarLista(Lista p);

// Função para retirar o elemento do início da lista
Lista retirar(Lista L);

// Função para retirar o elemento do fim da lista
Lista retirarFim(Lista L);

// Função para retirar um elemento específico da lista
Lista retirarItem(Lista lista, int elemento);

// Função para remover o elemento de um determinado índice na lista
Lista removerIndice(Lista, int k);

int main(){
    Lista L;
    L = criarLista();

    // Inserção de elementos na lista
    L = inserir(L, 1);
    L = inserir(L, 2);
    L = inserir(L, 3);
    L = inserir(L, 4);
    L = inserirFim(L, 5);
    L = inserirFim(L, 6);

    // Retirar elementos da lista
    L = retirar(L);
    L = retirarFim(L);
    L = retirarItem(L, 2);
    L = removerIndice(L, 3);

    // Mostrar os elementos da lista
    mostrarLista(L);

    return 0;
}

// Função para criar uma lista vazia
Lista criarLista(){
    Lista L  = NULL;
    return L;
}

// Função para inserir um elemento no início da lista
Lista inserir(Lista L, int y){
    Lista novo;
    novo = malloc(sizeof(Celula));
    novo->elemento = y;

    if(L == NULL){
        novo->next = novo;
        L = novo;
    } else{
        novo->next = L;
        Lista ultimo = L;
        
        while(ultimo->next != L)
            ultimo = ultimo->next;
        
        ultimo->next = novo;
        L = novo;
    }
    
    return L;
}

// Função para mostrar os elementos da lista
void mostrarLista(Lista p){
    Lista apont;
    int k;
    if(p == NULL)
        printf("lista vazia \n");
    else{
        printf("\n lista = ");
        apont = p;
        do {
            k = apont->elemento;
            printf(" %d ", k);
            apont =  apont->next;
        } while(apont!= p);
    }
    printf("\n");
}

// Função para inserir um elemento no fim da lista
Lista inserirFim(Lista L, int y){
    Lista novo;
    
    novo = malloc(sizeof(Celula));
    novo->elemento = y;
    
    if(L == NULL){
        novo->next = novo;
        L = novo;
    } else{
        Lista ultimo = L;
        while(ultimo->next != L)
            ultimo = ultimo->next;
            
        ultimo->next = novo;
			novo->next = L;
	}
	return L;
}

Lista retirar(Lista L){
	
	Lista ap = L;
	
	if(L != NULL){
	if(ap == ap->next)
	L = NULL;
	else
	{
		Lista ultimo = L;
		while(ultimo->next != L)
			ultimo = ultimo->next;
		ultimo->next = ap->next;
		L = ap->next;
		free(ap);
	}
	}

	return L;
	
}

Lista retirarFim(Lista L){
	Lista ap = L;
	
	if(L != NULL){
	if(ap == ap->next)
	L = NULL;
	else{
		Lista penultimo;
		while(ap->next != L){
			penultimo = ap;
			ap = ap->next;
		}
		penultimo->next = L;
		free(ap);
	}
	}	
	
	return L;
	
}


// Função para remover um elemento específico da lista
Lista retirarItem(Lista lista, int elemento) {
    if (lista == NULL) { // Caso a lista esteja vazia
        return NULL; // Retorna NULL
    } else if (lista->elemento == elemento) { // Caso o primeiro elemento seja o elemento a ser removido
        Lista aux = lista; // Armazena o primeiro nó em uma variável auxiliar
        Lista ultimo = lista;
        while (ultimo->next != lista) {
            ultimo = ultimo->next; // Percorre até o último nó da lista
        }
        lista = lista->next; // O segundo nó se torna o novo primeiro nó
        ultimo->next = lista; // O último nó aponta para o novo primeiro nó
        free(aux); // Libera a memória do primeiro nó
        return lista; // Retorna a lista atualizada
    } else {
        Lista atual = lista->next; // Começa a partir do segundo nó
        Lista anterior = lista; // Armazena o primeiro nó em uma variável auxiliar
        while (atual != lista && atual->elemento != elemento) { // Percorre até encontrar o elemento ou voltar ao início da lista
            anterior = atual;
            atual = atual->next;
        }
        if (atual == lista) { // Caso tenha voltado ao início da lista sem encontrar o elemento
            printf("Nao foi encontrado o item");
			return lista; // Retorna a lista original
        } else {
            anterior->next = atual->next; // Remove o nó que contém o elemento
            free(atual); // Libera a memória do nó removido
            return lista; // Retorna a lista atualizada
        }
    }
}

// Função para retirar o elemento do fim da lista
Lista removerIndice(Lista L, int k){
	Lista ap, ultimo, anterior;
	int i, tam = 1, aux = 0; i = 1;
	if(L != NULL){
		ap = L;
		do{
		if(i == k)
			aux = 1;
		tam++;
		i++;
		ap = ap->next;
		} while(ap != L);
		
		if(aux == 1){
			ap = L;
			if(k == 1){
				if(ap->next == ap)
					L = NULL;
				else{
					ultimo = L;
					while(ultimo -> next != L)
						ultimo = ultimo->next;
					ultimo->next = ap->next;
					L = ap->next;
					free(ap);
				}
			}
			else if(k == tam){
				ultimo = L;
				while(ultimo->next != L){
					anterior = ultimo;
					ultimo = ultimo->next;}
					anterior->next = L;
					free(ultimo);
			}
			else{
				i = 2; ap = L->next; anterior = L;
				while(i != k){
					anterior = ap;
					ap = ap->next;
					i++;
			}
					anterior->next = ap->next;
					free(ap);
			}
		}
		
	}
	
	return L;
}




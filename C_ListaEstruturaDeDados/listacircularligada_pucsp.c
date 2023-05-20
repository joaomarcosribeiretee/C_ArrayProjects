#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ghost 0

typedef struct Celula{
    int elemento;
    struct Celula* next;
} Celula;

typedef Celula* Lista;

// Fun��o para criar uma lista vazia
Lista criarLista();

// Fun��o para inserir um elemento no in�cio da lista
Lista inserir(Lista L, int y);

// Fun��o para inserir um elemento no fim da lista
Lista inserirFim(Lista L, int y);

// Fun��o para mostrar os elementos da lista
void mostrarLista(Lista p);

// Fun��o para retirar o elemento do in�cio da lista
Lista retirar(Lista L);

// Fun��o para retirar o elemento do fim da lista
Lista retirarFim(Lista L);

// Fun��o para retirar um elemento espec�fico da lista
Lista retirarItem(Lista lista, int elemento);

// Fun��o para remover o elemento de um determinado �ndice na lista
Lista removerIndice(Lista, int k);

int main(){
    Lista L;
    L = criarLista();

    // Inser��o de elementos na lista
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

// Fun��o para criar uma lista vazia
Lista criarLista(){
    Lista L  = NULL;
    return L;
}

// Fun��o para inserir um elemento no in�cio da lista
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

// Fun��o para mostrar os elementos da lista
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

// Fun��o para inserir um elemento no fim da lista
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


// Fun��o para remover um elemento espec�fico da lista
Lista retirarItem(Lista lista, int elemento) {
    if (lista == NULL) { // Caso a lista esteja vazia
        return NULL; // Retorna NULL
    } else if (lista->elemento == elemento) { // Caso o primeiro elemento seja o elemento a ser removido
        Lista aux = lista; // Armazena o primeiro n� em uma vari�vel auxiliar
        Lista ultimo = lista;
        while (ultimo->next != lista) {
            ultimo = ultimo->next; // Percorre at� o �ltimo n� da lista
        }
        lista = lista->next; // O segundo n� se torna o novo primeiro n�
        ultimo->next = lista; // O �ltimo n� aponta para o novo primeiro n�
        free(aux); // Libera a mem�ria do primeiro n�
        return lista; // Retorna a lista atualizada
    } else {
        Lista atual = lista->next; // Come�a a partir do segundo n�
        Lista anterior = lista; // Armazena o primeiro n� em uma vari�vel auxiliar
        while (atual != lista && atual->elemento != elemento) { // Percorre at� encontrar o elemento ou voltar ao in�cio da lista
            anterior = atual;
            atual = atual->next;
        }
        if (atual == lista) { // Caso tenha voltado ao in�cio da lista sem encontrar o elemento
            printf("Nao foi encontrado o item");
			return lista; // Retorna a lista original
        } else {
            anterior->next = atual->next; // Remove o n� que cont�m o elemento
            free(atual); // Libera a mem�ria do n� removido
            return lista; // Retorna a lista atualizada
        }
    }
}

// Fun��o para retirar o elemento do fim da lista
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




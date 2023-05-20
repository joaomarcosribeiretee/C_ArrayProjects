	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>
	
	#define ghost 0
	
	typedef struct Celula {
		char prim;
		struct Celula *suc;
		struct Celula *pre;
	} Celula;
	
	typedef struct {
		int tamanho;
		Celula *inicio;
		Celula *fim;
	} Lista;
	
	//interface
	
	// Interface
	Lista criarLista();  // O construtor cria a lista vazia
	bool listaVazia(Lista);  // Devolve TRUE se a lista estiver vazia
	void mostrarLista(Lista);  // Mostra o conteúdo da lista a partir do início
	void mostrarListaDE(Lista);  // Mostra o conteúdo da lista a partir do fim
	void inserirInicio(Lista *, int);  // Acrescenta o item no início da lista
	void inserirFim(Lista *, int);  // Acrescenta o item no final da lista
	void removerPos(Lista *, int);  // Remove o item na posição especificada
	int localizarMaior(Lista);  // Retorna a posição do maior valor na lista
	int obterMaximo(Lista);  // Retorna o maior valor da lista
	int obterSoma(Lista);  // Retorna a soma dos elementos da lista
	void inverterLista(Lista *);  // Inverte a ordem dos elementos da lista
	
	int main() {
		Lista a;
		bool p;

		a = criarLista();
		inserirInicio(&a, 14);
		inserirInicio(&a, 7);
		inserirFim(&a, 10);
		inserirFim(&a, 23);
		removerPos(&a, 2);
		mostrarLista(a);
		mostrarListaDE(a);
		p = listaVazia(a);
		mostrarLista(a);
		
		int maximo = obterMaximo(a);
    	if (maximo == ghost) {
        	printf("\nA lista esta vazia\n");
    	} else {
    		printf("\nO maior valor da lista eh %d\n", maximo);
    	}

    	int posicao_maior = localizarMaior(a);
    	if (posicao_maior == 0) {
        	printf("\nA lista esta vazia\n");
    	} else {
        	printf("\nO maior valor da lista esta na posicao %d\n", posicao_maior);
    	}
    	
    	int soma = obterSoma(a);
    	printf("\nSoma dos elementos da lista: %d", soma);

		return 0;
		
		
	}
	
	Lista criarLista(){
		Lista ap;
		ap.inicio = NULL;
		ap.fim = NULL;
		ap.tamanho = 0;
		//printf("A Lista foi criada");
		return ap;
	}
	
	bool listaVazia(Lista ap){
		
		bool y;
		
		if (ap.tamanho == 0) {
			y = false;
			printf("\nLista Vazia");
		}	
		else {
			y = true;
		    printf("\nLista nao e Vazia");
		}
		
		return y;
	}
	
	void mostrarLista(Lista ap) {
		
    	Celula *p = ap.inicio;
    	printf("\nConteudo da lista: ");
    	while (p != NULL) {
    		printf(" %d", p->prim);
       		p = p->suc;
   	 }
   	 printf("\n");
	}

	void mostrarListaDE(Lista ap) {
    	Celula *p = ap.fim;
    	printf("\nConteudo da lista (do fim para o inicio): ");
    	while (p != NULL) {
        	printf(" %d", p->prim);
        	p = p->pre;
    	}
    	printf("\n");
	}

	void inserirInicio(Lista *ap, int novo) {
    	Celula *nova = (Celula*) malloc(sizeof(Celula));
   		nova->prim = novo;
    	nova->suc = ap->inicio;
    	nova->pre = NULL;
    	if (ap->inicio != NULL) {
        	ap->inicio->pre = nova;
    	} else {
        	ap->fim = nova;
    	}
    	ap->inicio = nova;
    	ap->tamanho++;
	}
	
	void inserirFim(Lista *ap, int novo) {
    	Celula *nova = (Celula*) malloc(sizeof(Celula));
    	nova->prim = novo;
    	nova->suc = NULL;
    	nova->pre = ap->fim;
   		if (ap->fim != NULL) {
        	ap->fim->suc = nova;
    	} else {
        	ap->inicio = nova;
    	}
    	ap->fim = nova;
    	ap->tamanho++;
	}
		
	void removerPos(Lista *ap, int pos) {
    if (ap->tamanho == 0) {
        printf("Lista vazia\n");
        return;
    }

    if (pos < 0 || pos >= ap->tamanho) {
        printf("Posicao invalida\n");
        return;
    }

    Celula *atual = ap->inicio;
    Celula *anterior = NULL;
    int i;
    for (i = 0; i < pos; i++) {
        anterior = atual;
        atual = atual->suc;
    }

    if (anterior != NULL) {
        anterior->suc = atual->suc;
    } else {
        ap->inicio = atual->suc;
    }

    if (atual->suc != NULL) {
        atual->suc->pre = anterior;
    } else {
        ap->fim = anterior;
    }

    free(atual);
    ap->tamanho--;
}

	int obterMaximo(Lista ap) {
    if (ap.tamanho == 0) {
        return ghost;
    }

    Celula *p = ap.inicio;
    int max = p->prim;
    while (p != NULL) {
        if (p->prim > max) {
            max = p->prim;
        }
        p = p->suc;
    }
    return max;
	}
	
	int localizarMaior(Lista ap) {
    Celula *p = ap.inicio;
    int maior = ghost;
    int ordem = 0;
    int i = 1;
    while (p != NULL) {
        if (p->prim > maior) {
            maior = p->prim;
            ordem = i;
        }
        p = p->suc;
        i++;
    }
    return ordem;
	}

	int obterSoma(Lista ap) {
    	int soma = 0;
    	Celula *p = ap.inicio;
    	while (p != NULL) {
        	soma += p->prim;
        	p = p->suc;
    	}
    	return soma;
	}

	void inverterLista(Lista *ap) {
    Celula *atual = ap->inicio;
    ap->fim = atual;
    while (atual != NULL) {
        Celula *temp = atual->suc;
        atual->suc = atual->pre;
        atual->pre = temp;
        if (temp == NULL) {
            ap->inicio = atual;
        }
        atual = temp;
    }
	}



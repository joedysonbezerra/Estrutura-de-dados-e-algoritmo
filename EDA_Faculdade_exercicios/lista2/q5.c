#include <stdio.h>
#include <stdlib.h>

struct No {
	int valor;
	struct No *prox;
};

void init();
void snapshot();
void inserirLigacao();
void buscaEmLargura();
void inserir();
int remover();
int removerFim();
int verificar();



int main(int argc, char const *argv[]){

	struct No *fila = NULL;
	struct No *pilha = NULL;
	
	int grafo[13][13];
	init(grafo);
	inserirLigacao(0,1,grafo);
	inserirLigacao(0,2,grafo);
	inserirLigacao(0,3,grafo);

	inserirLigacao(1,0,grafo);
	inserirLigacao(1,2,grafo);

   inserirLigacao(2,0,grafo);
	inserirLigacao(2,1,grafo);
	inserirLigacao(2,4,grafo);
	inserirLigacao(2,5,grafo);

	inserirLigacao(3,0,grafo);
	inserirLigacao(3,7,grafo);

   inserirLigacao(4,2,grafo);
	inserirLigacao(4,5,grafo);

   inserirLigacao(5,2,grafo);
	inserirLigacao(5,4,grafo);
   inserirLigacao(5,6,grafo);

   inserirLigacao(6,5,grafo);
	inserirLigacao(6,7,grafo);
   inserirLigacao(6,8,grafo);

   inserirLigacao(7,3,grafo);
   inserirLigacao(7,6,grafo);
	inserirLigacao(7,8,grafo);

   inserirLigacao(8,6,grafo);
   inserirLigacao(8,7,grafo);
	inserirLigacao(8,9,grafo);
   inserirLigacao(8,12,grafo);

   inserirLigacao(9,8,grafo);
   inserirLigacao(9,10,grafo);
   inserirLigacao(9,12,grafo);

   inserirLigacao(10,9,grafo);
   inserirLigacao(10,11,grafo);

   inserirLigacao(11,10,grafo);
   inserirLigacao(11,12,grafo);

   inserirLigacao(12,8,grafo);
   inserirLigacao(12,9,grafo);
   inserirLigacao(12,11,grafo);
	snapshot(grafo);
	buscaEmLargura(grafo,&fila);
	return 0;
}

void init(int grafo[10][10]){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			grafo[i][j] = 0;	
		}
	}
}

void snapshot(int grafo[10][10]){
	for (int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			printf("%d", grafo[i][j]);
		}
		printf("\n");
	}
}

void inserirLigacao(int vertice1, int vertice2, int grafo[10][10]){
	grafo[vertice1][vertice2] = 1;
}

void buscaEmLargura(int grafo[10][10], struct No **fila){
	inserir(0,fila);
	
	while(*fila != NULL){
		for(int i = 0; i < 10; i++){
			if(grafo[(*fila)->valor][i] == 1){
				if(verificar(i,fila) == 0){
					inserir(i,fila);
				}
			}
		}
		printf("%d", remover(fila));	
	}
}

void inserir(int numero, struct No **fila){

	if((*fila) == NULL){
		struct No *tmp = malloc(sizeof(struct No));
		tmp->valor = numero;
		tmp->prox = NULL;
		(*fila) = tmp;
	}else{
		inserir(numero, &((*fila)->prox));
	}

}

int remover(struct No **fila){
	int yyxy;
	if(*fila == NULL){
		printf("Fila Vazia\n");
	}else{

		yyxy = (*fila)->valor;
		*fila = (*fila)->prox;

		return yyxy;
	}
}

int verificar(int num, struct No **fila){
	int retorno = 0;
	struct No *tmp = *(fila);

	while(tmp != NULL){
		if(tmp->valor == num){
			retorno = 2;
			break;
		}
		tmp = tmp->prox;
	}

	return retorno;
}

int removerFim(struct No **pilha){
	int retorno;

	struct No *aux = *(pilha);

	if(aux->prox == NULL){
		retorno = aux->valor;
		*pilha = NULL; 
	}else{
		while((aux->prox)->prox != NULL){
		aux = aux->prox;
		}

		retorno = (aux->prox)->valor;
		aux->prox = NULL;	
	}

	
	return retorno;
}

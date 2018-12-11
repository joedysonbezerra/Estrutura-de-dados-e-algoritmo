#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   int valor;
   struct Lista *proximo;
}Lista;

Lista *inserir ();
Lista *separa();
void imprimir ();
int vazio ();



int main (int argc, char **argv) {
   Lista *lista = NULL;
   Lista *secundaria = NULL;
   lista = inserir(lista,1);
   lista = inserir(lista,12);
   lista = inserir(lista,5);
   lista = inserir(lista,17);
   lista = inserir(lista,3);
   imprimir(lista);
   secundaria = separa(lista, 5);
   imprimir(lista);
   imprimir(secundaria);
   return 0;
}

Lista *inserir (Lista *l, int valor) {
   Lista *novoElemento = (Lista*) malloc(sizeof(Lista)); 
   novoElemento->valor = valor;
   novoElemento->proximo = (struct Lista*) l;
   return novoElemento;
}

Lista *separa(Lista *l, int n) {
   Lista *p1 = l;
   Lista *p2 = NULL;
   if(vazio(l)){
      printf("Lista Vazia não tem como separar !!!");
      return NULL;
   }
   while(p1 != NULL && p1->valor != n ) {
      p2 = p1;
      p1 = (Lista*) p1->proximo;
   }
   if(vazio(p1)){
      printf("Não encontrei o numero que você pediu para separar, não tem como separar !!!");
      return NULL;
   }else{
      p2 = p1;
      p1 = (Lista*) p1->proximo;
      p2->proximo = NULL;
      return p1;
   }

}

void imprimir (Lista *l) {
   Lista *ponteiro = l;
   if(vazio(l)){
      printf("Lista Vazia!!!");
      return;
   }
   while(ponteiro != NULL){
      printf("%d\t", ponteiro->valor);
      ponteiro = (Lista*) ponteiro->proximo;
   }
   printf("\n");
}
int vazio (Lista *l) {
   return (l == NULL);
}
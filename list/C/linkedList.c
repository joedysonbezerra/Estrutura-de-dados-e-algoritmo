#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
   char name[10];
   int quantity;
};

typedef struct {
   struct product products;
   struct Node *next;
}Node;

Node *insert ();
Node *removeNode ();
void print ();
int empty ();
void erro();


int main (int argc, char **argv) {
   Node *list = NULL;
   list = insert(list,"Abacaxi",4);
   list = insert(list,"axi",4);
   list = insert(list,"Aba",4);
   print(list);
   list = removeNode(list,"axi");

   print(list);


   return 0;
}

Node *insert (Node *list, char name[10], int quantity) {
   Node *new = (Node*) malloc(sizeof(Node)); 
   strcpy(new->products.name,name);
   new->products.quantity = quantity;
   new->next = (struct Node*) list;
   return new;
}

void print (Node *list) {
   Node *pointer = list;
   if(empty(list)){
      printf("Lista Vazia!!!");
      return;
   }
   while(pointer != NULL){
      printf("Produto: Nome:%s  Quantidade:%d\n", pointer->products.name, pointer->products.quantity);
      pointer = (Node*) pointer->next;
   }
}

Node* removeNode(Node *list, char name[10]) {
   Node *p = list;
   Node *prior = NULL;
   while(p != NULL && (strcmp(p->products.name,name) != 0)) {
      prior = p;
      p = (Node*) p->next;
   }
   if(empty(p)){
      return list;
   }else{
      prior->next = p->next;
   }
   free(p);
   return list;
}

int empty (Node *list) {
   return (list == NULL);
}

void erro(char message[]) {
   printf("\033[31m %s\033[37m\n",message);
}


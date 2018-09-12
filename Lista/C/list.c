#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

struct product {
   char name[100];
   float price;
};

typedef struct { 
   int length;
   struct product objects[MAX];
}list;

void Erro();
void Print();
void Search();
list *Create();
int Empty(); 
int Full(); 

int main(int argc, char **argv) {
   

   list *Food = Create();


   return 0;
}
list *Create() {
   list *new = (list*) malloc(sizeof(list));
   if(new == NULL) {
      Erro("Erro na criação da lista estática");
   }else {
      printf("\033[32m Lista criada com sucesso\n"); 
      new->length = 0;
   }

   return new;
}

void Search(list *object, char name[]) {
   for(int i = 0; i < (object->length); i++){
      if(strcmp(object->objects[i].name,name) == 0){
         printf("%s",object->objects[i].name);
         printf("%f",object->objects[i].price);
         return 1;
      };
   }
   Erro("Não Encontrado !!!");
   return 0;
}

int Empty(list *object) {
   if(object->length == 0){
      printf("Lista Vazia");
      return 1;
   }
   return 0;
}

int Full(list *object) {
      if(object->length == MAX){
      printf("Lista Cheia");
      return 1;
   }
   return 0;
}

void Print(list *object) {
   printf("| ");
   for(int i = (MAX - 1); i >= 0; i--) {
     // printf("%d | ",list[i]);
   }
   printf("\n");
}

void Erro(char message[]) {
   printf("\033[31m %s\n",message);
   exit(1);
}
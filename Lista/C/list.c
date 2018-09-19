#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

struct product {
   char name[10];
   int quantity;
};

typedef struct { 
   int length;
   struct product objects[MAX];
}List;

void erro();
void print();
void insert();
int search();
List *create();
int empty(); 
int full(); 

int main(int argc, char **argv) {
   
   List *food = create();
   insert(food, "Chocolate1", 3, 1);
   insert(food, "Chocolate2", 3, 2);
   insert(food, "Chocolate3", 3, 2);
   insert(food, "Chocolate4", 3, 1);
   print(food);

   return 0;
}

List *create() {
   List *new = (List*) malloc(sizeof(List));
   if(new == NULL) {
      erro("Erro na criação da lista estática");
   }else {
      printf("\033[32mLista criada com sucesso\033[37m\n"); 
      new->length = 0;
   }
   return new;
}

void insert(List *object,char name[],int quantity,int type){
   int result = full(object);
   if(result == 1){
      erro("Impossivel inserir !!!");
   }else{
      switch (type){
         case 1: // Insere no começo
            if(empty(object) == 1){
               object->length++;
               object->objects[0].quantity = quantity;
               strcpy(object->objects[0].name,name);
            }else{
               for(int i = (object->length - 1); i >= 0; i-- ){
                  object->objects[i+1].quantity = object->objects[i].quantity;
                  strcpy(object->objects[i+1].name,object->objects[i].name);
               }
               object->objects[0].quantity = quantity;
               strcpy(object->objects[0].name,name);
               object->length++;
            }
            break;
            case 2: // Insere no final
               object->length++;
               object->objects[object->length-1].quantity = quantity;
               strcpy(object->objects[object->length-1].name,name);
               break;
         default:
            erro("Não reconheço esse tipo de inserir dados!");
            printf("1- Inserir no começo | 2 - Inserir no final");
            break;
      }

   }


}

int search(List *object, char name[]) {
   for(int i = 0; i < (object->length); i++) {
      if(strcmp(object->objects[i].name,name) == 0) {
         printf("Nome:%s\nQuantidade:%d\n",object->objects[i].name,object->objects[i].quantity);
         return 1;
      };
   }
   erro("Não Encontrado !!!");
   return 0;
}

int empty(List *object) {
   if(object->length == 0) {
      return 1;
   }
   return 0;
}

int full(List *object) {
   if(object->length == MAX) {
      printf("Lista Cheia\n");
      return 1;
   }
   return 0;
}

void print(List *object) {
   int result = empty(object);
   if(result != 1){
      printf("|");
      for(int i = 0; i < (object->length); i++) {
         printf("Nome:%s Quantidade:%d |",object->objects[i].name,object->objects[i].quantity);
      }
      printf("\n");
   }else{
      printf("A lista não possue dados para impressão\n");  
   }
}

void erro(char message[]) {
   printf("\033[31m %s\033[37m\n",message);
}
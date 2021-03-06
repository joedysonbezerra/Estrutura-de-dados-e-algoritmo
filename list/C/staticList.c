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
   struct product products[MAX];
}List;

List *create();
void insert();
void delete();
int search();
int empty(); 
int full(); 
void print();
void size();
void erro();
void kill();

int main(int argc, char **argv) {
   
   List *food = create();
   insert(food, "Chocolate1", 3, 1);
   insert(food, "Chocolate2", 3, 2);
   insert(food, "Chocolate3", 3, 2);
   insert(food, "Chocolate4", 3, 1);
   print(food);
   delete(food,1);
   print(food);
   delete(food,2);
   print(food);
   insert(food, "Chocolate3", 3, 2);
   insert(food, "Chocolate4", 3, 2);
   print(food);
   delete(food,3);
   size(food);
   print(food);
   kill(food);

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

void insert(List *object,char name[],int quantity,int type) {
   if(full(object) == 1) {
      erro("Impossivel inserir !!!");
   }else {
      switch (type){
         case 1: // Insere no começo
            if(empty(object) == 1) {
               object->length++;
               object->products[0].quantity = quantity;
               strcpy(object->products[0].name,name);
            }else{
               for(int i = (object->length - 1); i >= 0; i-- ) {
                  object->products[i+1].quantity = object->products[i].quantity;
                  strcpy(object->products[i+1].name,object->products[i].name);
               }
               object->products[0].quantity = quantity;
               strcpy(object->products[0].name,name);
               object->length++;
            }
            break;

         case 2: // Insere no final
            object->length++;
            object->products[object->length-1].quantity = quantity;
            strcpy(object->products[object->length-1].name,name);
            break;

         default:
            erro("Não reconheço esse tipo de inserir dados!");
            printf("1- Inserir no começo | 2 - Inserir no final");
            break;
      }

   }

}

void delete(List *object,int type){
   int position;
   if(empty(object) == 1) {
      erro("Impossivel remover !!!");
   }else {
      switch (type){
         case 1: // remove no começo
               for(int i = 1; i <= (object->length - 1); i++ ) {
                  object->products[i-1].quantity = object->products[i].quantity;
                  strcpy(object->products[i-1].name,object->products[i].name);
               }
               object->length--;
            break;

         case 2: // remove no final
            object->length--;
            break;
         case 3: // remove em qualquer posição
            printf("Posição:");
            scanf("%d",&position);
            printf("\n");

            if(position < object->length) {
               for(int i = (position+1); i <= (object->length - 1); i++ ) {
                  object->products[i-1].quantity = object->products[i].quantity;
                  strcpy(object->products[i-1].name,object->products[i].name);
               }
               object->length--;
            }
            break;

         default:
            erro("Não reconheço esse tipo para remover dados!");
            printf("1- remove no começo | 2 - remove no final");
            break;
      }
   }
}

int search(List *object, char name[]) {
   for(int i = 0; i < (object->length); i++) {
      if(strcmp(object->products[i].name,name) == 0) {
         printf("Nome:%s\nQuantidade:%d\n",object->products[i].name,object->products[i].quantity);
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
   if(result != 1) {
      printf("|");
      for(int i = 0; i < (object->length); i++) {
         printf("Nome:%s Quantidade:%d |",object->products[i].name,object->products[i].quantity);
      }
      printf("\n");
   }else {
      printf("A lista não possue dados para impressão\n");  
   }
}

void size(List *object) {
   printf("O tamanho da lista é:%d\n",object->length);
}

void erro(char message[]) {
   printf("\033[31m %s\033[37m\n",message);
}

void kill(List *object) {
   free(object);
}
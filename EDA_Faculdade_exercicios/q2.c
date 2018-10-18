#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct { 
   int length;
   int value[MAX];
}Queue;

Queue *create();
void reverse();
void insert();
int empty(); 
int full(); 
void print();


int main(int argc, char **argv) {
   
   Queue *number = create();
   insert(number,5);
   insert(number,4);
   insert(number,3);
   insert(number,2);
   insert(number,1);
   insert(number,0);
   insert(number,6);
   print(number);
   reverse(number);
   print(number);

   return 0;
}

Queue *create() {
   Queue *new = (Queue*) malloc(sizeof(Queue));
   if(new == NULL) {
      printf("Erro na criação da Fila estática\n");
   }else { 
      new->length = 0;
   }
   return new;
}

void insert(Queue *object,int value) {
   if(full(object) == 1) {
      printf("Impossivel inserir !!!\n");
   }else {
      object->length++;
      object->value[object->length-1]= value;
   }

}
void reverse(Queue *object) {
   Queue *new = create();
   for(int i = (object->length-1); i >= 0; i--) {
      insert(new,object->value[i]);
   }
   object->length = 0;
   for(int i = 0; i < (new->length); i++) {
      insert(object,new->value[i]);
   }
   free(new);
}
int empty(Queue *object) {
   if(object->length == 0) {
      printf("fila Vazia\n");
      return 1;
   }
   return 0;
}

int full(Queue *object) {
   if(object->length == MAX) {
      printf("fila Cheia\n");
      return 1;
   }
   return 0;
}

void print(Queue *object) {
   int result = empty(object);
   if(result != 1) {
      printf("|");
      for(int i = 0; i < (object->length); i++) {
         printf("%d |",object->value[i]);
      }
      printf("\n");
   }else {
      printf("A fila não possue dados para impressão\n");  
   }
}
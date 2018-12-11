#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct { 
   int length;
   int value[MAX];
}Queue;

Queue *create();
int reverse();
void insert();
int empty(); 
int full(); 
void print();
void pop();
void push();


int main(int argc, char **argv) {
   
   Queue *queue1 = create();
   Queue *queue2 = create();
   insert(queue1,5);
   insert(queue1,4);
   insert(queue1,3);
   insert(queue1,2);
   insert(queue1,1);
   insert(queue1,0);
   insert(queue1,6);
   print(queue1);
   pop(queue1,queue2);
   pop(queue1,queue2);
   pop(queue1,queue2);
   print(queue1);
   print(queue2);
   pop(queue2,queue1);
   push(queue1,5);
   print(queue1);
   print(queue2);
   return 0;
}
void pop(Queue *q1,Queue *q2) {
   insert(q2,reverse(q1));
   q1->length--;
}
void push(Queue *object, int value){
   insert(object,value);
}

Queue *create() {
   Queue *new = (Queue*) malloc(sizeof(Queue));
   if(new == NULL) {
      printf("Erro na criação da Fila \n");
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
int reverse(Queue *object) {
   Queue *new = create();
   for(int i = (object->length-1); i >= 0; i--) {
      insert(new,object->value[i]);
   }
   return new->value[0];
}

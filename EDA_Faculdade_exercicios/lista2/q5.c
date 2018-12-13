#include <stdio.h>
#include <stdlib.h>

#define MAX 13

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

void init();
void snapshot();
void insertCall();
void breadthFirstSearch();
int verificar();



int main(int argc, char const *argv[]){

	Queue *support = create();
	
	int Graph[13][13];
	init(Graph);
	insertCall(0,1,Graph);
	insertCall(0,2,Graph);
	insertCall(0,3,Graph);

	insertCall(1,0,Graph);
	insertCall(1,2,Graph);

   insertCall(2,0,Graph);
	insertCall(2,1,Graph);
	insertCall(2,4,Graph);
	insertCall(2,5,Graph);

	insertCall(3,0,Graph);
	insertCall(3,7,Graph);

   insertCall(4,2,Graph);
	insertCall(4,5,Graph);

   insertCall(5,2,Graph);
	insertCall(5,4,Graph);
   insertCall(5,6,Graph);

   insertCall(6,5,Graph);
	insertCall(6,7,Graph);
   insertCall(6,8,Graph);

   insertCall(7,3,Graph);
   insertCall(7,6,Graph);
	insertCall(7,8,Graph);

   insertCall(8,6,Graph);
   insertCall(8,7,Graph);
	insertCall(8,9,Graph);
   insertCall(8,12,Graph);

   insertCall(9,8,Graph);
   insertCall(9,10,Graph);
   insertCall(9,12,Graph);

   insertCall(10,9,Graph);
   insertCall(10,11,Graph);

   insertCall(11,10,Graph);
   insertCall(11,12,Graph);

   insertCall(12,8,Graph);
   insertCall(12,9,Graph);
   insertCall(12,11,Graph);
	snapshot(Graph);

	breadthFirstSearch(Graph,support);
	return 0;
}

void init(int Graph[13][13]){
	for(int i = 0; i < 13; i++){
		for(int j = 0; j < 13; j++){
			Graph[i][j] = 0;	
		}
	}
}

void snapshot(int Graph[13][13]){
	for (int i = 0; i < 13; i++){
		printf("%d |",i);
		for(int j = 0; j < 13; j++){
			if(Graph[i][j] == 1){
				printf("%d ->",j);
			}
		}
		printf("\n");
	}
}

void insertCall(int x, int y, int Graph[13][13]){
	Graph[x][y] = 1;
}

void breadthFirstSearch(int Graph[13][13], Queue *object){
	insert(object,0);
	

		for(int i = 0; i < 13; i++){
			if(Graph[object->value[object->length-1]][i] == 1){
				if(verificar(i,object) == 0){
					insert(object,i);
				}
			}
		}
	print(object);
}

int verificar(int num, Queue *object){
	int x = 0;
	Queue *tmp = object;
	for(int i = 0; i<tmp->length;i++){
		if(tmp->value[i] == num){
			x = 2;
			break;
		}
	}

	return x;
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
      object->value[object->length]= value;
		object->length++;
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
void print(Queue *object) {
      printf("|");
      for(int i = 0; i < (object->length); i++) {
         printf("%d |",object->value[i]);
      }
      printf("\n");
}

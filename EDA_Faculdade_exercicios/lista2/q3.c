#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct sensor{
   int date;
   int value;
};

typedef struct { 
   int length;
   struct sensor sensors[MAX];
}List;

List *create();
void insert();
int empty(); 
int full(); 
void print();
void erro();
void insertionSort();


int main(int argc, char **argv){
   
   List *data = create();
   insert(data, 5, 5);
   insert(data, 23, 23);
   insert(data, 21, 21);
   insert(data, 10, 10);
   insert(data, 40, 40);

   print(data);
   insertionSort(data);
   print(data);

}
List *create() {
   List *new = (List*) malloc(sizeof(List));
   if(new == NULL) {
      erro("Erro na criação da lista estática");
   }else {
      new->length = 0;
   }
   return new;
}

void insert(List *data,int pDate,int pValue) {
   if(full(data) == 1) {
      erro("Impossivel inserir !!!");
   }else {
            if(empty(data) == 1) {
               data->sensors[0].date = pDate;
               data->sensors[0].value = pValue;
               data->length++;
            }else{
               for(int i = (data->length - 1); i >= 0; i-- ) {
                  data->sensors[i+1].value = data->sensors[i].value;
                  data->sensors[i+1].date = data->sensors[i].date;
               }
               data->sensors[0].date = pDate;
               data->sensors[0].value = pValue;
               data->length++;
            }
   }
}
int empty(List *data) {
   if(data->length == 0) {
      return 1;
   }
   return 0;
}

int full(List *data) {
   if(data->length == MAX) {
      printf("Lista Cheia\n");
      return 1;
   }
   return 0;
}

void print(List *data) {
   int result = empty(data);
   if(result != 1) {
      for(int i = 0; i < (data->length); i++) {
         printf("Data:%d\n valor:%d\n\n ",data->sensors[i].date,data->sensors[i].value);
      }
      printf("\n");
   }else {
      printf("A lista não possue dados para impressão\n");  
   }
}

void erro(char message[]) {
   printf("%s\n",message);
}

void insertionSort(List *data) {
    int i, j, pivotDate, pivotValue = 0;
    for(i=1; i < data->length; i++) {
        pivotDate = data->sensors[i].date;
        pivotValue = data->sensors[i].value;
        j = i-1;
        while(j >= 0 && data->sensors[j].date > pivotDate){
            data->sensors[j+1].date = data->sensors[j].date;
            data->sensors[j+1].value = data->sensors[j].value;
            j--;
        }
        data->sensors[j+1].date = pivotDate;
        data->sensors[j+1].value = pivotValue;
    }
}

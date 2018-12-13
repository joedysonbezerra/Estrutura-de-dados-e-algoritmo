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
void mergeSort();
void merge();


int main(int argc, char **argv){
   
   List *data = create();
   insert(data, 5, 5);
   insert(data, 23, 23);
   insert(data, 21, 21);
   insert(data, 50, 50);
   insert(data, 10, 10);
   insert(data, 40, 40);

   print(data);
   insertionSort(data);
   //mergeSort(data,0,(data->length-1));
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
            data->sensors[j+1] = data->sensors[j];
            j--;
        }
        data->sensors[j+1].date = pivotDate;
        data->sensors[j+1].value = pivotValue;
    }
}

void mergeSort(List *data, int first, int last){
        if (first == last) return;
        int middle = (( first + last) / 2);
        mergeSort(data, first, middle);
        mergeSort(data, (middle + 1), last);
        merge(data, first, last, middle);

}

void merge(List *data, int first, int last, int middle){
   int i, j, k;
   int a_size = middle-first+1;
   int b_size = last-middle;
   List *a = (List*) malloc(sizeof(List) * a_size);
   List *b = (List*) malloc(sizeof(List) * b_size);
   for (i = 0; i < a_size; i++){
      a->sensors[i] = data->sensors[i+first];
   } 
      
   for (i = 0; i < b_size; i++) {
      b->sensors[i] = data->sensors[i+middle+1];
   }
   for (i = 0, j = 0, k = first; k <= last; k++) {
      if (i == a_size){
         data->sensors[k] = b->sensors[j++];
      } 
      else if (j == b_size){
         data->sensors[k]  = a->sensors[i++];
      }else if ( a->sensors[i].date < b->sensors[j].date){
         data->sensors[k] = a->sensors[i++];
      } else{
         data->sensors[k] = b->sensors[j++];   
      } 
   }
   free(a); free(b);
}

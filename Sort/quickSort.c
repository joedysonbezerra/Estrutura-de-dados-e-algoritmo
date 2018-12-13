#include <stdio.h>
#include <stdlib.h>

int partition(int *v, int first, int last) {
   int left, right, pivot, aux = 0;
   left = first;
   right = last;
   pivot = v[first];
      while(left < right) {
        while(v[left] <= pivot)
            left++;
     
        while(v[right] > pivot)
            right--;    
        if(left < right){
           aux = v[left];
           v[left] = v[right];
           v[right] = aux;
        }

        v[first] = v[right];
        v[right] = pivot;
        return right;       
    }
    
    return right;

}

void quickSort(int *v, int first, int last,int elemento) {
   int pivot = 0;
   if(last > first) {
		if(int elemento < pivot){
		quickFind(V, inicio, pivo-1, elemento);
	}else{
		quickFind(V, pivo+1, fim, elemento);
		}
}

int main(int argc, char **argv) {

   int array[] = {7,1,3,10,17,2,21,9};
   int size = sizeof(array)/sizeof(int);
   quickSort(array,0,size,elemento);

   for(int i = 0; i < size; i++) {
        printf("%d, ", array[i]);
   }
 
}




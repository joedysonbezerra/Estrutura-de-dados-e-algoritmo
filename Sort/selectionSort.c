#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv) {
   int v[] = {3,2,1,5,7,9,8};
   int min, troca = 0;
   
   for(int i = 0; i < (sizeof(v)/sizeof(int)); i++) {
      min = i;
      for(int j = i+1; j < (sizeof(v)/sizeof(int)); j++) {
         if(v[j] < v[min]) {
            min = j;
         }
         if(i != min) {
            troca = v[i];
            v[i] = v[min];
            v[min] = troca;
         }
      }
   }
   
   for(int x = 0; x < (sizeof(v)/sizeof(int)); x++) {
      printf("%d",v[x]);
   }


}

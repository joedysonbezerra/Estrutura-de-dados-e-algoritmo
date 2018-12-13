#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
   int v[] = {3,2,1,5,7,4,9,8};
   int aux,z = 0;
   for(int x = (sizeof(v)/sizeof(int)); x >= 0; x--) {
      z = 0;
        for(int y = 0; y <= x; y++) {
            if(v[y] > v[y+1]){
               aux = v[y];
               v[y] = v[y+1];
               v[y+1] = aux;
               z++;         
            }
        }
        z--;
        if(z == 0) break;
    }
   for(int x = 0; x < (sizeof(v)/sizeof(int)); x++) {
      printf("%d",v[x]);
   }
}
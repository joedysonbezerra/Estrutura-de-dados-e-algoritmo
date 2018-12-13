function partition(array,first,last){
   let pivot = array[last];
   console.log(pivot);
   while ( first < last ){
       while ( array[first] < pivot ){
          first++;
          console.log("1º");
          console.log(array);
          console.log(first);
       };
       while ( array[last] > pivot ){
          last--;
          console.log("2º");
          console.log(array);
          console.log(last);
       }
       if (array[first] == array[last] ){
         console.log("3º");
         console.log(array);
         console.log(first);
      }else if ( first < last ) {
           let aux = array[first];
           array[first] = array[last];
           array[last] = aux;
           console.log(array);
       }
   }
   
   return last;
}

function quickFind(array,first,last,position){
   let pivot = partition(array,first,last);

   if (pivot == position - 1){
       return array[pivot];
   }else if (position - 1 < pivot){
       return quickFind(array, first, pivot - 1, position);
   }else{
       return quickFind(array, pivot + 1, last, position);
   }
}


function main(){

    let array = [7,1,3,10,17,2,21,9];
    const n = 5;

   console.log("O"+ n + "º menor elemento: " + quickFind(array,0,7,n));

}

main();
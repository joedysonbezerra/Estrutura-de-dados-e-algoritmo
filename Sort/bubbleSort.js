let vetor =[5,7,9,2,6,3,8,4,1];
//Antes
console.log(vetor);

//Ordenação de vetor Input(vetor unidimensional) 
//Output(vetor unidimensional ordenado)
function bubbleSort(){
    for(let x = (vetor.length - 1); x >= 0; x--){
        for(let y = 0; y <= x; y++){
            if(vetor[y] > vetor[y+1]){
                [vetor[y],vetor[y+1]] = [vetor[y+1],vetor[y]];
                
            }

        }
    }
    console.log(vetor); //Depois
}
bubbleSort();
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
   int value;
   int fb;
   struct Node *left;
   struct Node *right;
}BinaryTree;

BinaryTree *insert();
BinaryTree *create();
BinaryTree *rotation();
void print();
int isEmpty();

int main(int argc, char **argv) {
   BinaryTree *tree = create();
   tree = insert(tree,10);
   tree = insert(tree,5);
   tree = insert(tree,3);
   tree = insert(tree,6);

   print(tree);

   return 0;

}
BinaryTree *create() {
   return NULL;
}

void print(BinaryTree *base) {
	if(!isEmpty(base)) {
      printf("%d\n", base->value);
		print(base->left);
		print(base->right);
   }
}

BinaryTree *insert(BinaryTree *base, int pValue) {
   if(isEmpty(base)) {
         base = (BinaryTree*) malloc(sizeof(BinaryTree));
      if(base == NULL) {
         printf("Erro na criação da Arvore Binaria\n");
      }else{
         base->value = pValue;
         base->left = NULL;
         base->right = NULL;
         base->fb = 0;
      }
   }else if(pValue < base->value) {
         base->left = insert(base->left,pValue);
         base->fb++; 
      }else {
         base->right = insert(base->right,pValue);
         base->fb--;
   }
   base = rotation(base);
   return base;
}

BinaryTree *rotation(BinaryTree *base) {
   BinaryTree *aux;
   if(base->fb < -1) {
      aux = base->right;
      base->right = base->right->left;
      aux->left = base;
      base = aux;
   }else if(base->fb > 1) {
      aux = base->left;
      base->left = base->left->right;
      aux->right = base;
      base = aux;
   }
   return base;

}

int isEmpty(BinaryTree *base) {
   return(base == NULL);
}
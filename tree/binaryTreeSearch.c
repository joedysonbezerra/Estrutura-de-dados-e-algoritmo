#include<stdio.h>
#include<stdlib.h>
#define FALSE 0;
#define TRUE 1;

typedef struct Node {
   int value;
   struct Node *left;
   struct Node *right;
}BinaryTree;

BinaryTree *insert();
BinaryTree *create();
BinaryTree *freeTree();
int isEmpty();
int search();
void print();
void erro();

int main(int argc, char **argv) {
   BinaryTree *tree = create();
   tree = insert(tree,5);
   tree = insert(tree,3);
   tree = insert(tree,6);
   tree = insert(tree,7);

   print(tree);

}
BinaryTree *create() {
   return NULL;
}

BinaryTree *insert(BinaryTree *base, int pValue) {
   if(isEmpty(base)) {
         base = (BinaryTree*) malloc(sizeof(BinaryTree));
      if(base == NULL) {
         erro("Erro na criação da Arvore Binaria");
      }else{
         base->value = pValue;
         base->left = NULL;
         base->right = NULL;
      }
   }else if(pValue < base->value) {
      if(isEmpty(base->left)) {
         base->left = insert(base->left,pValue);
      } 
      }else {
         base->right = insert(base->right,pValue);
   }
   return base;
}

void print(BinaryTree *base) {
	if(!isEmpty(base)) {
		printf("%d\n", base->value);
		print(base->left);
		print(base->right);
   }
}
int search(BinaryTree *base, int value) {
   if(isEmpty(base)) {
      return FALSE;
   }else {
      if(base->value == value) {
         return TRUE;
      }else {
         search(base->left,value);
         search(base->right,value);
      }
   }
}
int isEmpty(BinaryTree *base) {
   return(base == NULL);
}

BinaryTree *freeTree(BinaryTree *base) {
   if(!isEmpty(base)) {
      freeTree(base->left);
      freeTree(base->right);
      free(base);
   }
   return NULL;

}
void erro(char message[]) {
   printf("%s\n",message);
}
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
   tree = insert(5,insert(6,create(),insert(8,create(),create())),insert(7,create(),create()));
   print(tree);
   printf("%d\n",search(tree,7));
   tree = freeTree(tree);
   print(tree);


}
BinaryTree *create() {
   return NULL;
}

BinaryTree *insert(int pValue, struct Node *left, struct Node *right) {
   BinaryTree *new = (BinaryTree*) malloc(sizeof(BinaryTree));
   if(new == NULL) {
      erro("Erro na criação da Arvore Binaria");
   }else {
      new->value = pValue;
      new->left = left;
      new->right = right;
   }
   return new;
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
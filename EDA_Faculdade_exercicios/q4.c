// Num sistema de arquivos, um catálogo de todos os arquivos é organizado como 
// uma árvore de busca binária. Cada nó denota um arquivo e especifica seu nome e, 
// entre outras coisas,a data de seu último acesso, codificada como um inteiro. 
// Escreva um programa que percorra a árvore e apague todos os arquivos cujos 
// últimos acessos tenham sido anteriores a uma certa data. 
// As chaves do catálogo são os nomes dos arquivos.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct archive {
   char name[30];
   int size;
   int date_Of_Last_Acess;
};

typedef struct node {
   struct archive docs;
   struct node *left;
   struct node *right;
}BinaryTree;

BinaryTree *insert();
BinaryTree *delete();
BinaryTree *searchremove();
int isEmpty();
void erro();
void print();

int main(int argc, char **argv) {
   BinaryTree *archivesSystem = NULL;

   archivesSystem = insert(archivesSystem, "jj", 18, 203918);
   archivesSystem = insert(archivesSystem, "cc", 17, 203913);
   archivesSystem = insert(archivesSystem, "bb", 16, 200);
   archivesSystem = insert(archivesSystem, "aa", 15, 203911);
   archivesSystem = insert(archivesSystem, "ee", 14, 200);
   archivesSystem = insert(archivesSystem, "dd", 13, 203910);
   archivesSystem = insert(archivesSystem, "ff", 13, 203910);
   archivesSystem = insert(archivesSystem, "ii", 13, 203919);
   archivesSystem = insert(archivesSystem, "hh", 13, 203960);
   archivesSystem = insert(archivesSystem, "tt", 13, 203960);
   archivesSystem = insert(archivesSystem, "vv", 13, 300000);
   archivesSystem = insert(archivesSystem, "oo", 13, 203960);
   archivesSystem = insert(archivesSystem, "pp", 13, 200000);
   archivesSystem = insert(archivesSystem, "uu", 13, 203960);
   archivesSystem = insert(archivesSystem, "zz", 13, 203960);
   archivesSystem = insert(archivesSystem, "xx", 13, 203960);
   archivesSystem = insert(archivesSystem, "ww", 13, 203960);
   archivesSystem = insert(archivesSystem, "yy", 13, 203960);
   
   print(archivesSystem);
   printf("\n");
   archivesSystem = searchremove(archivesSystem,300);

   print(archivesSystem);
   return 0;
}

BinaryTree *insert(BinaryTree *base, char name[30], int size, int date_Of_Last_Acess) {
   
   if(isEmpty(base)) {
         base = (BinaryTree*) malloc(sizeof(BinaryTree));
      if(base == NULL) {
         erro("Erro na criação da Arvore Binaria");
      }else{
         strcpy(base->docs.name,name);
         base->docs.size = size;
         base->docs.date_Of_Last_Acess = date_Of_Last_Acess;
         base->left = NULL;
         base->right = NULL;
      }
   }else if (strcmp(base->docs.name,name) > 0) {
      base->left = insert(base->left, name, size, date_Of_Last_Acess);
   }else if (strcmp(base->docs.name,name) < 0) {
      base->right = insert(base->right, name, size, date_Of_Last_Acess);
   }else{
      erro("Erro na inserção na arvore");
   }

   return base;

}

void print(BinaryTree *base){
   if(!isEmpty(base)) {
      printf("%s->",base->docs.name);
      print(base->left);
      print(base-> right);
   }
}

int isEmpty(BinaryTree *base) {
   return (base == NULL);
}
void erro(char message[]) {
   printf("%s\n",message);
}

BinaryTree *searchremove(BinaryTree *base,int data) {
   if(!isEmpty(base)) {
      if(base->docs.date_Of_Last_Acess < data) {
        base = delete(base);
      }
      base->left = searchremove(base->left, data);
      base->right = searchremove(base->right,data);
   }
   return base;
}

BinaryTree *delete(BinaryTree *base) {
   if(isEmpty(base->left) && isEmpty(base->right)) {
      BinaryTree *aux = NULL;
      base = aux;
   }else if(isEmpty(base->left)) {
      BinaryTree *aux = base;
      base = base->right;
      free(aux); 
   }else if(isEmpty(base->right)) {
      BinaryTree *aux = base;
      base = base->left;
      free(aux);
   }else {
			BinaryTree *aux = base->right;
			while(aux->left != NULL) {
				aux = aux->left;
         }
         strcpy(base->docs.name, aux->docs.name);
         base->docs.size = aux->docs.size;
         base->docs.date_Of_Last_Acess = aux->docs.date_Of_Last_Acess;
         base->right = delete(base->right);
}

   return base;
}



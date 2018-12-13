#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
   char name[40];
   int phone;
};
typedef struct node {
   struct contact newContact;
   int heightLeft;
   int heightRight;
   struct node *left;
   struct node *right;
}AvlTree;

AvlTree *create();
AvlTree *rotateRight();
AvlTree *rotateLeft();
AvlTree *insert();
AvlTree *search();
AvlTree *delete();
int isEmpty();
int calcHeight();
int calcBalanceFactor();
AvlTree *balancing(AvlTree *list);
void printList(AvlTree *list);
void printErro();

int main(int argc, char **argv) {
   AvlTree *contactList = create();
   contactList = insert(contactList,"Jonatan",98443092);
   contactList = insert(contactList,"Joedyson",98493092);
   contactList = insert(contactList,"Bia",94493092);
   contactList = insert(contactList,"Ana",98453092);
   contactList = insert(contactList,"Deco",98495092);
   contactList = insert(contactList,"Bruno",94493092);
   contactList = insert(contactList,"Adriano",98453092);
   contactList = insert(contactList,"Elivelton",98495092);
   printf("%s\n",(search(contactList,"Joedyson")->newContact.name));
   contactList = delete(contactList,"Joedyson");
   printList(contactList);
   return 0;
}


AvlTree *create() {
   return NULL;
}

AvlTree *insert(AvlTree *list, char pName[], int pPhone) {
   if(isEmpty(list)) {
      list = (AvlTree *) malloc(sizeof(AvlTree));
      if(isEmpty(list)) {
         printErro("Erro ao inserir o novo contato na agenda");
      }else {
         strcpy(list->newContact.name,pName);
         list->newContact.phone = pPhone;
         list->left = NULL;
         list->right =NULL;
         list->heightLeft = 0;
         list->heightRight = 0;
      }
   }else if(strcmp(list->newContact.name,pName) > 0) {
      list->left = insert(list->left,pName,pPhone);
      list->heightLeft = calcHeight(list->left->heightRight,list->left->heightLeft);

   }else if(strcmp(list->newContact.name,pName) < 0) {
      list->right =insert(list->right,pName,pPhone);
      list->heightRight = calcHeight(list->right->heightRight,list->right->heightLeft);
   }

   return balancing(list);
   
}

//Calculando a altura da arvore
int calcHeight(int pHeightRight, int pHeightLeft) {
   int result = 0;
   if(pHeightRight > pHeightLeft) {
      result = pHeightRight + 1;
   }else {
      result = pHeightLeft + 1;
   }

   return result;
}

AvlTree *rotateRight(AvlTree *base) {
   AvlTree *aux;
   aux = base->left;
   base->left = base->left->right;
   aux->right = base;
   base = aux;
}

AvlTree *rotateLeft(AvlTree *base) {
   AvlTree *aux;
   aux = base->right;
   base->right = base->right->left;
   aux->left = base;
   base = aux;
}

//Calculando o fator de balanceamento
int calcBalanceFactor(int pHeightRight, int pHeightLeft){
   return (pHeightRight - pHeightLeft);
}

AvlTree *balancing(AvlTree *list) {

   if(calcBalanceFactor(list->heightRight, list->heightLeft) == 2){
      
      if(calcBalanceFactor(list->right->heightRight, list->right->heightLeft) >= 0){
         list = rotateLeft(list);
      }else{
         list->right = rotateRight(list->right);
         list = rotateLeft(list);
      }
   
   }else if(calcBalanceFactor(list->heightRight, list->heightLeft) == -2) {
      
      if(calcBalanceFactor(list->left->heightRight, list->left->heightLeft) <= 0){
         list = rotateRight(list);
      }else{
         list->left = rotateLeft(list->left);
         list = rotateRight(list);
      }
   }
   return list;
}

int isEmpty(AvlTree *list) {
   return (list == NULL);
}

void printErro(char message[]) {
   printf("\033[31m %s\033[37m\n",message);
}

void printList(AvlTree *list) {
   if(!isEmpty(list)){
      printList(list->left);
      printf("Nome:%s\n Telefone:%d\n\n",list->newContact.name,list->newContact.phone);
      printList(list->right);
   }
}

AvlTree *search(AvlTree *base,char name[40]) {
   if(!isEmpty(base)) {
      if(strcmp(base->newContact.name,name) == 0) {
        return base;
      }else if(strcmp(base->newContact.name,name) > 0){
         search(base->left,name);
      }else {
         search(base->right,name);
      }
   }
}

AvlTree *delete(AvlTree *base,char name[]) {
   if(base == NULL){
      return NULL;  
   }else if(strcmp(base->newContact.name,name) > 0){
      base->left = delete(base->left,name);
   }else if(strcmp(base->newContact.name,name) < 0){
      base->right = delete(base->right,name);
   }else{
   if(isEmpty(base->left) && isEmpty(base->right)) {
      base = NULL;
      free(base);
   }else if(isEmpty(base->left)) {
      AvlTree *aux = base;
      base = base->right;
      free(aux); 
   }else if(isEmpty(base->right)) {
      AvlTree *aux = base;
      base = base->left;
      free(aux);
   }else {
         AvlTree *aux = base->right;
         while(aux->left != NULL) {
            aux = aux->left;
         }
         strcpy(base->newContact.name,aux->newContact.name);
         strcpy(aux->newContact.name,name);
         base->newContact.phone = aux->newContact.phone;
         base->right = delete(base->right,name);
         
         free(aux);
   }
}

   return base;
}
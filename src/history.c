#include "history.h"
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include <string.h>
//initalize

List* init_history(){ //history list 
  List *list = malloc(sizeof(List)); //allocate memory for list 
  list->root = NULL; //setting empty list 
  return list;
  
}


//add histiry item
void add_history(List *list, char *str){
  char **tokens= tokenize(str); //tokenize the input into array 
  for(int i=0; tokens[i] != NULL; i++){ //loop through each token 
    Item *newNode = malloc(sizeof(Item)); //allocate memory for the new items 
    if(newNode ==NULL){ //ckeck if null 
      return;
    }
    newNode->str =tokens[i]; //set the new node to curr token 
    newNode->next=NULL; //set to null 
    //id identify each token in the list 
    if(list->root ==NULL){ //if empty 
      newNode->id=1; //setting id 
      list->root=newNode; //set root to new node 
    }else{
      Item *temp = list->root; //else transverse using a temp variable 
      while(temp->next != NULL){ 
	temp = temp->next; 
      }
      newNode->id = temp->id+1; //set id to +1 
      temp->next = newNode;
    }
  }
}
 

//retrieve string 
char *get_history(List *list, int id){
  Item *current = list -> root; //initial ize the pointer so we can transverse the list 
  while (current != NULL){  //while loop until end 
    if(current -> id == id ){
      //checking if curr node matches what the input id is return string 
      return current ->str;
    }
    current = current ->next; //move to next 
  }
  return NULL;
}


//print history
void print_history(List *list){
  //check if empty  and print message 
  if(list-> root ==NULL){
    printf("History is empty\n");
    //return;
  }else{
    //initialize the pointer to transverse through the list 
    Item *node = list->root;
    while(node != NULL){ //while loop until the end 
      printf("> %d  %s\n", node->id,node->str); //printing id and string 
      node = node->next; //move to next 
    }
  }
  
}


//free history
void free_history(List *list){ 
  if (list == NULL){ //check if null 
    return;
  }
  //initialize pointer to currenr 
  Item *curr = list->root; 
  Item *next; //next pointer 
  while(curr != NULL){ 
    next = curr->next; ///set nect to curr 
    free(curr->str); //freeing string anf current node 
    free(curr);
    curr = next; //move to next 
  }
  free(list); //free list 
}











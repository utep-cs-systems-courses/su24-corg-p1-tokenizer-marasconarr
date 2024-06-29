#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

//check if if space 
int space_char(char c){
  //finding space 
  return  (c== ' '|| c == '\t');
    
} 

//find if not space 
int non_space_char(char c){
  return (c != ' ' &&  c != '\t');
}

//finding start of the token 
char *token_start(char *str){
  //skip any spaces
  while(*str !=  '\0' &&  space_char(*str)){
    str++;
  }

  //at the end return 0 
  if(*str == '\0'){
    return NULL;
  }
  //return the start pointer  
  return str;
}

// end of the word 
char *token_terminator(char *token){
  // we find space or when string ends
  while(*token != '\0' && non_space_char(*token) ==1){
   token++;
  }
  //return the terminator
  return token;
}

//count num of tokens
int count_tokens(char *str){ 
  //initiakize count
  int count = 0;
  //while loop goes till end of string              
  while(*str != '\0' && token_start(str) !=0){
    //move pointer  to end
    str = token_terminator(token_start(str));
    count++; //increment count 
  }

  //return total count
  return count; 
}


//copy striing
char *copy_str(char *inStr, short len){
  //allocate memory for new string
  char *copyStr = malloc((len +1)* sizeof(char));
  //add ponter to go through the new string
  char *sp = copyStr;
  for(int  i=0; i<len;i++){ //copying from input ro new string using pointer 
    *sp++ = *inStr++;
  }
  //terminator at end of string 
  *sp = 0;
  //return new string
  return copyStr;
  
}

//tokenize string 
char **tokenize(char *str){
  //count the tokens
  int count = count_tokens(str);
  //allocate memory for array 
  char **tokens = malloc((count + 1) * sizeof(char *));
  char *start = token_start(str); //gettimg the start og the first token  
  char *end; //pointer to mark the end
  int i=0; //index declaration 
  //while loop as long as in start  
  while(*start){
  //findstart and end of token to get the length 
    //using token terminator to find the end 
    end = token_terminator(start);
    tokens[i] = copy_str(start, end-start); //copy the curr token
    i++; //increment token index 
    start = token_start(end); 
  }

  tokens[count] = NULL; //reset to nul; 
  return tokens;
  //return tokens
  
}  
//print tokens
void print_tokens(char **tokens){
  //loop through the token array 
  for (int i = 0;tokens[i]!= NULL; i++){
    printf("token %d: %s\n ",i, tokens[i]);//printing index and the string
  }
}


//free tokens
void free_tokens(char **tokens){
  //loop through token array 
  for(int i=0;tokens[i] != NULL; i++){
    free(tokens[i]); //free the memory for each string 
  }
  free(tokens); 
}

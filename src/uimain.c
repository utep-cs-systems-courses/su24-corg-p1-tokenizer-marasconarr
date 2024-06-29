#include <stdio.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"
#define MAX_INPUT 250



//display menus for main and history options 
    void display_main_menu(){
      printf("Welcome to Tokenizer! please enter your options from below:\n");
      printf( "- 't' to tokenize\n- 'h for history\n-'q' to quit program\n");
      printf ("\n$");
    }
    void history_menu(){
      printf("Please enter from following option \n");
      printf("\n-'m' go back to main menu ");
      printf("\n-'!' display all history");
      printf("\n-'n' display history Item ");
      printf("\n-'c' clear current history");
      printf("\n$");
    }


int main() {
  //initalize variables that are used 
    char menu_input[MAX_INPUT];
    char history_input[MAX_INPUT];
    char input[MAX_INPUT];
    List *list = init_history();

   
 menu:
    //dhow main menu to give user options
      display_main_menu();
      while((menu_input[0] = getchar()) != EOF ){
	while(getchar() != '\n'){} //clear buffer for next input 
	switch (menu_input[0]){ //switch cases to organize functions
	case 't': 
	  goto tokenizer;
	case 'h':
	  goto history;
        case 'q':
	  printf("quitting program /n");
	  goto quit;
	default:
	  printf("option not available, please refer to menu and try again \n");
	  goto menu;
	}
      }

       
      

 tokenizer:
      //ask question and get user input 
     printf("enter a string you would like to tokenize: \n");
     printf("$ ");
     fgets(input, MAX_INPUT, stdin); //get input to staore in array 
     char *p = input; //pointer to point at beginning of user array 
     printf("This token is added to your histoy\n");
     add_history(list, input); //call add history function to add string
     char **tokens = tokenize(p);  //using tokenize function to store in pointer 
     print_tokens(tokens); //printing tokens 
     free_tokens(tokens);//free tokens
     goto menu;

 
     
 history:
     history_menu();
     fgets(history_input, MAX_INPUT,stdin);//user input
     switch(history_input[0]){ //switch CASE for inputs 
     case 'm':
       goto menu;
     case '!':
       print_history(list); //calling print
       goto history;
     case 'n':
       printf("which token would you like to view?\n");
       int id; //declare int to store 
       if (scanf("%d", &id)==1){ //reading the id
	 char *token = get_history(list, id); //get the token str from history 
         if(token != NULL){  //check if found if not print statement 
	   printf("%s\n",token);
         }else{
	   printf("Token %d not found\n", id);
	 }
       }else{
	 int c; //clearing buffer 
	   while ((c = getchar()) != '\n' && c != EOF );
         }
       
        goto history;
       
     case 'c':
       free_history(list); //free the current history 
       list = init_history(); //empty list 
       printf("History Cleared :) \n");
       goto history;
       // break;
     default: //option if input not recongnized
       printf("option not available, please refer to menu and try again \n");
       goto history;
       // break;
     }

  quit:
     free_history(list);
     return 0;
      


}
    
 

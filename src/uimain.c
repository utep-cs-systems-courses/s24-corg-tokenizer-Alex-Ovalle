#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int main()
{
  char input[100];
  char userOption;
  List *token_history = init_history();
  int userPos;
  char *user_token;

  while(1)
  {
    printf(">Enter '1' to tokenize a string, '2' to see token history, '3' for specific string in history, 'q' to quit: \n");
    scanf(" %c", &userOption);

    switch(userOption)
    {
      case '1':
	printf("Enter string to tokenize: ");
	scanf(" %[^\n]", input);
	
	char **tokens = tokenize(input);
	add_history(token_history, input);
	print_tokens(tokens);
	free_tokens(tokens);
	break;

      case '2':
	print_history(token_history);
	break;
	
      case '3':
	printf("Enter index of string to retreive: ");
	scanf(" %d", &userPos);

	user_token = get_history(token_history, userPos);
        if(user_token != NULL)
	  printf("Token: %s\n", user_token);
	else
	  printf("Invalid index.\n");
        break;

      case 'q':
	printf("Exiting.\n");
	return 0;

      default:
	printf("Invalid input.\n");
    }
  }
  return 0;
}

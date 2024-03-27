#include <stdio.h>
#include <stdlib.h>
#include "history.h"


/* Initialize the linked list to keep the history. */
List* init_history()
{
  List *token_hist = (List*)malloc(sizeof(List));
  if(token_hist!=NULL)
    token_hist -> root = NULL;

  return token_hist;
}


/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  Item *temp = (Item*)malloc(sizeof(Item));
  if(temp == NULL)
    return;

  // copying string
  int len = 0;
  while(str[len]!='\0' && str[len]!='\n')
    len++;
  temp-> str = malloc(len+1 * sizeof(char));
  // memory allocation fail
  if(temp->str == NULL)
  {
    free(temp);
    return;
  }
  for(int i=0; i<len; i++)
    temp-> str[i] = str[i];

  temp->str[len] = '\0';

  // setting id and next pointer
  temp->id = (list->root == NULL) ? 1 : (list->root->id + 1);
  temp->next = NULL;

  // finding last item and adding new one
  Item *last_item = list-> root;
  if(last_item == NULL)
    list->root = temp;
  
  else
  {
    while(last_item->next!=NULL)
      last_item = last_item->next;
    
    last_item->next = temp;
  }
}


/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  Item *temp = list->root;
  while(temp!=NULL)
  {
    // if node id matches the one given, we return the str attached to it
    if(temp->id == id)
      return temp->str;
    temp = temp->next;
  }
  // if not found return null
  return NULL;
}



/*Print the entire contents of the list. */
void print_history(List *list)
{
  // checking if list/ root are null
  if(list==NULL || list->root==NULL)
  {
    printf("There is no history\n");
    return;
  }

  Item *temp = list->root;
  while(temp != NULL)
  {
    printf("ID[:%d]: %s\n", temp->id, temp->str);
    temp = temp->next;
  }
}


/*Free the history list and the strings it references. */
void free_history(List *list)
{
  Item *curr = list->root;

  while(curr!=NULL)
  {
    Item *temp = curr;
    curr = curr->next;
    free(temp->str);
    free(temp);
  }
  free(list);
}


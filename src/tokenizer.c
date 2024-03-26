int space_char(char c)
{
  if (c == '\t' || c == ' ')
    {
      return 1;
    }
  return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */
int non_space_char(char c)
{
  if (space_char(c))
    {
      return 0;
    }
  return 1;
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str)
{
  while(*str != '\0' && space_char(*str))
    {
      str++;
    }
  if(*str == '\0')
    {
      return 0;
    }
 return str;
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token)
{
  while (*token != '\0' && non_space_char(*token))
    {
      token++;
    }
  return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str)
{
  counter = 0;
  while(*token_start(*str) != 0)
    {
      str = *token_terminator(*str);
      counter++;
    }
  return counter;
}

/* Returns a freshly allocated new zero-terminated string 

   containing <len> chars from <inStr> */

char *copy_str(char *inStr, short len)
{
  char *copied = (char *)malloc((len + 1) * sizeof(char));

  if(copied == NULL)
  {
    return NULL;
  }

  strncpy(copied, inStr, len);
  copied[len] = '\0';

  return copied;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 

   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str)
{
  char *token = str;
  char **tokens = malloc(sizeof(char *) * (token_count+1));
  
  for(int i=0; i<token_count; i++)
  {
    token = token_start(token);
    char* token_end = token_terminator(token);
    int length = token_end - token;
    tokens[i] = copy_str(token, length);
    token = token_terminator(token);
  }

  tokens[token_count] = "\0";
  return tokens;
}

void print_tokens(char **tokens)
{
  int i=0;

  while(tokens[i] != NULL)
  {
    printf("TOKEN[%d]: %s\n", i, tokens[i]);
    i++;
  }
  printf("\n");
}

void free_tokens(char **tokens)
{
  int i=0;
  while(tokens[i])
  {
    free(tokens[i]);
    i++;
  }
}

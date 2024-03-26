#include <stdio.h>

int main(void)
{
  int c = 0;
  char ch;
  char str [100];
  printf("hello, please type something here:\n> ");
  while((ch = getchar()) != '\n')
    str[c++] = ch;
  puts(str);
  return 0;
}

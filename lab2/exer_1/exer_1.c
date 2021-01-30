/* Exercise 1: Command line arguments */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  printf("Number of arguments: %d\n", argc - 1);
  printf("File name: %s\n", argv[0] + 2);

  if (argc > 1)
  {
    for (int i = 1; i < argc; i++)
    {
      if (isnumber(argv[i]))
      {
        printf("Argument %d: %d\n", i, atoi(argv[i]));
      }
      else
      {
        printf("Argument %d: %s\n", i, argv[i]);
      }
    }
  }

  return 0;
}

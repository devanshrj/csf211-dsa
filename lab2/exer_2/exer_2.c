/* Exercise 2: File operations */

#include <stdio.h>
#include <stdlib.h>

#define max 256

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Inadequate arguments!\n");
    exit(1);
  }

  printf("Input file: %s\n", argv[1]);
  printf("Output file: %s\n", argv[2]);

  FILE *fin, *fout;

  printf("Opening files...\n");
  fin = fopen(argv[1], "r");
  fout = fopen(argv[2], "w");
  printf("Files opened successfully.\n");

  /* file not found  */
  if (fin == NULL || fout == NULL)
  {
    printf("Error! File not found.\n");
    exit(1);
  }

  printf("Content copying...\n");
  char s[max];
  while (fgets(s, max, fin))
  {
    fprintf(fout, "%s", s);
  }
  printf("Content copied successfully.\n");

  return 0;
}

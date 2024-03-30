#include <stdio.h>
#include <string.h>

#define MAX 1000
#define TRUE 1
#define FALSE 0

void printFile(char *argv[], int argc, int index, int numbers)
{
  char character;
  int count = 0;

  for (int i = index; i < argc; i++)
  {
    FILE *file = fopen(argv[i], "r");

    if (numbers)
      printf("\t%d ", ++count);
    while ((character = fgetc(file)) != EOF)
    {
      printf("%c", character);
      if (numbers && character == '\n')
        printf("\t%d ", ++count);
    }

    fclose(file);
  }
}

int main(int argc, char *argv[])
{
  char input[MAX];

  if (argc > 1)
  {
    if (strcmp(argv[1], "-n") == 0)
    {
      printFile(argv, argc, 2, TRUE);
    }
    else
    {
      printFile(argv, argc, 1, FALSE);
    }
  }
  else
  {
    while (1)
    {
      scanf("%s", input);
      printf("%s\n", input);
    }
  }

  return 0;
}
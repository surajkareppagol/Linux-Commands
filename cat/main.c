#include <stdio.h>

int main(int argc, char *argv[])
{
  char character;

  if (argc > 1)
  {
    for (int i = 1; i < argc; i++)
    {
      FILE *file = fopen(argv[i], "r");

      while ((character = fgetc(file)) != EOF)
        printf("%c", character);

      fclose(file);
    }
  }

  return 0;
}
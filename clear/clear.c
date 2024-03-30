#include <stdio.h>

/* Version 1
#include <sys/ioctl.h>
#include <unistd.h>
*/

int main()
{
  // Get Terminal Size

  /* Version 1
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  printf("%d %d\n", w.ws_row, w.ws_col);

  for (int i = 0; i < w.ws_row + 40; i++)
    printf("\n");
  */

  /* Version 2
    printf("\033[0;0H");
  */

  printf("\033c");

  return 0;
}
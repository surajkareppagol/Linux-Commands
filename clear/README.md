# clear

`clear` - clear the terminal screen

```sh
clear
```

This is the program for `clear` command written in C.

`Version 1`, print `\n` for terminal rows + 40 times.

```c
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main()
{
  // Get Terminal Size

  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  // printf("%d %d\n", w.ws_row, w.ws_col);

  for (int i = 0; i < w.ws_row + 40; i++)
    printf("\n");

  return 0;
}
```

`Version 2`, Move cursor to the top left of the terminal with `<esc>[m;nH`.

```c
#include <stdio.h>

int main()
{
  printf("\033[0;0H");

  return 0;
}
```

`Version 3`, Clear the terminal screen with escape sequence `<esc>c`.

```c
#include <stdio.h>

int main()
{
  printf("\033c");

  return 0;
}
```

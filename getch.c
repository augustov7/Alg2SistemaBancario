/* FONTE:
    https://opensourceforu.com/2014/03/write-conio-h-gnulinux/
*/

#include <stdio.h>
#include <stdlib.h>

char getch()
{

  char c;
  c = getchar();
  return c;

}
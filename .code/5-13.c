#include<stdio.h>
#include<dos.h>
main()
{
  printf("\n The status of Ctrl-Break %s",(getcbrk())?"on":"off");
  setcbrk(1);
  printf("\n The status of Ctrl-Break %s",(getcbrk())?"on":"off");
  getch();
}

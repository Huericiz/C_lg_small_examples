#include<stdio.h>
#include<alloc.h>
main(void)
{
  printf("\nthe start address available for use:%x",coreleft());
  sbrk(0x80);
  printf("\nAfter modify,the start address available for use:%x",coreleft());
  getch();
}

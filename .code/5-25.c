#include<stdio.h>
#include<dos.h>
main()
{
  int value=0;
  printf("\nThe current status of your keyboard is:");
  value=peekb(0x0040,0x0017);
  if(value&1)printf("\nRight shift on");
  if(value&2)printf("\nLeft shift on");
  if(value&4)printf("\nControl key on");
  if(value&8)printf("\nAlt key on");
  if(value&16)printf("\nScroll lock key on");
  if(value&32)printf("\nNum lock key on");
  if(value&64)printf("\nCaps lock key on");
  if(value&128)printf("\nIns key on");
  getch();
}

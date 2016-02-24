#include<stdio.h>
#include<dos.h>
main()
{
  int value=0;
  value=peekb(0x0040,0x0017);
  if(value&64){printf("\nCaps lock key on");}
  else
  {
    printf("\nCaps lock key off");
    pokeb(0x0040,0x0017,64);
    printf("\nAfter setting, ");
    value=peekb(0x0040,0x0017);
    if(value&64){printf("Caps lock key on");}
  }
  getch();
}

#include<stdio.h>
#include<dos.h>
main()
{
  bdos(0x09,(unsigned)"Hello,World!$",0);
  getch();
}

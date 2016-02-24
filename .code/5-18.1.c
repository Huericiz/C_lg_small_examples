#include<stdio.h>
#include<dos.h>
#define VIDEO 0x10
main()
{
  int x=25,y=10;
  union REGS regs;
  clrscr();
  regs.h.ah=2;
  regs.h.dh=y;
  regs.h.dl=x;
  regs.h.bh=0;
  int86(VIDEO,&regs,&regs);
  printf("Hello");
  getch();
}

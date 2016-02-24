#include"conio.h"
main()
{
  void*buf;
  clrscr();
  gotoxy(35,15);
  textcolor(YELLOW);
  textbackground(BLUE);
  cprintf("hello world\n");
  cprintf("hello computer\n");
  buf=(char*)malloc(2*11*2);
  gettext(35,15,60,16,buf);
  puttext(20,5,45,6,buf);
  gotoxy(30,10);
  textattr(RED|128|GREEN*16);
  cprintf("Morning!");
  getch();
}

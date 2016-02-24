#include"bios.h"
#include"stdio.h"
#include"conio.h"
#define UP    0x4800
#define DOWN  0x5000
#define LEFT  0x4b00
#define RIGHT 0x4d00
#define SPACE 0x3920
#define ENTER 0x1c0d
#define ESC 0x011b
main()
{
  struct point
  {
     int x,y;
  }a;
  int key,key1;
  a.x=1;
  a.y=10;
  clrscr();
  gotoxy(a.x,a.y);
  printf("%c",6);
  while(bioskey(1)==0)
  {
    key=bioskey(0);
    switch(key)
    {
      case UP:
      {
         a.y-=1;
         if(a.y==0)
         a.y=24;
         gotoxy(a.x,a.y);
         printf("%c",6);
         break;
      }
      case DOWN:
      {
         a.y+=1;
         if(a.y==24)
         a.y=1;
         gotoxy(a.x,a.y);
         printf("%c",6);
         break;
      }
      case LEFT:
      {
         a.x-=1;
         if(a.x==0)
         a.x=80;
         gotoxy(a.x,a.y);
         printf("%c",6);
         break;
      }
      case RIGHT:
      {
         a.x+=1;
         if(a.x==80)
         a.x=1;
         gotoxy(a.x,a.y);
         printf("%c",6);
         break;
      }
      case ENTER:
      {
         a.y+=1;
         if(a.y==24)
         a.y=1;
         gotoxy(a.x,a.y);
         printf("%c",6);
         break;
      }
      case SPACE:
      {
        while(bioskey(1)==0)
        {
          key1=bioskey(0);
          switch(key1)
          {
           case UP:
          {
            a.y-=1;
            if(a.y==0)
            a.y=24;
            gotoxy(a.x,a.y);
            putch(' ');
            break;
           }
            case DOWN:
      {
         a.y+=1;
         if(a.y==24)
         a.y=1;
         gotoxy(a.x,a.y);
         putch(' ');
         break;
      }
      case LEFT:
      {
         a.x-=1;
         if(a.x==0)
         a.x=80;
         gotoxy(a.x,a.y);
         putch(' ');
         break;
      }
      case RIGHT:
      {
         a.x+=1;
         if(a.x==80)
         a.x=1;
         gotoxy(a.x,a.y);
         putch(' ');
         break;
      }
      case ENTER:
      {
         a.y+=1;
         if(a.y==24)
         a.y=1;
         gotoxy(a.x,a.y);
         putch(' ');
         break;
      }
          }
          if(key1==SPACE)
          break;
        }
      }
    }
    if(key==ESC)
    break;
  }
}

#include"stdio.h"
#include"dos.h"
#include"conio.h"
void goto_xy(int x,int y);
void dell(int x1,int x2,int y1,int y2);
void delr(int x1,int x2,int y1,int y2);
void mid(int x1,int x2,int y1,int y2);
void bias(int x1,int x2,int y1,int y2);
void tri(int x1,int x2,int y1,int y2);
void puta(void);
void goto_xy(int x,int y)
{
  union REGS r;
  r.h.ah=2;
  r.h.dl=y;
  r.h.dh=x;
  r.h.bh=0;
  int86(0x10,&r,&r);
}
void puta(void)
{
  int i,j;
  for(i=0;i<24;i++)
  {
    for(j=0;j<80;j++)
    {
      goto_xy(i,j);
      printf("%c",1);
    }
  }
}
void dell(int x1,int x2,int y1,int y2)
{
  int i,j;
  for(j=y1;j<=y2;j++)
   if(j%2==0)
     for(i=x1;i<=x2;i++)
     {
       goto_xy(i,j);
       putchar('');
       delay(10);
     }
}
void delr(int x1,int x2,int y1,int y2)
{
  int i,j;
  for(j=x1;j<=x2;j++)
  {
    if(j%2==0)
    for(i=y1;i<=y2;i++)
    {
      goto_xy(j,i);
      putchar('');
      delay(10);
    }
  }
}
void mid(int x1,int x2,int y1,int y2)
{
   int t,s,t1,s1,i,j;
   for(t=y1,s=y2;t<(y1+y2)/2;t++,s--)
   for(j=x1;j<=x2;j++)
   {
     goto_xy(j,t);
     putchar('');
     goto_xy(j,s);
     putchar('');
     delay(10);
   }
}
void bias(int x1,int x2,int y1,int y2)
{
   int i,j;
   for(i=x1;i<=x2;i++)
   if(i%2==0)
   {
     for(j=y1;j<=y2;j++)
     if(j%2!=0)
     {
      goto_xy(i,j);
      putchar('');
     }
   }
   else
     for(j=y1;j<=y2;j++)
     if(j%2==0)
     {
       goto_xy(i,j);
       putchar('');
     }
}
void tri(int x1,int x2,int y1,int y2)
{
  int i,j,k;
  for(i=x1;i<=x2;i++)
  for(j=y1,k=y2+1;j<=(y1+y2)/2-i;j++,k--)
  {
    goto_xy(i,j);
    putchar('');
    goto_xy(i,k);
    putchar('');
  }
}
main()
{
  puta();
  getch();
  dell(0,23,0,79);
  getch();
  puta();
  delr(0,23,0,79);
  getch();
  puta();
  getch();
  mid(0,23,0,79);
  getch();
  puta();
  getch();
  bias(0,23,0,79);
  getch();
  puta();
  getch();
  tri(0,23,0,79);
  getch();
}

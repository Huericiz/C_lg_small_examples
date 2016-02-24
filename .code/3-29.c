#include<stdio.h>
#include<graphics.h>
#include<math.h>
main()
{
  int gd=DETECT,gm;
  int i;
  unsigned long t;
  double alfa=0;
  double x,y;
  int time;
  detectgraph(&gd,&gm);
  initgraph(&gd,&gm,"");
  setbkcolor(BLACK);
  setcolor(WHITE);
  x=0;
  y=0;
  moveto(x*40+20,y*100+300);
  for(x=0;x<15;x=x+0.1)
  {
    y=sin(x+alfa);
    lineto(x*40+20,y*100+300);
  }
  getch();
  closegraph();
}

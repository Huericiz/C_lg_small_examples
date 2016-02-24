#include"graphics.h"
#include"math.h"
#include"dos.h"
#define pi 3.1415926
void draw(int a,int b,int c)
{
   float x,y;
   x=a*cos(b*c*pi/180-pi/2)+300;
   y=a*sin(b*c*pi/180-pi/2)-240;
   setlinestyle(0,0,3);
   line(300,240,x,y);
}
void init()
{
   int i,r,x1,y1,x2,y2,n=3;
   setbkcolor(GREEN);
   setfillstyle(1,RED);
   circle(300,240,200);
   circle(300,240,205);
   floodfill(300,37,GREEN);
   circle(300,240,5);
   for(i=0;i<60;i++)
   {
     if(i%5==0)
     {
       setcolor(WHITE);
       setfillstyle(1,GREEN);
       r=10;
       x2=(200-r)*cos(i*6*pi/180)+300;
       y2=(200-r)*sin(i*6*pi/180)+240;
       pieslice(x2,y2,0,360,8);
     }
     else
     {
       r=5;
       x1=200*cos(i*6*pi/180)+300;
       y1=200*sin(i*6*pi/180)+240;
       x2=(200-r)*cos(i*6*pi/180)+300;
       y2=(200-r)*sin(i*6*pi/180)+240;
       setcolor(WHITE);
       line(x1,y1,x2,y2);
     }
   }
}
main()
{
  int x,y;
  int gdriver=DETECT,gmode;
  unsigned char h,m,s;
  struct time t[1];
  initgraph(&gdriver,&gmode,"");
  init();
  setwritemode(1);
  gettime(t);
  h=t[0].ti_hour;
  m=t[0].ti_min;
  s=t[0].ti_sec;
  setcolor(7);
  draw(150,h,30);
  setcolor(14);
  draw(170,m,6);
  setcolor(4);
  draw(190,s,6);
  while(!kbhit())
  {
    while(t[0].ti_sec==s)
    gettime(t);
    setcolor(4);
    draw(190,s,6);
    s=t[0].ti_sec;
    draw(190,s,6);
    if(t[0].ti_min!=m)
    {
      setcolor(14);
      draw(170,m,6);
      m=t[0].ti_min;
      draw(170,m,6);
    }
    if(t[0].ti_hour!=h)
    {
      setcolor(7);
      draw(150,h,30);
      h=t[0].ti_hour;
      draw(150,h,30);
    }
  }
  getch();
  closegraph();
}

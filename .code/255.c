#include"graphics.h"
#include"math.h"
#define pi 3.1415926
void draw(int x,int y,int r)
{
   int x1,y1,x2,y2,x3,y3,color=1;
   float i;
   for(i=0;i<=2*pi;i+=pi/20)
   {
      setcolor(color);
      x1=x+r*cos(i);
      y1=y-r*sin(i);
      x2=x-3*r+r*cos(-i);
      y2=y-3*r-r*sin(-i);
      x3=x+3*r+r*cos(-i);
      y3=y+3*r-r*sin(-i);
      circle(x1,y1,r);
      circle(x2,y2,r);
      circle(x3,y3,r);
      delay(1e20);
      color++;
      if(color>15)
        color=1;
   }
}
main()
{
  int gdriver=DETECT,gmode;
  initgraph(&gdriver,&gmode,"");
  cleardevice();
  draw(320,240,25);
  getch();
  closegraph();
}

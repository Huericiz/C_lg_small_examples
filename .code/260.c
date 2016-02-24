#include"math.h"
#include"graphics.h"
#include"conio.h"
#define pi 3.1415926
void squ()
{
   int i,j,x[6],y[6];
   float m,n;
   setcolor(14);
   for(m=0;m<=pi/2;m+=pi/8)
   {
      for(i=1,n=m;n<=5*pi/2+m;i++,n+=pi/2)
      {
        x[i]=320+200*sin(n);
        y[i]=240-200*cos(n);
      }
      for(i=1;i<=4;i++)
       line(x[i],y[i],x[i+1],y[i+1]);
   }
}
void multicolor()
{
   int i,j,color=1;
   float n,x,y;
   for(n=pi/2;n<=3*pi/2;n+=pi/60)
   {
     setcolor(color);
     x=320+140*sin(n);
     y=240-140*cos(n);
     line(x,y,x,480-y);
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
  squ();
  delay(1e10);
  multicolor();
  getch();
  closegraph();
}

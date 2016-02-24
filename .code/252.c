#include"graphics.h"
#include"stdlib.h"
#include"math.h"
#define PI 3.1415926
#define R1 150
void Pentacle(double m)
{
  int x1,y1,x2,y2;
  double n;
  setcolor(RED);
  for(n=m;n<=2*PI+m;n+=2*PI/5)
  {
     x1=320+R1*cos(n);
     y1=240-R1*sin(n);
     x2=320+R1*0.382*cos(n+PI/5);
     y2=240-R1*0.382*sin(n+PI/5);
     line(x1,y1,x2,y2);
     x1=320+R1*cos(n+2*PI/5);
     y1=240-R1*sin(n+2*PI/5);
     line(x2,y2,x1,y1);
  }
  setfillstyle(1,RED);
  floodfill(320,240,RED);
}
void light()
{
  int i,j,x,y,r2=160;
  setcolor(YELLOW);
  for(i=0;i<=16;i++)
  {
    for(j=0;j<=60;j++)
      ellipse(320,240,j*6,j*6+1,r2+10*i,r2+5*i);
  }
}
void Delay(int Second)
{
   long T1,T2;
   T1=time();
   while(1)
   {
     delay(50);
     T2=time();
     if(T2-T1>Second)
       break;
   }
}
main()
{
  int gdriver=DETECT,gmode;
  double m=0.0;
  initgraph(&gdriver,&gmode,"");
  while(!kbhit())
  {
    Pentacle(m);
    light();
    Delay(0.5);
    cleardevice();
    m+=PI/6;
  }
  getch();
  closegraph();
}

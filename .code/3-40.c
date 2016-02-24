#include<graphics.h>
#include<math.h>
#include<conio.h>
#define  PI 3.1415926535
main()
{
  int gd=DETECT,gm;
  double a=0,b;
  int x0=300,y0=250,radius=120,i,x,y;
  initgraph(&gd,&gm,"");
  cleardevice();
  setbkcolor(WHITE);
  setcolor(BLUE);
  for(i=0;i<6;i++,a+=60)
  {
    b=a*PI/180;
    x=x0+radius*cos(b);
    y=y0+radius*sin(b);
    arc(x,y,120-i*60,240-i*60,radius);
  }
  getch();
  closegraph();
}

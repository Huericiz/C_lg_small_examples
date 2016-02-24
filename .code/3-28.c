#include<graphics.h>
#include<math.h>
void ellipsel(x0,y0,a,b,dt)
int x0,y0,a,b,dt;
{
  int x,y,n,i;
  float t1,t=0.0;
  t1=dt*0.0174533;
  n=360/dt;
  moveto(x0+a,y0);
  for(i=1;i<n;i++)
  {
    t=t+t1;
    x=x0+a*cos(t);
    y=y0+b*sin(t);
    lineto(x,y);
  }
  lineto(x0+a,y0);
}
void main()
{
  int a=150,b=100,x=320,y=240;
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"");
  cleardevice();
  setbkcolor(WHITE);
  setcolor(BLUE);
  setlinestyle(0,0,3);
  ellipsel(x,y,a,b,10);
  getch();
  closegraph();
}

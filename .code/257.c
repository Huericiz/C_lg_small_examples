#include"graphics.h"
#include"math.h"
#include"conio.h"
#define PI 3.1415926
main()
{
  int x,y,r=70,r1;
  double a;
  int gdriver=DETECT,gmode;
  initgraph(&gdriver,&gmode,"");
  cleardevice();
  setbkcolor(WHITE);
  setcolor(RED);
  for(a=0;a<2*PI;a+=PI/30)
  {
    x=320+r*cos(a);
    y=240-r*sin(a);
    r1=sqrt((x-320)*(x-320)+(y-240+r)*(y-240+r));
    circle(x,y,r1);
  }
  getch();
  closegraph();
}

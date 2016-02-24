#include<math.h>
#include<graphics.h>
#define D 100
#define PI 3.14159
main()
{
   float a,e,x1,y1,x2,y2;
   int gdriver=DETECT,gmode;
   initgraph(&gdriver,&gmode,"");
   cleardevice();
   setcolor(GREEN);
   setbkcolor(0);
   for(a=0.0;a<2*PI;a+=2*PI/720)
   {
      e=D*(1+sin(4*a));
      x1=320+e*cos(a);
      x2=320+e*cos(a+PI/5);
      y1=240+e*sin(a);
      y2=240+e*sin(a+PI/5);
      line(x1,y1,x2,y2);
   }
   getch();
   closegraph();
}

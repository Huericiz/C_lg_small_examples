#include"conio.h"
#include"graphics.h"
#include"math.h"
main()
{
   int y=200;
   int i,h;
   float m;
   int gdriver=DETECT,gmode;
   initgraph(&gdriver,&gmode,"");
   setviewport(50,50,450,450,1);
   setcolor(14);
   rectangle(0,0,400,400);
   line(200,0,200,400);
   line(0,200,400,200);
   for(i=0;i<400;i++)
   {
     m=100*sin(i/31.83);
     h=y-(int)m;
     putpixel(i,h,15);
     delay(10000);
   }
   getch();
   closegraph();
}


#include"conio.h"
#include"graphics.h"
int main()
{
   int gdriver=DETECT,gmode;
   int point[16]=
   {
       200,100,300,100,300,110,330,95,300,80,300,90,200,90,200,100
   };
   initgraph(&gdriver,&gmode,"");
   setbkcolor(BLUE);
   cleardevice();
   setcolor(WHITE);
   drawpoly(8,point);
   getch();
   closegraph();
   return 0;
}

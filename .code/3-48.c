#include<graphics.h>
#include<math.h>
#define PI 3.1415926
void main()
{
   double a;
   int x,y,r,r1;
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"");
   printf("Please input Radus(<150):");
   scanf("%d",&r);
   cleardevice();
   setbkcolor(MAGENTA);
   setcolor(WHITE);
   outtextxy(80,20,"This program show the Kidney picture.");
   for(a=0;a<=2*PI;a+=PI/27)
   {
     x=320+r*cos(a);
     y=240+r*sin(a);
     r1=abs(x-320);
     circle(x,y,r1);
   }
   outtextxy(80,640,"Press any key to quit...");
   getch();
   closegraph();
}

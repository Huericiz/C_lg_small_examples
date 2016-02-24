#include<graphics.h>
void main()
{
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"");
   cleardevice();
   printf("\n\n\n To draw a ellipse.\n");
   ellipse(300,250,0,360,150,100);
   getch();
   cleardevice();
   printf("\n\n\n To draw a fill ellipse.\n");
   fillellipse(300,250,150,100);
   getch();
   closegraph();
}

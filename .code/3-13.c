#include<graphics.h>
void main()
{
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"");
   cleardevice();
   printf("\n To draw lines with function 'line'.");
   line(160,120,300,250);
   line(300,360,480,250);
   getch();
   cleardevice();
   printf("\n To draw lines with function 'lineto'.");
   moveto(160,120);
   lineto(300,360);
   lineto(480,250);
   getch();
   cleardevice();
   printf("\n To draw lines with function 'linerel'.");
   moveto(160,120);
   linerel(140,240);
   linerel(180,-110);
   getch();
   closegraph();
}

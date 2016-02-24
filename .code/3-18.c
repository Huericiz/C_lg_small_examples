#include<graphics.h>
void main()
{
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"");
   cleardevice();
   printf("\n\n\n To draw a arc.\n");
   arc(300,250,100,240,120);
   getch();
}

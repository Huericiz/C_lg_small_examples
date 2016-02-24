#include<graphics.h>
void main()
{
   int i,j;
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"");
   cleardevice();
   printf("\n\n\n TO use the putpixel function.\n");
   for(i=300;i<350;i++)
   {
      for(j=200;j<250;j++)
         putpixel(i,j,RED);
   }
   getch();
   closegraph();
}

#include"conio.h"
#include<graphics.h>
main()
{
   int gdriver=DETECT,gmode,i,j;
   initgraph(&gdriver,&gmode,"");
   cleardevice;
   for(i=120;i<=400;i=i+40)
   for(j=120;j<=400;j++)
   {
       putpixel(i,j,YELLOW);
       putpixel(j,i,YELLOW);
   }
   getch();
   closegraph();
}

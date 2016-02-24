#include"conio.h"
#include"graphics.h"
main()
{
   int gdriver=DETECT,gmode;
   initgraph(&gdriver,&gmode,"");
   setbkcolor(WHITE);
   setcolor(RED);
   circle(getmaxx()/2,getmaxy()/2,100);
   getch();
   closegraph();
}

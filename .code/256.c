#include"graphics.h"
#include"conio.h"
#include"stdio.h"
main()
{
    int gdriver=DETECT,gmode;
    int x;
    int color=1;
    initgraph(&gdriver,&gmode,"");
    cleardevice();
    setbkcolor(15);
    setlinestyle(0,0,1);
    for(x=0;x<=640;x+=10)
    {
       setcolor(color);
       line(x,1,640-x,480);
       delay(1e20);
       color++;
       if(color==15)
         color=1;
    }
    for(x=640;x>=0;x-=10)
    {
       setcolor(15);
       line(640-x,480,x,1);
       delay(1e20);

    }
    getch();
    closegraph();
}

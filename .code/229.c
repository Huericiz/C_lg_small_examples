#include<stdio.h>
#include<conio.h>
#include<graphics.h>
main()
{
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"");
    ellipse(200,200,0,360,50,100);
    getch();
    closegraph();
}

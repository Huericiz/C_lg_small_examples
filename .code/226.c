#include"stdio.h"
#include"conio.h"
#include"graphics.h"
main()
{
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"");
line(100,300,300,300);
line(320,50,320,300);
lineto(200,200);
getch();
closegraph();
}

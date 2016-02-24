#include"conio.h"
#include"graphics.h"
main()
{
  int gdriver=DETECT,gmode;
  initgraph(&gdriver,gmode,"");
  setcolor(RED);
  ellipse(320,240,0,360,160,80);
  setfillstyle(7,14);
  floodfill(320,240,RED);
  getch();
  closegraph();
}

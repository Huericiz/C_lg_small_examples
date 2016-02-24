#include"conio.h"
#include"graphics.h"
main()
{
  int gdriver=DETECT,gmode;
  initgraph(&gdriver,&gmode,"");
  setcolor(RED);
  setlinestyle(DASHED_LINE,0,3);
  rectangle(100,100,550,350);
  getch();
  closegraph();
}

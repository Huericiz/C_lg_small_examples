#include"conio.h"
#include"graphics.h"
main()
{
  int gdriver=DETECT,gmode;
  initgraph(&gdriver,&gmode,"");
  setbkcolor(GREEN);
  setcolor(RED);
  arc(getmaxx()/2,getmaxy()/2,0,120,100);
  getch();
  closegraph();
}

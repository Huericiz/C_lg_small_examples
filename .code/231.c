#include"conio.h"
#include"graphics.h"
main()
{
  int gdriver=DETECT,gmode;
  initgraph(&gdriver,&gmode,"");
  pieslice(260,200,0,120,100);
  getch();
  closegraph();
}

#include"graphics.h"
main()
{
  int i,j;
  int gdriver=DETECT,gmode;
  initgraph(&gdriver,&gmode,"");
  for(i=0;i<=200;i++)
  {
     setcolor(i%16);
     setlinestyle(0,0,1);
     setfillstyle(1,3);
     circle(300,240,200-i);
     floodfill(300,240,i%16);
     delay(1e20);
  }
  for(j=0;j<=200;j++)
  {
    setcolor(j%16);
    setlinestyle(0,0,1);
    setfillstyle(5,14);
    circle(300,240,j);
    floodfill(300,240,j%16);
    delay(1e20);
  }
  getch();
  closegraph();


}

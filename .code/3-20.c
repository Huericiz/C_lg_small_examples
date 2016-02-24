#include<graphics.h>
void main()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"");
  setfillstyle(SOLID_FILL,GREEN);
  bar(60,80,220,160);
  setfillstyle(SOLID_FILL,RED);
  bar3d(260,180,360,240,20,1);
  getch();
  restorecrtmode();
}

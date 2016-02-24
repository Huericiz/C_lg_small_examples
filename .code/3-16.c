#include<graphics.h>
void main()
{
  int b;
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"");
  cleardevice();
  printf("\n\n\n To draw a circle.\n");
  circle(300,250,120);
  getch();
  closegraph();
}

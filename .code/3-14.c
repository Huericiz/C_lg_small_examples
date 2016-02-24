#include<graphics.h>
void main()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"");
  cleardevice();
  printf("\n\n\n To draw a rectangle.\n");
  rectangle(30,80,500,400);
  getch();
  closegraph();
}


#include<graphics.h>
void main()
{
  int i,j;
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"");
  cleardevice();
  setbkcolor(15);
  for(i=0;i<4;i++)
  {
    setcolor(i+1);
    setlinestyle(i,0,1);
    line(50,50+i*50+200,200,200+i*50+200);
    circle(100+i*150,150,60);
  }
  for(j=0;j<4;j++)
  {
    setcolor(j+5);
    setlinestyle(j,0,3);
    line(100,50+j*50,300,200+j*50);
    circle(100+j*150,300,60);
  }
  getch();
  closegraph();
}

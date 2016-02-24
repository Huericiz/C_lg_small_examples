#include<stdio.h>
#include<graphics.h>
#include<dos.h>
void circlePoint(int xCenter,int yCenter,int x,int y)
{
  putpixel(xCenter+x,yCenter+y,BLUE);
  putpixel(xCenter-x,yCenter+y,BLUE);
  putpixel(xCenter+x,yCenter-y,BLUE);
  putpixel(xCenter-x,yCenter-y,BLUE);
  putpixel(xCenter+y,yCenter+x,BLUE);
  putpixel(xCenter-y,yCenter+x,BLUE);
  putpixel(xCenter+y,yCenter-x,BLUE);
  putpixel(xCenter-y,yCenter-x,BLUE);
}
void drawCircle(int xCenter,int yCenter,int radius)
{
  int x,y,p;
  x=0;
  y=radius;
  p=1-radius;
  circlePoint(xCenter,yCenter,x,y);
  while(x<y)
  {
    x++;
    if(p<0)
      p+=2*x+1;
    else
    {
      y--;
      p+=2*(x-y)+1;
    }
    circlePoint(xCenter,yCenter,x,y);
  }
}
void main()
{
  int gd=DETECT,gm;
  int xCenter=300,yCenter=250,radius=120;
  initgraph(&gd,&gm,"");
  cleardevice();
  setbkcolor(WHITE);
  printf("\n\n\n To draw circle.\n");
  setcolor(BLUE);
  drawCircle(xCenter,yCenter,radius);
  getch();
  closegraph();
  return;
}

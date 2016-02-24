#include<graphics.h>
#include<conio.h>
#include<stdio.h>
int main()
{
  int gd=DETECT,gm;
  int trama,color;
  int puntos[6]={300,50,500,300,100,300};
  initgraph(&gd,&gm,"");
  trama=SLASH_FILL;
  color=4;
  setfillstyle(trama,color);
  fillpoly(3,puntos);
  getch();
  closegraph();
  return 0;
}

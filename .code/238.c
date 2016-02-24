#include"conio.h"
#include"graphics.h"
#include"math.h"
main()
{
  int i,j=0,gdriver=DETECT,gmode,points[20];
  initgraph(&gdriver,&gmode,"");
  setcolor(YELLOW);
  setlinestyle(0,0,1);
  for(i=0;i<5;i++)
  {
     points[j++]=(int)(320+150*cos(0.4*3.1415926*i));
     points[j++]=(int)(240-150*sin(0.4*3.1415926*i));
     points[j++]=(int)(320+50*cos(0.4*3.1415926*i+0.6283));
     points[j++]=(int)(240-50*sin(0.4*3.1415926*i+0.6283));
  }
  setfillstyle(1,RED);
  fillpoly(10,points);
  getch();
  closegraph();
}



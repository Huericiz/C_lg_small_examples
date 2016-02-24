#include"conio.h"
#include"graphics.h"
main()
{
  int gdriver=DETECT,gmode,n;
  int point[]=
  {
     200,200,150,250,150,300,200,350,250,350,300,300,300,250,250,200
  };
  initgraph(&gdriver,&gmode,"");
  setfillstyle(INTERLEAVE_FILL,RED);
  n=sizeof(point)/(2*sizeof(int));
  fillpoly(n,point);
  getch();
  closegraph();
}

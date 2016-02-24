#include"math.h"
#include"graphics.h"
main()
{
  int x0=320,y0=240;
  int n=25,i,j,r=180;
  int x[50],y[50];
  int gdriver=DETECT,gmode;
  initgraph(&gdriver,&gmode,"");
  cleardevice();
  setbkcolor(WHITE);
  setcolor(GREEN);
  for(i=0;i<n;i++)
  {
     x[i]=r*cos(2*3.14159265357*i/n)+x0;
     y[i]=r*sin(2*3.14159265357*i/n)+y0;
  }
  for(i=0;i<=n-2;i++)
   {
     for(j=i+1;j<n-1;j++)
     line(x[i],y[i],x[j],y[j]);
   }
   getch();
   closegraph();
}


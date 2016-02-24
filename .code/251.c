#include"graphics.h"
#include"dos.h"
#include"conio.h"
#include"stdlib.h"
#include"math.h"
#define PI 3.1415926
double a=10.0,b=0.0;
char ch;
void ball()
{
   int i,j;
   setcolor(RED);
   setfillstyle(1,15);
   circle(100,100,50);
   floodfill(100,100,RED);
   ellipse(100,100,90,270,20,50);
   ellipse(100,100,180,360,50,20);
   for(i=-18;i<18;i++)
     ellipse(100,100,5*i,5*i+1,20,50);
   for(j=0;j<36;j++)
      ellipse(100,100,5*j,5*j+1,50,20);
}
main()
{
  int gdrive=DETECT,gmode,k,t,size;
  void*buf;
  initgraph(&gdrive,&gmode,"");
  setcolor(GREEN);
  ball();
  size=imagesize(50,50,150,150);
  buf=malloc(size);
  getimage(50,50,150,150,buf);
  for(t=0;t<=50;t++)
  {
     cleardevice();
     putimage(a,b,buf,COPY_PUT);
     delay(1e15);
     b=200-150*sin(0.5*a);
     a+=10;
  }
  getch();
  closegraph();

}

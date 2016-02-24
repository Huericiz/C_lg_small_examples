#include"stdlib.h"
#include"conio.h"
#include"dos.h"
#include"graphics.h"
#define step 10
main()
{
  int gdriver=DETECT,gmode;
  static int startx=5;
  static int starty=100;
  int n;
  int size;
  initgraph(&gdriver,&gmode,"");
  setbkcolor(BLUE);
  while(!kbhit())
  {
    for(n=1;n<=40;n++)
    {
      cleardevice();
      setcolor(GREEN);
      setlinestyle(0,0,3);
      setfillstyle(1,YELLOW);
      rectangle(startx+n*step,starty,startx+n*step+160,starty+80);
      floodfill(startx+n*step+10,starty+20,GREEN);
      settextstyle(1,0,3);
      outtextxy(startx+20+n*startx,starty+20,"welcome!!");
      delay(1e10);
    }
  }
  closegraph();
}

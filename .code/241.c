#include"conio.h"
#include"graphics.h"
#include"time.h"
main()
{
  int i,gdriver=DETECT,gmode;
  time_t curtime;
  char s[30];
  time(&curtime);
  initgraph(&gdriver,&gmode,"");
  setbkcolor(BLUE);
  cleardevice();
  setviewport(100,100,580,380,1);
  setfillstyle(1,2);
  setcolor(15);
  rectangle(0,0,480,280);
  floodfill(50,50,15);
  setcolor(12);
  settextstyle(1,0,7);
  outtextxy(20,20,"Hello,China!");
  setcolor(15);
  settextstyle(3,0,6);
  outtextxy(120,85,"Hello,China!");
  setcolor(14);
  settextstyle(2,0,8);
  sprintf(s,"Now is %s",ctime(&curtime));
  outtextxy(20,150,s);
  setcolor(1);
  settextstyle(4,0,3);
  outtextxy(50,220,s);
  getch();
  exit(0);

}

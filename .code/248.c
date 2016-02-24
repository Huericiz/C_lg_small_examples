#include"graphics.h"
#include"conio.h"
#include"stdlib.h"
#define START_X 100
#define START_Y 400
void draw(int x,int y)
{
  setcolor(14);
  setfillstyle(1,15);
  rectangle(x,y,x+30,y+60);
  floodfill(x+10,y+10,14);
  setfillstyle(1,RED);
  line(x+15,y-15,x,y);

  line(x+15,y-15,x+30,y);
  floodfill(x+15,y-5,14);
  setfillstyle(2,RED);
  line(x-20,y+80,x,y+60);
  line(x+50,y+80,x+30,y+60);
  line(x-20,y+80,x+50,y+80);
  floodfill(x+10,y+70,14);
  line(x,y+90,x-10,y+100);
  setcolor(RED);
  line(x+10,y+90,x,y+100);
  line(x+20,y+90,x+30,y+100);
  setcolor(14);
  line(x+30,y+90,x+40,y+100);
}
void play()
{
   int x,y;
   int s=4;
   for(x=START_X,y=START_Y;y>=15;y-=s)
   {
     cleardevice();
     draw(x,y);
     delay(1e20);
   }
   outtextxy(200,100,"The demo is over!");
}
main()
{
  char ch;
  int x=START_X,y=START_Y;
  int gdriver=DETECT,gmode;
  initgraph(&gdriver,&gmode,"");
  setbkcolor(BLACK);
  cleardevice();
  setcolor(WHITE);
  settextstyle(TRIPLEX_FONT,0,2);
  outtextxy(200,100,"Press any key to begin!");
  getch();
  play();
  getch();
  closegraph();
}


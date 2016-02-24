#include<stdlib.h>
#include<graphics.h>
struct Snow
{
  int x;
  int y;
  int speed;
}snow[100];
int snownum=0;
int size;
int change=10;
void *save1,*save2;
void Copy();
void DrawSnow();
void Pr();
void main(void)
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"");
  Copy();
  DrawSnow();
  getch();
  closegraph();
}
void Copy()
{
  setcolor(0);
  setfillstyle(SOLID_FILL,15);
  fillellipse(200,200,4,4);
  size=imagesize(196,196,204,204);
  save1=malloc(size);
  save2=malloc(size);
  getimage(196,196,204,204,save1);
  getimage(96,96,104,104,save2);
}
void Pr()
{
  int s[15]={0,100,150,200,150,200,250,150,250,300,250,150,100,250,350};
  setcolor(change/10);
  settextstyle(0,0,4);
  outtextxy(100,200,"Merry Christmas");
  sound(s[change/10]);
}
void DrawSnow()
{
  int i;
  int sx[62];
  randomize();
  for(i=0;i<62;i++)
  sx[i]=(i+2)*10;
  cleardevice();
  while(!kbhit())
  {
    Pr();
    if(snownum!=100)
    {
      snow[snownum].speed=2+random(5);
      i=random(62);
      snow[snownum].x=sx[i];
      snow[snownum].y=10-random(100);
    }
    for(i=0;i<snownum;i++)
     putimage(snow[i].x,snow[i].y,save2,COPY_PUT);
     Pr();
     if(snownum!=100)
       snownum++;
     setfillstyle(SOLID_FILL,15);
     for(i=0;i<snownum;i++)
     {
       snow[i].y+=snow[i].speed;
       putimage(snow[i].x,snow[i].y,save1,COPY_PUT);
       if(snow[i].y>500)
         snow[i].y=10-random(200);
     }
     change++;
     if(change==140)
       change=10;
  }
  nosound();
}

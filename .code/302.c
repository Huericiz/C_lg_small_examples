#include <math.h>
#include <dos.h>
#include <graphics.h>
#define FLAG_X 10
#define FLAG_Y 50
#define FLAG_WID 300
#define FLAG_HI 180
#define WAVE_WID 100
#define WAVE_HI 5
#define BACKCOLOR CYAN
#define FLAGCOLOR RED
int Dy[WAVE_WID];
void InitDy(void)
{
float ang;
int i;
for (i=0;i<WAVE_WID;i++)
{
ang=(float)i/WAVE_WID*M_PI*2;
Dy[i]=WAVE_HI*sin(ang);
}
}
void DrawFlag(int offset)
{
int x,y,dy;
int i;
setbkcolor(BACKCOLOR);
cleardevice();
setcolor(FLAGCOLOR);
for (i=0;i<FLAG_WID;i++)
{
x=FLAG_X+i;
dy=Dy[(i+offset)%WAVE_WID];
y=FLAG_Y+dy;
line(x,y,x,y+FLAG_HI);
}
}
void main(void)
{
int gdriver=EGA,gmode=EGAHI;
int off,curpage,doff=5;
initgraph(&gdriver,&gmode,"");
InitDy();
off=0;
curpage=1;
while(1)
{
if (bioskey(1))
break;
if (curpage==0)
curpage=1;
else
curpage=0;
setactivepage(curpage);
DrawFlag(off);
setvisualpage(curpage);
off+=doff;
if (off>=WAVE_WID)
off-=WAVE_WID;
}
closegraph();
}


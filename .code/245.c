#include"dos.h"
#include"stdlib.h"
#include"graphics.h"
main()
{
   union REGS r;
   int gdriver=DETECT,gmode;
   int x,y,c,color;
   initgraph(&gdriver,&gmode,"");
   while(!kbhit())
   {
      r.x.ax=1;
      int86(0x33,&r,&r);
      r.x.ax=3;
      int86(0x33,&r,&r);
      x=r.x.cx;
      y=r.x.dx;
      c=r.x.bx;
      if(c==2)
      {
        color=rand()%16;
        setcolor(color);
      }
      if(c==1)
      {
        r.x.ax=2;
        int86(0x33,&r,&r);
        line(x,y,x+2,y+2);
      }
   }
}

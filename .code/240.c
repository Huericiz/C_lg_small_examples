#include"conio.h"
#include"graphics.h"
main()
{
   int i,start,end;
   int gdriver=DETECT,gmode;
   initgraph(&gdriver,&gmode,"");
   start=0;
   end=45;
   for(i=0;i<8;i++)
   {
      setfillstyle(SOLID_FILL,i);
      pieslice(getmaxx()/2,getmaxy()/2,start,end,200);
      start+=45;
      end+=45;
   }
   getch();
   closegraph();

}

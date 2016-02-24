#include"conio.h"
#include"graphics.h"
main()
{
   int color;
   int gdriver=DETECT,gmode;
   initgraph(&gdriver,&gmode,"");
   for(color=0;color<=14;color++)
   {
      setbkcolor(color);
      getch();
   }
   closegraph();
}

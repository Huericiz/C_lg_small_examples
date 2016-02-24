#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
int main(void)
{
   int gdriver=DETECT,gmode;
   initgraph(&gdriver,&gmode,"");
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
   moveto(0,getmaxy()/2);
   outtext("Norm");
   setusercharsize(1,3,1,1);
   outtext("Short");
   setusercharsize(3,1,1,1);
   outtext("Wide");
   getch();
   closegraph();
   return 0;
}

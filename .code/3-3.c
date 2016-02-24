#include<conio.h>
#include<graphics.h>
void main()
{
   int gdriver=DETECT,gmode;
   initgraph(&gdriver,&gmode,"");
   outtext("Normal");
   settextstyle(GOTHIC_FONT,HORIZ_DIR,2);
   outtext("Gothic");
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
   outtext("Triplex");
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
   outtext("Sans serif");
   getch();
   restorecrtmode();
}

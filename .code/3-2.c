#include<graphics.h>
void main()
{
   int gdriver=DETECT,gmode;
   initgraph(&gdriver,&gmode,"");
   outtext("say hello by function outtext!");
   outtextxy(200,150,"say helloc by function outtext!");
   getch();
   restorecrtmode();
}

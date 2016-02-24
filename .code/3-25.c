#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
main()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"");
  cleardevice();
  setbkcolor(15);
  printf("press any key to stop.");
  while(!kbhit())
    putpixel(rand()%640,rand()%440+40,rand()%15+1);
    getch();
    getch();
    closegraph();
}

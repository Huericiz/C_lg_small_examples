#include<stdio.h>
#include<graphics.h>
main()
{
  int i,j,gd=DETECT,gm;
  initgraph(&gd,&gm,"");
  setbkcolor(YELLOW);
  for(i=50;i<=230;i+=20)
    for(j=50;j<=230;j++)
      putpixel(i,j,1);
  for(j=50;j<=230;j+=20)
    for(i=50;i<=230;i++)
      putpixel(i,j,1);
   getch();
   closegraph();
}

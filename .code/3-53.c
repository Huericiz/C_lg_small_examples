#include<graphics.h>
#include<stdio.h>
void tria(xa,ya,xb,yb,xc,yc,n)
int xa,ya,xb,yb,xc,yc,n;
{
  int xp,yp,xq,yq,xr,yr;
  if(n>0)
  {
    xp=(xa+xb)/2;
    yp=(ya+yb)/2;
    xq=(xb+xc)/2;
    yq=(yb+yc)/2;
    xr=(xc+xa)/2;
    yr=(yc+ya)/2;
    moveto(xp,yp);
    lineto(xq,yq);
    lineto(xr,yr);
    lineto(xp,yp);
    tria(xa,ya,xp,yp,xr,yr,n-1);
    tria(xb,yb,xq,yq,xp,yp,n-1);
    tria(xc,yc,xr,yr,xq,yq,n-1);
  }
}
void main()
{
  int n,xa=10,ya=10,xb=10,yb=470,xc=630,yc=470;
  int gd=DETECT,gm;
  printf("Input recursion depth(for example,7):");
  scanf("%d",&n);
  initgraph(&gd,&gm,"");
  cleardevice();
  setbkcolor(WHITE);
  setcolor(BLUE);
  setcolor(2);
  moveto(xa,ya);
  lineto(xb,yb);
  lineto(xc,yc);
  lineto(xa,ya);
  tria(xa,ya,xb,yb,xc,yc,n);
  getch();
  closegraph();
}

#include<graphics.h>
int dx[12]={0,60,60,0,0,60,60,0,60,0,60,0};
int dy[12]={0,0,120,120,0,0,40,40,80,80,120,120};
int dz[12]={0,0,0,0,80,80,80,80,40,40,40,40};
int ld[24]={0,1,2,3,0,4,5,6,7,4,10,11,9,8,10,2,3,11,8,6,9,7,1,5};
int tl[24]={0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1};
int i,j,vh=100,vw=120,x,y,x0=250,y0=200;
main()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"");
  setbkcolor(BLUE);
  setcolor(YELLOW);
  front_view();
  top_view();
  left_view();
  perspective_view();
  getch();
  closegraph();
}
front_view()
{
  for(i=0;i<24;i++)
  {
    j=ld[i];
    x=x0-dx[j];
    y=y0-dz[j];
    if(tl[i]==0)
    moveto(x,y);
    lineto(x,y);
  }
}
top_view()
{
  for(i=0;i<24;i++)
  {
    j=ld[i];
    x=x0-dx[j];
    y=y0+dy[j]+vh;
    if(tl[i]==0)
    moveto(x,y);
    lineto(x,y);
  }
}
left_view()
{
  for(i=0;i<24;i++)
  {
    j=ld[i];
    x=x0+dy[j]+vw;
    y=y0-dz[j];
    if(tl[i]==0)
    moveto(x,y);
    lineto(x,y);
  }
}
perspective_view()
{
  for(i=0;i<24;i++)
  {
    j=ld[i];
    x=x0-0.7071*dx[j]+0.7071*dy[j]+150;
    y=y0+0.4082*dx[j]+0.4082*dy[j]-0.8165*dz[j]+150;
    if(tl[i]==0)
    moveto(x,y);
    lineto(x,y);
  }
}

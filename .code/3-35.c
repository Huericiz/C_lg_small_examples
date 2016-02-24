#include<graphics.h>
#include<math.h>
#include<conio.h>
#define PI 3.1415926
#define T PI/180
#define NN 36
#define DT PI/NN
#define DIST 0.8
#define R 190
static int n=1;
void trans(t,s)
float t[3];float s[3][3];
{
  s[0][0]=cos(t[1])*cos(t[2]);s[0][1]=cos(t[1])*sin(t[2]);
  s[0][2]=-sin(t[1]);
  s[1][0]=sin(t[0])*sin(t[1])*cos(t[2])-cos(t[0])*sin(t[2]);
  s[1][1]=sin(t[0])*sin(t[1])*sin(t[2])+cos(t[0])*cos(t[2]);
  s[1][2]=sin(t[0])*cos(t[1]);
  s[2][0]=cos(t[0])*sin(t[1])*cos(t[2])+sin(t[0])*sin(t[2]);
  s[2][1]=cos(t[0])*sin(t[1])*sin(t[2])-sin(t[0])*cos(t[2]);
  s[2][2]=cos(t[0])*cos(t[1]);
}
void draw(m,da,db)
float m[3][3],da,db;
{
  float f[3],f0,x0,y0,x1,y1,x2,y2;
  f[0]=R*sin(da)*cos(db);
  f[1]=R*sin(da)*sin(db);
  f[2]=R*cos(da);
  f0=f[0]*m[0][2]+f[1]*m[1][2]+f[2]*m[2][2];
  if(f0<=0)
    n=1;
  else
  {
    x0=300.0;y0=165.0;
    x2=(f0*m[0][0]+f[1]*m[1][0]+f[2]*m[2][0])+x0;
    y2=(f0*m[0][1]+f[1]*m[1][1]+f[2]*m[2][1])*DIST+y0;
    if(n==1)
    {
      n=2;
      x1=x2;
      y1=y2;
    }
    else
    {
      line(x1,y1,x2,y2);
      x1=x2;
      y1=y2;
    }
  }
}
main()
{
  float d[3],r[3][3];
  float ta,tb;
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"");
  cleardevice();
  setbkcolor(BLACK);
  setcolor(GREEN);
  d[1]=30*T;
  d[2]=-0.3;
  d[2]+=30*T;
  d[0]=60*T;
  trans(d,r);
  for(tb=0.0;tb<PI;tb+=DT)
      {
        n=1;
        for(ta=0.0;ta<2.1*PI;ta+=DT)
         draw(r,ta,tb);
      }
  for(ta=0.0;ta<PI;ta+=DT)
      {
        n=1;
        for(tb=0.0;tb<2.1*PI;tb+=DT)
         draw(r,ta,tb);
      }
      getch();
      closegraph();
}

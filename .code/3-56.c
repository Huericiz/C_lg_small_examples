#include<graphics.h>
typedef struct{float x,y;}complex;
complex complexSquare(complex c)
{
   complex csq;
   csq.x=c.x*c.x-c.y*c.y;
   csq.y=2*c.x*c.y;
   return csq;
}
int iterate(complex zInit,int maxIter)
{
   complex z=zInit;
   int cnt=0;
   while((z.x*z.x+z.y*z.y<=4.0)&&(cnt<maxIter))
   {
     z.x+=zInit.x;
     z.y+=zInit.y;
     cnt++;
   }
   return cnt;
}
void mandelbrot(int nx,int ny,int maxIter,float realMin,float realMax,float
   imagMin,float imagMax)
   {
     float realInc=(realMax-realMin)/nx;
     float imagInc=(imagMax-imagMin)/ny;
     complex z;
     int x,y;
     int cnt;
     for(x=0,z.x=realMin;x<nx;x++,z.x+=realInc)
     {
        for(y=0,z.y=imagMin;y<ny;y++,z.y+=imagInc)
        {
          cnt=iterate(z,maxIter);
          if(cnt==maxIter)
            putpixel(x,y,BLACK);
          else
            putpixel(x,y,cnt);
        }
     }
   }
void main()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"");
  mandelbrot(640,480,255,-2.0,0.55,-1.0,1.25);
  getch();
  closegraph();
}

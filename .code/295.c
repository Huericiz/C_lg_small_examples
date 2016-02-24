#include"stdio.h"
#include"stdlib.h"
#include"graphics.h"
#include"bios.h"
#include"conio.h"
#define LEFT 0x4b00
#define RIGHT 0x4d00
#define DOWN 0x5000
#define UP 0x4800
#define ESC 0x011b
#define SPACE 0x3920
int chessx,chessy;
int key;
int chess[20][20];
int flag=1;
void chessboard();
void draw_circle(int x,int y,int color);
void play();
int result(int x,int y);
void start();
void start()
{
  settextstyle(4,0,5);
  outtextxy(80,240,"GAME START!");
  settextstyle(3,0,3);
  outtextxy(120,340,"ESC-exit/press any key to continue");
}
void chessboard()
{
   int i,j;
   setbkcolor(WHITE);
   cleardevice();
   for(i=40;i<=440;i=i+20)
   for(j=40;j<=440;j++)
   {
      putpixel(i,j,8);
      putpixel(j,i,8);
   }
   setcolor(8);
   setlinestyle(1,0,1);
   rectangle(32,32,448,448);
}
void draw_circle(int x,int y,int color)
{
  setcolor(color);
  setlinestyle(SOLID_LINE,0,1);
  x=(x+2)*20;
  y=(y+2)*20;
  circle(x,y,8);
}
void draw_pixel(int x,int y,int color)
{
    x=(x+2)*20;
    y=(y+2)*20;
    {
       putpixel(x+8,y,color);
       putpixel(x,y-8,color);
       putpixel(x,y+8,color);
       putpixel(x+8,y,color);
    }
}
void play()
{
  int i;
  int j;
  switch(key)
  {
     case LEFT:
        if((chessx-1)<0)
          break;
        else
        {
            for(i=chessx-1,j=chessy;i>=1;i--)
            if(chess[i][j]==0)
            {
              draw_circle(chessx,chessy,WHITE);
              draw_pixel(chessx,chessy,8);
              break;
            }
            if(i<1)
              break;
            chessx=i;
            if(flag==1)
               draw_circle(chessx,chessy,BLUE);
            else
               draw_circle(chessx,chessy,RED);
        }
        break;
     case RIGHT:
        if((chessx+1)>19)
          break;
        else
        {
            for(i=chessx+1,j=chessy;i<=19;i++)
            if(chess[i][j]==0)
            {
              draw_circle(chessx,chessy,WHITE);
              draw_pixel(chessx,chessy,8);
              break;
            }
            if(i>19)
              break;
            chessx=i;
            if(flag==1)
               draw_circle(chessx,chessy,BLUE);
            else
               draw_circle(chessx,chessy,RED);
        }
        break;
     case DOWN:
        if((chessy+1)>19)
          break;
        else
        {
            for(i=chessx,j=chessy+1;j<=19;j++)
            if(chess[i][j]==0)
            {
              draw_circle(chessx,chessy,WHITE);
              draw_pixel(chessx,chessy,8);
              break;
            }
            if(j>19)
              break;
            chessy=j;
            if(flag==1)
               draw_circle(chessx,chessy,BLUE);
            else
               draw_circle(chessx,chessy,RED);
        }
        break;
      case UP:
        if((chessy-1)<0)
          break;
        else
        {
            for(i=chessx,j=chessy-1;j>=1;j--)
            if(chess[i][j]==0)
            {
              draw_circle(chessx,chessy,WHITE);
              draw_pixel(chessx,chessy,8);
              break;
            }
            if(j<1)
              break;
            chessy=j;
            if(flag==1)
               draw_circle(chessx,chessy,BLUE);
            else
               draw_circle(chessx,chessy,RED);
        }
        break;
      case ESC:
         break;
      case SPACE:
         if(chessx>=1&&chessx<=19&&chessy>=1&&chessy<=19)
         {
            if(chess[chessx][chessy]==0)
            {
               chess[chessx][chessy]=flag;
               if(result(chessx,chessy)==1)
               {
                 if(flag==1)
                 {
                    cleardevice();
                    settextstyle(4,0,9);
                    outtextxy(80,200,"BLUE Win!");
                    getch();
                    closegraph();
                    exit(0);
                 }
                 if(flag==2)
                 {
                    cleardevice();
                    settextstyle(4,0,9);
                    outtextxy(80,200,"RED Win!");
                    getch();
                    closegraph();
                    exit(0);
                 }
               }
               if(flag==1)
                 flag=2;
               else
                 flag=1;
               break;
            }
         }
         else
            break;
  }
}
int result(int x,int y)
{
  int j,k,n1,n2;
  while(1)
  {
     n1=0;
     n2=0;
     for(j=x,k=y;j>=1&&k>=1;j--,k--)
     {
        if(chess[j][k]==flag)
            n1++;
        else
           break;
     }
     for(j=x,k=y;j<=19&&k<=19;j++,k++)
     {
        if(chess[j][k]==flag)
            n2++;
        else
           break;
     }
     if(n1+n2-1>=5)
       return(1);

     n1=0;
     n2=0;
     for(j=x,k=y;j<=19&&k>=1;j++,k--)
     {
        if(chess[j][k]==flag)
            n1++;
        else
           break;
     }
     for(j=x,k=y;j>=1&&k<=19;j--,k++)
     {
        if(chess[j][k]==flag)
            n2++;
        else
           break;
     }
     if(n1+n2-1>=5)
       return(1);

     n1=0;
     n2=0;
     for(j=x,k=y;j>=1;j--)
     {
        if(chess[j][k]==flag)
            n1++;
        else
           break;
     }
     for(j=x,k=y;j<=19;j++)
     {
        if(chess[j][k]==flag)
            n2++;
        else
           break;
     }
     if(n1+n2-1>=5)
       return(1);

     n1=0;
     n2=0;
     for(j=x,k=y;k>=1;k--)
     {
        if(chess[j][k]==flag)
            n1++;
        else
           break;
     }
     for(j=x,k=y;k<=19;k++)
     {
        if(chess[j][k]==flag)
            n2++;
        else
           break;
     }
     if(n1+n2-1>=5)
       return(1);
     return 0;
  }
}
main()
{
   int gdriver=DETECT,gmode;
   initgraph(&gdriver,&gmode,"");
   start();
   key=bioskey(0);
   if(key==ESC)
      exit(0);
   else
   {
      cleardevice();
      flag=1;
      chessboard();
      do
      {
         chessx=0;
         chessy=0;
         if(flag==1)
            draw_circle(chessx,chessy,BLUE);
         else
            draw_circle(chessx,chessy,RED);
          do
          {
             while(bioskey(1)==0);
             key=bioskey(0);
             play();
          }
          while(key!=SPACE&&key!=ESC);
      }
      while(key!=ESC);
      closegraph();
   }
}

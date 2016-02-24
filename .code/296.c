#include<stdio.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<bios.h>
#define R 4
#define Key_Up 0x4800
#define Key_Enter 0x1c0d
#define Key_Down 0x5000
int Keystate;
int MouseX;
int MouseY=400;
int dx=1,dy=1;
int sizex=20,sizey=10;
int Ide,Key;
struct wall
{
   int x;
   int y;
   int color;
}a[20][20];
void draw(int x,int y)
{
   int sizx=sizex-1;
   int sizy=sizey-1;
   setcolor(15);
   line(x,y,x+sizx,y);
   line(x,y+1,x+sizx,y+1);
   line(x,y,x,y+sizy);
   line(x+1,y,x+1,y+sizy);
   setcolor(4);
   line(x+1,y+sizy,x+sizx,y+sizy);
   line(x+2,y+sizy-1,x+sizx,y+sizy-1);
   line(x+sizx-1,y+1,x+sizx-1,y+sizy);
   line(x+sizx,y+2,x+sizx,y+sizy);
   setfillstyle(1,12);
   bar(x+2,y+2,x+sizx-2,y+sizy-2);
}
void picture(int r,int l)
{
   int i,j;
   setcolor(15);
   rectangle(100,50,482,461);
   for(i=0;i<r;i++)
   for(j=0;j<l;j++)
   {
      a[i][j].color=0;
      a[i][j].x=106+j*25;
      a[i][j].y=56+i*15;
      draw(106+j*25,56+i*15);
   }
   sizex=50,sizey=5;
}
void MouseOn(int x,int y)
{
   draw(x,y);
}
void MouseSetX(int lx,int rx)
{
    _CX=lx;
    _DX=rx;
    _AX=0x07;
    geninterrupt(0x33);
}
void MouseSetY(int uy,int dy)
{
    _CX=uy;
    _DX=dy;
    _AX=0x08;
    geninterrupt(0x33);
}
void MouseSetXY(int x,int y)
{
   _CX=x;
   _DX=y;
   _AX=0x64;
   geninterrupt(0x33);
}
void MouseSpeed(int vx,int vy)
{
    _CX=vx;
    _DX=vy;
    _AX=0x0f;
    geninterrupt(0x33);
}
void MouseGetXY()
{
    _AX=0x03;
    geninterrupt(0x33);
    MouseX=_CX;
    MouseY=_DX;
}
void MouseStatus()
{
   int x;
   int status;
   status=0;
   x=MouseX;
   if(x==MouseX&&status==0)
   {
      MouseGetXY();
      if(MouseX!=x)
         if(MouseX+50<482)
            status=1;
   }
   if(status)
   {
      setfillstyle(1,0);
      bar(x,MouseY,x+sizex,MouseY+sizey);
      MouseOn(MouseX,MouseY);
   }
}
void Play(int r,int l)
{
     int ballX;
     int ballY=MouseY-R;
     int i,j,t=0;
     srand((unsigned long)time(0));
     do
     {
        ballX=rand()%477;
     }
     while(ballX<=107||ballX>=476);
     while(kbhit)
     {
        MouseStatus();
        if(ballY<=(50-R))
           dy*=(-1);
        if(ballX>=(482-R)||ballX<=(110-R))
           dx*=(-1);
        setcolor(YELLOW);
        circle(ballX+=dx,ballY-=dy,R-1);
        delay(2500);
        setcolor(0);
        circle(ballX,ballY,R-1);
        for(i=0;i<r;i++)
           for(j=0;j<l;j++)
             if(t<l*r&&a[i][j].color==0&&ballX>=a[i][j].x&&ballX<=
                 a[i][j].x+20&&ballY>=a[i][j].y&&ballY<=a[i][j].y+10)
             {
                t++;
                dy*=(-1);
                a[i][j].color=1;
                setfillstyle(1,0);
                bar(a[i][j].x,a[i][j].y,a[i][j].x+20,a[i][j].y+10);
             }
             if(ballX==MouseX||ballX==MouseX-1||ballX==MouseX-2&&
             ballX==(MouseX+50+2)||ballX==(MouseX+50+1)||ballX==(MouseX+50))
              if(ballY>=(MouseY-R))
              {
                 dx*=(-1);
                 dy*=(-1);
              }
              if(ballX>MouseX&&ballX<(MouseX+50))
                 if(ballY>=(MouseY-R))
                    dy*=(-1);
              if(t==l*r)
              {
                  sleep(1);
                  cleardevice();
                  setcolor(RED);
                  settextstyle(0,0,4);
                  outtextxy(100,200,"Win!");
                  sleep(1);
                  break;
              }
              if(ballY>MouseY)
              {
                 sleep(1);
                 cleardevice();
                 setcolor(RED);
                 settextstyle(0,0,4);
                 outtextxy(130,200,"Game Over!");
                 sleep(1);
                 break;
              }
     }
     dx=1,dy=1;
     sizex=20,sizey=10;
}
void Rule()
{
   int n;
   char *s[5]=
   {
       "move the mouse right or left to let the ball rebound",
       "when the ball bounce the wall","the wall will disappear",
       "when all the wall disappear","you will win!"
   };
   settextstyle(0,0,1);
   setcolor(GREEN);
   for(n=0;n<5;n++)
     outtextxy(150,170+n*20,s[n]);
}
void DrawMenu(int j)
{
   int n;
   char*s[4]=
   {
       "1.Mession One","2.Mesion two","3.rule","4.Exit Game"
   };
   settextstyle(0,0,1);
   setcolor(GREEN);
   for(n=0;n<4;n++)
      outtextxy(250,170+n*20,s[n]);
      setcolor(RED);
      outtextxy(250,170+j*20,s[j]);
}
void MainMenu()
{
   void JudgeIde();
   setbkcolor(BLACK);
   cleardevice();
   Ide=0,Key=0;
   DrawMenu(Ide);
   do
   {
      if(bioskey(1))
      {
         Key=bioskey(0);
         switch(Key)
         {
             case Key_Down:
             {
                Ide++;
                Ide=Ide%4;
                DrawMenu(Ide);
                break;
             }
             case Key_Up:
             {
                Ide--;
                Ide=(Ide+4)%4;
                DrawMenu(Ide);
                break;
             }
         }
      }
   }
   while(Key!=Key_Enter);
   JudgeIde();
}
void JudgeIde()
{
    switch(Ide)
    {
       case 0:
          cleardevice();
          picture(6,15);
          MouseSetX(101,431);
          MouseSetY(MouseY,MouseY);
          MouseSetXY(150,MouseY);
          Play(6,15);
          MainMenu();
          break;
       case 1:
          cleardevice();
          picture(9,15);
          MouseSetX(101,431);
          MouseSetY(MouseY,MouseY);
          MouseSetXY(150,MouseY);
          Play(9,15);
          MainMenu();
          break;
       case 2:
          cleardevice();
          Rule();
          sleep(8);
          MainMenu();
          break;
       case 3:
          cleardevice();
          settextstyle(0,0,4);
          outtextxy(150,200,"goodbye!");
          sleep(1);
          exit(0);
    }
}
main()
{
   int gdriver=DETECT,gmode;
   initgraph(&gdriver,&gmode,"");
   MainMenu();
   closegraph();
}

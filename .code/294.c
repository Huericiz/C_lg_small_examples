#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#define LEFT 0x4b00
#define RIGHT 0x4d00
#define DOWN 0x5000
#define UP 0x4800
#define ESC 0x011b
#define N 100
int i,key;
int speed;
void GameOver();
void Play();
void dwall();
void wall(int x,int y);
int Speed();
struct FOOD
{
   int x;
   int y;
   int flag;
}food;
struct Snake
{
   int x[N];
   int y[N];
   int node;
   int dir;
   int life;
}snake;
void wall(int x,int y)
{
   int sizx=9;
   int sizy=9;
   setcolor(15);
   line(x,y,x+sizx,y);
   line(x,y+1,x+sizx-1,y+1);
   line(x,y,x,y+sizy);
   line(x+1,y,x+1,y+sizy-1);
   setcolor(4);
   line(x+1,y+sizy,x+sizx,y+sizy);
   line(x+2,y+sizy-1,x+sizx,y+sizy-1);
   line(x+sizx-1,y+2,x+sizx-1,y+sizy-1);
   line(x+sizx,y+1,x+sizx,y+sizy);
   setfillstyle(1,12);
   bar(x+2,y+2,x+sizx-2,y+sizy-2);
}
void dwall()
{
    int j;
    for(j=50;j<=600;j+=10)
    {
       wall(j,40);
       wall(j,451);
    }
    for(j=40;j<=450;j++)
    {
       wall(50,j);
       wall(601,j);
    }
}
int Speed()
{
   int m;
   gotoxy(20,10);
   printf("level\n");
   gotoxy(20,12);
   printf("level2\n");
   gotoxy(20,14);
   printf("level3\n\t\tplease choose:");
   scanf("%d",&m);
   switch(m)
   {
      case 1:
         return 60000;
      case 2:
         return 40000;
      case 3:
         return 20000;
      default:
         cleardevice();
         Speed();
   }
}
void Play()
{
   srand((unsigned long)time(0));
   food.flag=1;
   snake.life=0;
   snake.dir=1;
   snake.x[0]=300;
   snake.y[0]=240;
   snake.x[1]=290;
   snake.y[1]=240;
   snake.node=2;
   do
   {
      while(!kbhit())
      {
         if(food.flag==1)
         do
         {
            food.x=rand()%520+60;
            food.y=rand()%370+60;
            food.flag=0;
         }while(food.x%10!=0||food.y%10!=0);
         if(food.flag==0)
         {
            setcolor(GREEN);
            setlinestyle(3,0,3);
            rectangle(food.x,food.y,food.x+10,food.y+10);
         }
         for(i=snake.node-1;i;i--)
         {
            snake.x[i]=snake.x[i-1];
            snake.y[i]=snake.y[i-1];
         }
         switch(snake.dir)
         {
            case 1:
               snake.x[0]+=10;
               break;
            case 2:
               snake.x[0]-=10;
               break;
            case 3:
               snake.y[0]-=10;
               break;
            case 4:
               snake.y[0]+=10;
               break;
         }
         for(i=3;i<snake.node;i++)
         {
           if(snake.x[i]==snake.x[0]&&snake.y[i]==snake.y[0])
           {
              GameOver();
              snake.life=1;
              break;
           }
         }
         if(snake.x[0]<60||snake.x[0]>590|snake.y[0]<50||snake.y[0]>440)
         {
            GameOver();
            snake.life=1;
            break;
         }
         if(snake.x[0]==food.x&&snake.y[0]==food.y)
         {
            setcolor(0);
            rectangle(food.x,food.y,food.x+10,food.y+10);
            snake.node++;
            food.flag=1;
         }
         setcolor(4);
         for(i=0;i<snake.node;i++)
         {
           rectangle(snake.x[i],snake.y[i],snake.x[i]+10,snake.y[i]+10);
         }
         delay(speed);
         setcolor(0);
         rectangle(snake.x[snake.node-1],snake.y[snake.node-1],snake.x[snake.node-1]+10,snake.y[snake.node-1]+10);
      }
      if(snake.life==1)
        break;
      key=bioskey(0);
      if(key==UP&&snake.dir!=4)
          snake.dir=3;
      else if(key==DOWN&&snake.dir!=3)
         snake.dir=4;
      else if(key==RIGHT&&snake.dir!=2)
         snake.dir=1;
      else if(key==LEFT&&snake.dir!=1)
         snake.dir=2;
   }
   while(key!=ESC);
}
void GameOver(void)
{
   cleardevice();
   setcolor(RED);
   settextstyle(0,0,4);
   outtextxy(50,200,"GAME OVER,BYE BYE!");
   sleep(3);
}
main()
{
   int gdriver=DETECT,gmode;
   initgraph(&gdriver,&gmode,"");
   speed=Speed();
   cleardevice();
   dwall();
   Play();
   getch();
   closegraph();
}

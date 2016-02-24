#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<alloc.h>
#include<time.h>
#include<bios.h>
#include<string.h>
#include<math.h>
#define ESC 27
#define F 80
#define HIGHT 480
#define WIDE 640
#define PAI 3.1415926
#define TIME 0.05
typedef struct
{
   float x;
   float y;
}_2D;
typedef struct
{
   float x;
   float y;
   float z;
}_3D;
typedef struct
{
   int anglex;
   int angley;
   int anglez;
}Axle;
typedef struct
{
  _3D*g[9][10];
  _2D*temp[9][10];
  _3D*center;
  _3D*round_center;
  float r;
}Globe;

float Observe_Mat[4][4],World_Mat[4][4];
float Sin[360],Cos[360];
size_t Size2D,Size3D,Sizeaxle,Sizeglobe;
_3D*Observe;
Globe *Moon1,*Moon2,*Earth;
int Zangle=5;

void create_table()
{
  int i;
  for(i=0;i<360;i++)
  {
     Sin[i]=sin(i*PAI/180);
     Cos[i]=cos(i*PAI/180);
  }
}
void init_observe()
{
   Observe=(_3D*)malloc(Size3D);
   Observe->x=160;
   Observe->y=0;
   Observe->z=0;
}
void to_EMat(float mat[4][4])
{
   int i,j;
   for(i=0;i<4;i++)
     for(j=0;j<4;j++)
      mat[i][j]=0;
   for(i=0;i<4;i++)
     mat[i][i]=1;
}
void _3D_cpy(_3D*point1,_3D*point2)
{
   point1->x=point2->x;
   point1->y=point2->y;
   point1->z=point2->z;
}
void _2D_cpy(_2D*point1,_2D*point2)
{
   point1->x=point2->x;
   point1->y=point2->y;
}
void init_size()
{
  Size2D=sizeof(_2D);
  Size3D=sizeof(_3D);
  Sizeaxle=sizeof(Axle);
  Sizeglobe=sizeof(Globe);
}
void init_Mat()
{
  int i,j;
  for(i=0;i<4;i++)
    for(j=0;j<4;j++)
    {
      Observe_Mat[i][j]=0;
      World_Mat[i][j]=0;
    }
    for(i=0;i<4;i++)
    {
       Observe_Mat[i][i]=1;
       World_Mat[i][i]=1;
    }
}
void mat_mult(float mat1[4][4],float mat2[4][4],float mat3[4][4])
{
  int i,j;
  for(i=0;i<4;i++)
    for(j=0;j<4;j++)
      mat3[i][j]=mat1[i][0]*mat2[0][j]+mat1[i][1]*mat2
      [1][j]+mat1[i][2]*mat2[2][j]+
        mat1[i][3]*mat2[3][j];
}
void mat_cpy(float mat1[4][4],float mat2[4][4])
{
  int i,j;
  for(i=0;i<=3;i++)
    for(j=0;j<=3;j++)
      mat1[i][j]=mat2[i][j];
}
void create_obMat()
{
  float _2Dr,_3Dr;
  _2Dr=pow((pow(Observe->x,2)+pow(Observe->y,2)),0.5);
  _3Dr=pow((pow(Observe->x,2)+pow(Observe->y,2)+pow(Observe->z,2)),0.5);
  Observe_Mat[0][0]=Observe->y/_2Dr*-1;
  Observe_Mat[0][1]=Observe->x*Observe->z/_2Dr/_3Dr*-1;
  Observe_Mat[0][2]=Observe->x/_3Dr*-1;
  Observe_Mat[1][0]=Observe->x/_2Dr;
  Observe_Mat[1][1]=Observe->y*Observe->z/_2Dr/_3Dr*-1;
  Observe_Mat[1][2]=Observe->y/_3Dr*-1;
  Observe_Mat[2][1]=_2Dr/_3Dr;
  Observe_Mat[2][2]=Observe->z/_3Dr*-1;
  Observe_Mat[3][2]=_3Dr;
  Observe_Mat[3][3]=1;
}
void _3D_mult_mat(_3D*Source,float mat[4][4])
{
  _3D*temp;
  temp=(_3D*)malloc(Size3D);
  temp->x=Source->x*mat[0][0]+Source->y*mat[1][0]+Source->z*mat[2][0]+mat[3][0];
  temp->y=Source->x*mat[0][1]+Source->y*mat[1][1]+Source->z*mat[2][1]+mat[3][1];
  temp->z=Source->x*mat[0][2]+Source->y*mat[1][2]+Source->z*mat[2][2]+mat[3][2];
  _3D_cpy(Source,temp);
}
void world_to_ob(_3D*point1,_3D*point2)
{
    point2->x=point1->x*Observe_Mat[0][0]+point1->y*Observe_Mat[1][0]+
    point1->z*Observe_Mat[2][0]+Observe_Mat[3][0];
    point2->y=point1->x*Observe_Mat[0][1]+point1->y*Observe_Mat[1][1]+
    point1->z*Observe_Mat[2][1]+Observe_Mat[3][1];
    point2->z=point1->x*Observe_Mat[0][2]+point1->y*Observe_Mat[1][2]+
    point1->z*Observe_Mat[2][2]+Observe_Mat[3][2];
}
void _3Dto_2D(_3D*_3Dpoint,_2D*_2Dpoint)
{
  _2Dpoint->x=WIDE/2+F*_3Dpoint->x/_3Dpoint->z;
  _2Dpoint->y=HIGHT/2-F*_3Dpoint->y/_3Dpoint->z;
}
void z_round(Globe*globe,int angle)
{
  float z[4][4];
  int i,j;
  to_EMat(z);
  z[0][0]=Cos[get_angle(angle)];
  z[0][1]=Sin[get_angle(angle)];
  z[1][0]=-z[0][1];
  z[1][1]=z[0][0];
  for(i=0;i<9;i++)
   for(j=0;j<10;j++)
     _3D_mult_mat(globe->g[i][j],z);
}
void y_round(Globe*globe,int angle)
{
  float y[4][4];
  int i,j;
  to_EMat(y);
  y[0][0]=Cos[get_angle(angle)];
  y[2][0]=Sin[get_angle(angle)];
  y[0][2]=-y[2][0];
  y[2][2]=y[0][0];
  for(i=0;i<9;i++)
   for(j=0;j<10;j++)
     _3D_mult_mat(globe->g[i][j],y);
}
void x_round(Globe*globe,int angle)
{
  float x[4][4];
  int i,j;
  to_EMat(x);
  x[1][1]=Cos[get_angle(angle)];
  x[1][2]=Sin[get_angle(angle)];
  x[2][1]=-x[1][2];
  x[2][2]=x[1][1];
  for(i=0;i<9;i++)
   for(j=0;j<10;j++)
     _3D_mult_mat(globe->g[i][j],x);
}
void init_gph()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"");
  cleardevice();
  setbkcolor(WHITE);
  bar(0,0,640,480);
}
Globe*create_globe()
{
   Globe*p;
   int i,j;
   p=(Globe*)malloc(Sizeglobe);
   for(i=0;i<9;i++)
     for(j=0;j<10;j++)
     {
       p->g[i][j]=(_3D*)malloc(Size3D);
       p->temp[i][j]=(_2D*)malloc(Size2D);
     }
     p->center=(_3D*)malloc(Size3D);
     p->round_center=(_3D*)malloc(Size3D);
     return p;
}
int get_angle(int angle)
{
  angle%=360;
  if(angle<0)
    angle=360+angle;
  return angle;
}
_3D *get_3Dpoint(float x0,float y0,float z0)
{
  _3D*p;
  p=(_3D*)malloc(Size3D);
  p->x=x0;
  p->y=y0;
  p->z=z0;
  return p;
}
Axle*get_axle(int qx,int qy,int qz)
{
  Axle*p;
  p=(Axle*)malloc(Sizeaxle);
  p->anglex=qx;
  p->angley=qy;
  p->anglez=qz;
  return p;
}
void place_globe(Globe*globe)
{
  float tempf[4][4];
  int i,j;
  to_EMat(tempf);
  tempf[3][0]=(globe->center)->x;
  tempf[3][1]=(globe->center)->y;
  tempf[3][2]=(globe->center)->z;
  for(i=0;i<9;i++)
     for(j=0;j<10;j++)
      _3D_mult_mat(globe->g[i][j],tempf);
}
void init_globe(Globe*globe,float r,_3D*thecenter,_3D*rnd_center)
{
   int i,j;
   globe->r=r;
   for(i=-4;i<=4;i++)
     for(j=0;j<=9;j++)
     {
       (globe->g[i+4][j])->x=r*Cos[get_angle(i*18)]*Cos[get_angle(j*36)];
       (globe->g[i+4][j])->y=r*Cos[get_angle(i*18)]*Sin[get_angle(j*36)];
       (globe->g[i+4][j])->z=r*Sin[get_angle(i*18)];
     }
     _3D_cpy(globe->center,thecenter);
     _3D_cpy(globe->round_center,rnd_center);
     place_globe(globe);
}
void Wglobe_to_2D(Globe*globe)
{
  int i,j;
  _3D*point;
  point=(_3D*)malloc(Size3D);
  for(i=0;i<9;i++)
    for(j=0;j<10;j++)
    {
      world_to_ob(globe->g[i][j],point);
      _3Dto_2D(point,globe->temp[i][j]);
    }
}
void draw_globe(Globe*g,int color)
{
  int i,j,n;
  Wglobe_to_2D(g);
  setcolor(color);
  for(i=0;i<9;i++)
   for(j=0;j<10;j++)
   {
     n=j+1;
     if(n==10)
      n=0;
     line((g->temp[i][j])->x,(g->temp[i][j])->y,(g->temp[i][n])->x,(g->temp[i][n])->y);
   }
  for(j=0;j<10;j++)
   for(i=0;i<9;i++)
   {
     n=i+1;
     if(n==10)
      n=0;
     line((g->temp[i][j])->x,(g->temp[i][j])->y,(g->temp[n][j])->x,(g->temp[n][j])->y);
   }
}
void init_start()
{
  int i;
  _3D*p1,*p2,*p3,*p4;
  p1=(_3D*)malloc(Size3D);
  p2=(_3D*)malloc(Size3D);
  p3=(_3D*)malloc(Size3D);
  p4=(_3D*)malloc(Size3D);
  init_gph();
  setcolor(RED);
  circle(320,240,200);
  init_size();
  create_table();
  init_observe();
  init_Mat();
  create_obMat();
  Moon1=create_globe();
  Moon2=create_globe();
  Earth=create_globe();
  p1=get_3Dpoint(0,100,0);
  p2=get_3Dpoint(0,-100,0);
  p3=get_3Dpoint(0,0,0);
  p4=get_3Dpoint(0,0,0);
  init_globe(Moon1,20,p1,p4);
  init_globe(Moon2,20,p2,p4);
  init_globe(Earth,50,p3,p4);
  draw_globe(Earth,BLUE);
  draw_globe(Moon1,DARKGRAY);
  draw_globe(Moon2,CYAN);
}
void roll()
{
   clock_t start,end;
   int angle=0;
   start=clock();
   while(!kbhit())
   {
     end=clock();
     if((end-start)/CLK_TCK>TIME)
     {
       draw_globe(Moon1,BLACK);
       draw_globe(Moon2,BLACK);
       draw_globe(Earth,BLACK);
       z_round(Moon1,Zangle);
       x_round(Moon2,Zangle);
       y_round(Earth,Zangle);
       angle+=5;
       if(get_angle(angle)<180)
       {
         draw_globe(Moon1,DARKGRAY);
         draw_globe(Earth,BLUE);
         draw_globe(Moon2,CYAN);
       }
       else
       {
         draw_globe(Moon2,CYAN);
         draw_globe(Earth,BLUE);
         draw_globe(Moon1,DARKGRAY);
       }
       start=clock();
     }
   }
}
void main()
{
  init_start();
  roll();
  getch();
  closegraph();
}

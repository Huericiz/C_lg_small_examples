#include"stdlib.h"
#include"graphics.h"
main()
{
   int gdriver=DETECT,gmode;
   int i,size;
   void*buf;
   initgraph(&gdriver,&gmode,"");
   setbkcolor(3);
   setcolor(RED);
   rectangle(80,80,100,100);
   size=imagesize(80,80,100,100);
   buf=malloc(size);
   getimage(80,80,100,100,buf);
   for(i=1;i<=40;i++)
   {
     cleardevice();
     putimage(300,20+i*10,buf,COPY_PUT);
     delay(1e20);
   }
   for(i=1;i<50;i++)
   {
     cleardevice();
     putimage(0+i*15,0+i*10,buf,COPY_PUT);
     putimage(640-i*15,0+i*10,buf,COPY_PUT);
     delay(1e20);
   }
   getch();
   closegraph();
}


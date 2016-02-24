#include"conio.h"
#include"graphics.h"
#include"stdlib.h"
main()
{
   int gdriver=DETECT,gmode;
   unsigned size;
   void*buf;
   initgraph(&gdriver,&gmode,"");
   setcolor(15);
   rectangle(20,20,200,200);
   setcolor(RED);
   line(20,20,200,200);
   outtext("press any key,you can see the same image!!");
   getch();
   size=imagesize(20,20,200,200);
   if(size!=-1)
   {
      buf=malloc(size);
      if(buf)
      {
        getimage(20,20,200,200,buf);
        putimage(100,100,buf,COPY_PUT);
        putimage(300,50,buf,COPY_PUT);
        putimage(400,150,buf,COPY_PUT);
      }
   }
   getch();
   closegraph();
}

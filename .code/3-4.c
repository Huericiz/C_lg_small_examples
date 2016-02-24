#include<conio.h>
#include<graphics.h>
int main()
{
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"");
   settextjustify(RIGHT_TEXT,BOTTOM_TEXT);
   moveto(300,200);
   outtext("RIGHT_TEXT,BOTTOM_TEXT");
   settextjustify(RIGHT_TEXT,TOP_TEXT);
   moveto(300,200);
   outtext("RIGHT_TEXT,TOP_TEXT");
   settextjustify(LEFT_TEXT,BOTTOM_TEXT);
   moveto(300,200);
   outtext("LEFT_TEXT,BOTTOM_TEXT");
   settextjustify(RIGHT_TEXT,TOP_TEXT);
   moveto(300,200);
   outtext("RIGHT_TEXT,TOP_TEXT");
   setcolor(1);
   line(300,200,300,300);
   setcolor(2);
   line(300,200,300,300);
   setcolor(3);
   line(300,200,100,200);
   setcolor(4);
   line(300,200,500,200);
   getch();
   closegraph();
   return 0;
}

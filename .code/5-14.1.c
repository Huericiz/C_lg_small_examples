#include<stdio.h>
#include<time.h>
main()
{
  clock_t goal,wait,now;
  wait=(clock_t)3*CLK_TCK;
  now=clock();
  goal=wait+now;
  for(;goal>now;now=clock()){;}
  getch();
}

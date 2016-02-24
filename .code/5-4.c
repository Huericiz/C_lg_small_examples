#include<stdio.h>
#include<dos.h>
#include<time.h>
main()
{
  long ticks;
  double seconds,minutes,hours;
  ticks=biostime(0,NULL);
  seconds=ticks/CLK_TCK;

  minutes=ticks/CLK_TCK/60;
  hours=ticks/CLK_TCK/3600;
  printf("\n Ticks since midnight %lu ",ticks);
  printf("\n Seconds since midnight %.4lf",seconds);
  printf("\n Minutes since midnight %.4f",minutes);
  printf("\n Hours since midnight %.4f",hours);
  getch();
}

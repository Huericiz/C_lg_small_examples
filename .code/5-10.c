#include<stdio.h>
#include<time.h>
#include<sys\timeb.h>
main()
{
  struct timeb tz;
  ftime(&tz);
  printf("\nMinintes difference between local zone and GMT zone is %d",tz.timezone);
  printf("\nLocal time is %s",asctime(localtime(&(tz.time))));
  getch();
}

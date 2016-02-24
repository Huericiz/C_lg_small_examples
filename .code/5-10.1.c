#include<stdio.h>
#include<time.h>
#include<sys\timeb.h>
main()
{
  struct timeb tz;ftime(&tz);
  printf("\nSeconds since 1-1-1970(GMT) is %ld.%ld",tz.time,tz.millitm);
  getch();
}

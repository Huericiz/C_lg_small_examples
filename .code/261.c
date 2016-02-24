#include"stdio.h"
#include"time.h"
#include"conio.h"
main()
{
   time_t now;
   time(&now);
   printf("\nNow is:%s",ctime(&now));
   getch();
}

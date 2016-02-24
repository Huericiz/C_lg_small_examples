#include<dos.h>
main(void)
{
   unsigned free=50;
   int times;
   for(times=0;times<1000;times++)
   {
      free=(free+times)%40000;
      sound(free);
      delay(1000);
   }
   nosound;
}

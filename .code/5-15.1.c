#include<stdio.h>
#include<dos.h>
main()
{
  unsigned freq[]={392,392,440,392,523,494,392,392,440,392,587,523,
                     392,392,784,659,523,494,440,698,698,659,523,587,523};
  unsigned dely[]={375,125,500,500,500,1000,375,125,500,500,500,1000,
                     375,125,500,500,500,1000,375,125,500,500,500,1000};
  int i;
  for(i=0;i<25;i++)
  {
    sound(freq[i]);
    delay(dely[i]);
    nosound();
  }
  getch();
}
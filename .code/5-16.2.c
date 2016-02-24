#include<stdio.h>
#include<dos.h>
main()
{
  printf("\n Press any key to quit!");
  for(;;)
  {
    if((char)(bdos(0xb,0,0)))
    {
      printf("\n You have pressed a key to quit!");
      break;
    }
  }
  getch();
}

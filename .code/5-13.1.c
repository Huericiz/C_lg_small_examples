#include<stdio.h>
#include<dos.h>
int ctrbrkhnd()
{
  printf("\nControl+Break pressed.program quit...");
  return 0;
}
main()
{
  if(getcbrk()==0)
  {
    setcbrk(1);
  }
  ctrlbrk(ctrbrkhnd);
  for(;;)
  {
    printf("\nWaiting...Press Control+Break to quit.");
  }
  getch();
}

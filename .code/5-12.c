#include<stdio.h>
#include<bios.h>
main(void)
{
  int printstatus=0;
  printstatus=biosprint(2,0,0);
  if(printstatus&1)
  {
    printf("\nTie out!");
  }
  else if(printstatus&8)
  {
    printf("\nInput or output error!");
  }
  else if(printstatus&16)
  {
    printf("\nPrint being selected!");
  }
  else if(printstatus&32)
  {
    printf("\nOut of paper!");
  }
  else if(printstatus&64)
  {
    printf("\nAcknowledge");
  }
  else if(printstatus&128)
  {
    printf("\nPrinter is not busy!");
  }
  else
  {
    printf("\nPrinter is in unknown status!");
  }
  getch();
}

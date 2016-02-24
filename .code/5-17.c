#include<stdio.h>
#include<dos.h>
main()
{
  int msize;
  msize=biosmemory();
  printf("\nBIOS regular memory size is %dKb",msize);
  getch();
}

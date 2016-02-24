#include<stdio.h>
#include<time.h>
main()
{
  clock_t start,end;
  int i;
  start=clock();
  for(i=0;i<1000;i++){;}
  end=clock();
  printf("\n%f seconds passed",(end-start)/CLK_TCK);
  getch();
}

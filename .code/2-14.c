#include<stdio.h>
#include<stdlib.h>
main()
{
  double result,x1=4.0;
  div_t x;
  x=div(10,3);
  result=exp(x);
  printf("10 div 3=%d remainder %d\n",x.quot,x.rem);
  printf("'e'raised to the power of %lf(e^%lf)=%lf\n",x1,x1,result);
  getch();
}

#include<stdio.h>
#include<math.h>
main()
{
  double value,value1,value2;
  double x=2,x1=8.6872,x2=100.00;
  int exponent=3;
  value=ldexp(x,exponent);
  value1=log(x1);
  value2=log10(x2);
  printf("The ldexp value is:%lf\n",value);
  printf("The natural log of %lf is %lf\n",x1,value1);
  printf("The common log of %lf is %lf\n",x2,value2);
  getch();
}

#include<stdio.h>
#include<math.h>
main()
{
  double number=123.54,x=0.5;
  double result1,result2,result3,result4,result5,result6;
  double up;
  up=ceil(number);
  result1=cos(x);
  result2=cosh(x);
  result3=sin(x);
  result4=sinh(x);
  result5=tan(x);
  result6=tanh(x);
  printf("original number %5.2lf\n",number);
  printf("number rounded up %5.2lf\n",up);
  printf("%lf%lf%lf%lf%lf%lf",result1,result2,result3,result4,result5,result6);
  getch();
}

#include<stdio.h>
#include<math.h>
main()
{
  double result1,result2,result3;
  double x=0.5;
  result1=acos(x);
  result2=asin(x);
  result3=atan(x);
  printf("The arc cosine of %lf is %lf\n",x,result1);
  printf("The arc sine of %lf is %lf\n",x,result2);
  printf("The arc tangent of %lf is %lf\n",x,result3);
  getch();
}

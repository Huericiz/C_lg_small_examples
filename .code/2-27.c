#include<stdio.h>
#include<math.h>
main()
{
  double x,y,result;
  x=3.0;
  y=4.0;
  result=hypot(x,y);
  printf("\n The hypotenuse is:%lf",result);
  getch();
}

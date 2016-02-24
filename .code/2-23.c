#include<stdio.h>
#include<math.h>
main()
{
  double x,y;
  x=2.0;
  y=3.0;
  printf("%lf raised to %lf is %lf\n",x,y,pow(x,y));
  printf("10 raised to %lf is %lf\n",x,pow10(x));
  getch();
}

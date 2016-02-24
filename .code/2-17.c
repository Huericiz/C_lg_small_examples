#include<stdio.h>
#include<math.h>
main()
{
  double mantissa,number;
  int exponent;
  number=8.0;
  mantissa=frexp(number,&exponent);
  printf("The number two to the",number);
  printf("%lf times two to the",mantissa);
  printf("power of %d\n",exponent);
  getch();

}

#include<stdio.h>
#include<math.h>

typedef struct complexnumber
{
  double rpart;
  double ipart;
}cnumber;
cnumber cpsin(cnumber a)
{
  cnumber value1;
  value1.rpart=sin(a.rpart)*(exp(a.ipart)+exp(-a.ipart))/2.0;
  value1.ipart=cos(a.rpart)*(exp(a.ipart)-exp(-a.ipart))/2.0;
  return value1;
}
cnumber cpcos(cnumber a)
{
  cnumber value2;
  value2.rpart=cos(a.rpart)*(exp(a.ipart)+exp(-a.ipart))/2.0;
  value2.ipart=-sin(a.rpart)*(exp(a.ipart)-exp(-a.ipart))/2.0;
  return value2;
}
main()
{
  cnumber a={-1.6,4.9},value1,value2;
  value1=cpsin(a);
  value2=cpcos(a);
  printf("\nThe result is :%5.2lfe",value1.rpart);
  if(value1.ipart>=0.0) printf("+%5.2lfi",value1.ipart);
  else             printf("%5.2lfi",value1.ipart);
  printf("\nThe result is :%5.2lfe",value2.rpart);
  if(value2.ipart>=0.0) printf("+%5.2lfi",value2.ipart);
  else             printf("%5.2lfi",value2.ipart);
  getch();
}

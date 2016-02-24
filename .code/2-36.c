#include<math.h>
typedef struct complexnumber
{
  double rpart;
  double ipart;
}cnumber;
cnumber cpmul(cnumber a,cnumber b)
{
  cnumber value1;
  value1.rpart=a.rpart*b.rpart-a.ipart*b.ipart;
  value1.ipart=a.rpart*b.ipart+a.ipart*b.rpart;
  return value1;
}
cnumber cpdiv(cnumber a,cnumber b)
{
  cnumber value2;
  double t=b.rpart*b.rpart+b.ipart*b.ipart;
  if(t!=0.0)
  {
    value2.rpart=(a.rpart*b.rpart+a.ipart*b.ipart)/t;
    value2.ipart=(-a.rpart*b.ipart+a.ipart*b.rpart)/t;
    return value2;
  }
}
main()
{
  cnumber a={-5.7,-6.5},b={2.9,7.3};
  cnumber value1,value2;
  value1=cpmul(a,b);
  value2=cpdiv(a,b);
  printf("\n The result is:%5.2lf",value1.rpart);
  if(value1.ipart>=0.0) printf("+%5.2lfi",value1.ipart);
  else              printf("%5.2lfi",value1.ipart);
  printf("\n The result is:%5.2lf",value2.rpart);
  if(value2.ipart>=0.0) printf("+%5.2lfi",value2.ipart);
  else              printf("%5.2lfi",value2.ipart);
  getch();
}

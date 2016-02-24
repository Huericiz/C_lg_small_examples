#include<stdio.h>
#define MAX_TERMS 100
typedef struct
{
  float coef;
  int expon;
}polynomial;

polynomial terms[MAX_TERMS];
int avail=0;
int COMPARE(int coef1,int coef2)
{
  if(coef1<coef2)
    return -1;
  else if(coef1==coef2)
    return 0;
  else
    return 1;
}
void attach(float coefficient,int exponent)
{
  if(avail>MAX_TERMS)
  {
    printf("Too many terms in the polynomial \n");
    exit(1);
  }
  terms[avail].coef=coefficient;
  terms[avail++].expon=exponent;
}
void padd(int starta,int finisha,int startb,int finishb,int *startd,int *finishd)
{
  float coefficient;
  *startd=avail;
  while(starta<=finisha&&startb<=finishb)
   switch(COMPARE(terms[starta].expon,terms[startb].expon))
   {
     case -1:
       attach
   }
}
void main()
{
  int startd,finishd;
  padd(4,1,3,2,&startd,&finishd);
  getch();
}

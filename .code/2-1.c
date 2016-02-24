#include<stdio.h>
#include<stdlib.h>
main()
{
  printf("\nnumber:%d absolute value:%d",4,abs(4));
  printf("\nnumber:%d absolute value:%d",0,abs(0));
  printf("\nnumber:%d absolute value:%d",-4,abs(-4));
  printf("\nnumber:%d absolute value:%d",65535,abs(65535));
  printf("\nnumber:%ld absolute value:%ld",65536,labs(65536));
  getch();
}

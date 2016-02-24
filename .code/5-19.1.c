#include<stdio.h>
#include<mem.h>
main()
{
  int str[64],*p,i;
  p=memset(str,0,sizeof(int)*4);
  printf("\nInital by 0:");
  for(i=0;i<4;i++){printf("%4(%d),",p[0+i],p[0+i]);}
  p=memset(str,-1,sizeof(int)*4);
  printf("\nIntal by -1:");
  for(i=0;i<4;i++){printf("%4(%d),",p[0+i],p[0+i]);}
  p=memset(str,1,sizeof(int)*4);
  printf("\nIntal by 1:");
  for(i=0;i<4;i++){printf("%4(%d),",p[0+i],p[0+i]);}
  printf("\n\t  ");
  for(i=0;i<4;i++)
  {
    printf("%4x(%d),",(char)p[0+i],(char)p[0+i]);
  }
  getch();
}

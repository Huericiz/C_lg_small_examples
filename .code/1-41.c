#include<stdio.h>
void main()
{
   int i,j,n=13;
   printf("N=");
   while(n>12)
   scanf("%d",&n);
   for(i=0;i<=n;i++)
   {
       for(j=0;j<24-2*i;j++)
          printf(" ");
       for(j=1;j<i+2;j++)
          printf("%4d",c(i,j));
       printf("\n");
       getch();
   }
}
int c(int x,int y)
{
   int z;
   if((y==1)||(y==x+1))
   return 1;
   z=c(x-1,y-1)+c(x-1,y);
   return z;
}

#include<stdio.h>
#define N 3
#define M N*(N+1)/2
void main()
{
  int A[M],B[M],C[M][N];
  int i,j;
  printf("Please input array A:\n");
  for(i=0;i<M;i++)
  {
    scanf("%d",&A[i]);
  }
  printf("Please input array B:\n");
  for(i=0;i<M;i++)
  {
    scanf("%d",&B[i]);
  }
  mult(A,B,C);
  printf("\nThe result of A*B is:\n");
  for(i=0;i<N;i++)
  {
   for(j=0;j<N;j++)
   {
     printf("%d  ",C[i][j]);
   }
   printf("\n");
  }
  getch();
}

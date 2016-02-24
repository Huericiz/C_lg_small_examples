#include<stdio.h>
#define n 3
#define m 3
void Get_Saddle(int A[m][n])
{
  int i,j,flag,min,k;
  for(i=0;i<m;i++)
  {
    for(min=A[i][0],j=0;j<n;j++)
      if(A[i][j]<min)min=A[i][j];
      for(j=0;j<n;j++)
      if(A[i][j]==min)
      {
        for(flag=1,k=0;k<m;k++) if(min<A[k][j]) flag=0;
        if(flag)
        printf("Found a saddle element!\nA[%d][%d]=%d",i,j,A[i][j]);
      }
  }
  printf("\n");
}
void main()
{
  int A[m][m]={1,2,3,4,5,6,7,8,9};
  Get_Saddle(A);
  getch();
}

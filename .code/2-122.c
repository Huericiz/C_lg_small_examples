#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<integration.h>
static double gt[5]={-0.9061798459,-0.5384693101,0.0,0.5384693101,0,9061798459};
static double gc[5]={0.2369268851,0.4786286705,0.5688888889,0.4786286705,0.2369268851};
double gauss(GINTEGP ap)
{
  int n,m,j,k,q,l,*is;
  double y[2],p,*x,*a,*b;
  double s=0;

  n=ap->n;
  is=malloc(2*(n+1)*sizeof(int));
  x=malloc(n*sizeof(double));
  a=malloc(2*(n+1)*sizeof(double));
  b=malloc((n+1)*sizeof(double));
  m=l=1;
  a[n]=1.0;a[2*n+1]=1.0;
  while(1)
  {
    for(j=m;j<=n;j++)
    {
      (*ap->ud)(j-1,n,x,y);
      a[j-1]=(y[1]-y[0])/(2.0*ap->js[j-1]);
      b[j-1]=a[j-1]+y[0];
      x[j-1]=a[j-1]*gt[0]+b[j-1];
      a[n+j]=0.0;
      is[j-1]=1;is[n+j]=1;
    }
    j=n;
    do
    {
      k=is[j-1];
      p=(j==n)?(*ap->ptr)(n,x):1.0;
      a[n+j]=a[n+j+1]*a[j]*p*gc[k-1]+a[n+j];
      is[j-1]++;
      if(is[j-1]>5)
        if(is[n+j]>=ap->js[j-1])
        {
          j=j-1;q=1;
          if(j==0)
          {
            s=a[n+1]*a[0];
            free(is);free(x);free(a);free(b);
            return s;
          }
        }
        else
        {
          is[n+j]++;
          b[j-1]+=a[j-1]*2.0;
          is[j-1]=1;k=is[j-1];
          x[j-1]=a[j-1]*gt[k-1]+b[j-1];
          q=(j==n)?1:0;
        }
        else
        {
          k=is[j-1];
          x[j-1]=a[j-1]*gt[k-1]+b[j-1];
          q=(j==n)?1:0;
        }
    }while(q==1);
    m=j+1;
  }
  return s;
}
void gauss_ud_ptr(int j,int n,double x[],double y[])
{
  double q;
  switch(j)
  {
    case 0:{y[0]=0.0;y[1]=1.0;break;}
    case 1:{y[0]=0.0;y[1]=sqrt(1.0-x[0]*x[0]);break;}
    case 2:{q=x[0]*x[0]+x[1]*x[1];y[0]=sqrt(q);
          y[1]=sqrt(2.0-q);break;}
  }
  return;
}
double gauss_ptr(int n,double x[])
{
  return 3.0*x[2]*x[2];
}
main()
{
  int js[3]={4,4,4};
  GINTEG ga={3,js,gauss_ud_ptr,gauss_ptr};
  double s=gauss(&ga);
  printf("\ns=%e\n\n",s);
}

#include<stdio.h>
#include<stdlib.h>
#include<matrix.h>

main()
{
  double ar[4][4]={{0.2368,0.2471,0.2568,1.2671},
                    {1.1161,0.1254,0.1397,0.1490},
                    {0.1582,1.1675,0.1768,0.1871},
                    {0.1968,0.2071,1.2168,0.2271}};
  double ai[4][4]={{0.1345,0.1678,0.1875,1.1161},
                   {1.2671,0.2017,0.7024,0.2701},
                   {-0.2836,-1.1967,0.3558,-0.2078},
                   {0.3576,-1.2345,2.1185,0.4773}};
  double br[4][4],bi[4][4],cr[4][4],ci[4][4];
  CM2 ma={4,4,(double*)ar,(double*)ai};
  CM2 mb={4,4,(double*)br,(double*)bi};
  CM2 mc={4,4,(double*)cr,(double*)ci} ;

  cmatrixcpy2(&ma,&mb);
  printcm2r("\nMatrix AR is:\n",&ma);
  printcm2r("\nMatrix AI is:\n",&ma);

  if(0==multi_matrix_inverse(&ma))
}

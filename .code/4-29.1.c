#include<stdio.h>
main()
{
  FILE*tp1,*tp2;
  if((tp1=tmpfile())!=NULL)
  {
    printf("\n temp file created!");
  }
  if((tp2=tmpfile())!=NULL)
  {
    printf("\n temp file created!");
  }
  getch();
}

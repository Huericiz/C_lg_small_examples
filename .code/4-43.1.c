#include<stdio.h>
main()
{
  FILE*fp;
  int i=4;
  fp=fopen("Extest2.txt","rb");
  putw(i,fp);
  if(ferror(fp))
  {
    printf("\nFailed to write to file!");
    clearerr(fp);
    if(!ferror(fp))
    {
      printf("\nError and EOP indicators have reset!");
    }
  }
  fclose(fp);
  getch();
}

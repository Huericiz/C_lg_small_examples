#include<stdio.h>
#include<sys\stat.h>
#include<io.h>
main()
{
  int i,access_mod;
  FILE*fp;
  char c='a';
  if((fp=fopen("Extemp1.txt","w+"))!=NULL)
  {
    for(i=0;i<20;i++){fputc(c,fp);}
    fclose(fp);
    if((chmod("Extemp1.txt",S_IREAD))==0)
    {
      access_mod=access("Extemp1.txt",2);
      if(access_mod!=0)
      {
        printf("File:Extemp1.txt can not be written!\n");
      }
      else
      {
        printf("File:Extemp1.txt can be written!\n");
      }
    }
  }
  getch();
}

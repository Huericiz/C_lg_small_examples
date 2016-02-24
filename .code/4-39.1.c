#include<stdio.h>
main()
{
  FILE*fp;
  char c='a';
  int i;
  if((fp=fopen("Extemp.txt","w+"))!=NULL)
  {
    for(i=0;i<20;i++)
    fputc(c,fp);
    fclose(fp);
    mkdir("\\TC\\TEMP");
    rename("Extemp.txt","\\TC\\TEMP\\Extemp.txt");
  }
  getch();
}

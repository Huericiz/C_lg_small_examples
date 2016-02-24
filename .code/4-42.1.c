#include<stdio.h>
#include<dos.h>
#include<io.h>
main()
{
  int attributes,i;
  FILE*fp;
  char c='a';
  if((fp=fopen("Extemp.txt","w+"))!=NULL)
  {
    for(i=0;i<20;i++)
    fputc(c,fp);
    fclose(fp);
  }
  printf("\n");
  if((attributes=_chmod("Extemp.txt",0))!=-1)
  {
    if(attributes&FA_ARCH) printf("\tArchive ");
    if(attributes&FA_RDONLY) printf("\tReadonly");
  }
  _chmod("Extemp.txt",1,FA_RDONLY);
  printf("\n");
  if((attributes=_chmod("Extemp.txt",0))!=-1)
  {
    if(attributes&FA_ARCH) printf("\tArchive ");
    if(attributes&FA_RDONLY) printf("\tReadonly");
  }
  getch();
}

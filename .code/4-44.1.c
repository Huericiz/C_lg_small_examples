#include<stdio.h>
main()
{
  FILE*fp;
  char c='a';
  int i;
  long length=0;
  if((fp=fopen("Extemp.txt","w+"))!=NULL)
  {
    for(i=0;i<20;i++){fputc(c+i,fp);}
    fclose(fp);
  }
  if((fp=fopen("Extemp.txt","r"))!=NULL)
  {
    while((c=fgetc(fp))!=EOF){length++;}
    fclose(fp);
    printf("\n length :%ld",length);
  }
  if((fp=fopen("Extemp.txt","r"))!=NULL)
  {
    fseek(fp,0,SEEK_END);
    printf("\t length :%ld",ftell(fp));
    fclose(fp);
  }
  getch();
}

#include<stdio.h>
main()
{
  FILE*inputfile;
  char*c="Hello the world",line[256],buffer[128];
  printf(" \nTemporary file is %s ",tmpnam(buffer));
  if((inputfile=fopen(buffer,"w+"))!=NULL)
  {
    fputs("\nYou are welcome",inputfile);
    fputc(':',inputfile);
    fprintf(inputfile,"\n%s",c);
    fclose(inputfile);
  }
  if((inputfile=fopen(buffer,"r"))!=NULL)
  {
    while(fgets(line,sizeof(line),inputfile))
    {
      printf("%s",line);
    }
    fclose(inputfile);
  }
  getch();
}

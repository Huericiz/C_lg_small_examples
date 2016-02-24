#include<stdio.h>
main()
{
  FILE*fp;
  char *c="Hello the world";
  if((fopen("Exteml.txt","w+")!=NULL))
  {
    fputs("You are welcome",fp);
    fputc(':',fp);
    fprintf(fp,"\n%s",c);
    fclose(fp);
  }
  getch();
}

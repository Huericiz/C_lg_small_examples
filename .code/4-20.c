#include<stdio.h>
main()
{
  FILE*fp;
  char*c="Hello the world",s[128];
  if((fp=fopen("Exteml.txt","w+"))!=NULL)
  {
    fputs("You are welcome",fp);
    fputc(':',fp);
    fprintf(fp,"\n%s",c);
    fclose(fp);
  }
  if((fp=fopen("Exteml.txt","rb"))!=NULL)
  {
    while(fgets(s,sizeof(s),fp))
    {
      printf("%s",s);
    }
    fclose(fp);
  }
  getch();
}

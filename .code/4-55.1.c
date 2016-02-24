#include<stdio.h>
#include<io.h>
main()
{
  char c,s[20]="hello";
  FILE*fp1,*fp2,*fp;
  int result;
  fp1=fopen("Extem1.txt","w+");
  fprintf(fp1,"%s",s);
  if((fp2=freopen("Extem2.txt","w+",fp1))!=NULL)
  {
    fprintf(fp1,"%s",s);
    fprintf(fp1,"%s",s);
  }
  if((result=fscanf(fp2,"%s",s))<0)
  {
    printf("\nfailed to write to Extem1.txt");
  }
  fclose(fp1);
  fclose(fp2);
  if((fp=fopen("Extem1.txt","r"))!=NULL)
  {
    printf("\n");
    while((c=fgetc(fp))!=EOF)
    printf("%c",c);
    fclose(fp);
  }
  if((fp=fopen("Extem2.txt","r"))!=NULL)
  {
    printf("\n");
    while((c=fgetc(fp))!=EOF)
    printf("%c",c);
    fclose(fp);
  }
  getch();
}

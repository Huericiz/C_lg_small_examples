#include<stdio.h>
main()
{
  FILE *input,*fp1,*fp2,*fp3;
  char*c="Hello the world";
  if((input=fopen("Extemp.txt","w+"))==NULL)
  {
    printf("Error open Extemp.txt");
  }
  else
  {
    printf("Handle for Extemp.txt %d \n",input->fd);
    printf("Handle for stdin %d \n",stdin->fd);
    fputs("You are welcom",input);
    fputc(':',input);
    fprintf(input,"\n%s",c);
    fclose(input);
  }
  if((fp1=fopen("Extemp.txt","r"))!=NULL)
  {
    printf("Handle of fp1 is %d \n",fp1->fd);
    fclose(fp1);
  }
  if((fp2=fopen("Extemp.txt","r"))!=NULL)
  {
    printf("Handle of fp2 is %d \n",fp2->fd);
    if((fp3=fopen("Extemp.txt","r"))!=NULL)
    {
      printf("Handle of fp3 is %d \n",fp3->fd);
      fclose(fp3);
    }
    fclose(fp2);
  }
  getch();
}

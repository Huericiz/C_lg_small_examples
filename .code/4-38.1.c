#include<stdio.h>
main()
{
  FILE *fp;
  long offset;
  fpos_t pos=0;
  char c='a';
  int i;
  if((fp=fopen("Extemp.txt","w+"))!=NULL)
  {
    printf("\nCurrent position is %ld",ftell(fp));
    for(i=0;i<20;i++) {fputc(c+i,fp);}
    fseek(fp,5,SEEK_SET);
    printf("\n Current position is %ld",ftell(fp));
    rewind(fp);
    fgetpos(fp,&pos);
    printf("\n Current position is %ld",pos);
    pos=10;
    fsetpos(fp,&pos);
    printf("\n Current position is %ld",ftell(fp));
    fclose(fp);
  }
  getch();
}

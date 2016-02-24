#include<stdio.h>
#include<io.h>
#include<fcnt1.h>
#include<sys\stat.h>
main()
{
  int handle;
  FILE*fp;
  if((handle=open("Extemp.txt",O_CREAT,S_IWRITE))==-1)
  {
    printf("\n Error open the file Extemp.txt");
  }
  else
  {
    printf("\nThe file Extemp.txt has created!");
    fp=fdopen(handle,"w");
    fprintf(fp,"%s\n","hello!");
    fclose(fp);
    close(handle);
  }
  getch();
}

#include<stdio.h>
#include<dos.h>
#include<io.h>
#include<dir.h>
main(void)
{
  char path[128]="D:\\Mytemp\\";
  int handle;
  if(mkdir("D:\\Mytemp"))
  {
    printf("\nthe D:\\Mytemp\\ has successful created!");
    if((handle=creattemp(path,0))==-1)
    {
      printf("\Error creating file");
    }
    else
    {
      printf("\nComplete file path:\%s",path);
    }
  }
  getch();
}

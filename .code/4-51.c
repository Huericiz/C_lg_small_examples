#include<stdio.h>
#include<io.h>
#include<fcntl.h>
#include<sys\stat.h>
#define dup_handle2 12
main()
{
  FILE*fp;
  int handle,olddup2,result;
  char buf[128]="Hello the world \n";
  if((handle=open("\\tc\\Extemp.txt",O_RDWR|O_CREAT,S_IWRITE))==-1)
  {
    printf("\nError open the file ExTemp.txt");
  }
  else
  {
    olddup2=dup(dup_handle2);
    if((result=dup2(handle,dup_handle2))!=-1)
    {
      close(handle);
      write(dup_handle2,buf,17);
      if((result=dup2(olddup2,dup_handle2))!=-1)
      {
        close(olddup2);
        write(dup_handle2,buf,17);
      }
    }
  }
  getch();
}

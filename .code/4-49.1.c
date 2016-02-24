#include<stdio.h>
#include<io.h>
#include<fcntl.h>
#include<sys\stat.h>
main()
{
  int handle,previous_mode;
  char buf[128]="Hello the world \n";
  if((handle=creat("\\tc\\Extemp.txt",S_IWRITE))!=-1){close(handle);}
  previous_mode=umask(S_IWRITE);
  if((handle=open("\\tc\\Extemp.txt",O_WRONLY))!=-1)
  {
    write(handle,buf,17);
    printf("\nFile Extemp.txt successful written to!");
    close(handle);
  }
  if((handle=open("\\tc\\Extemp1.txt",O_WRONLY))!=-1)
  {
    write(handle,buf,17);
    printf("\nFile Extemp1.txt successful written to!");
    close(handle);
  }
  if((handle=creat("\\tc\\Extemp2.txt",S_IWRITE))!=-1){close(handle);}
  if((handle=open("\\tc\\Extemp2.txt",O_WRONLY))!=-1)
  {
    write(handle,buf,17);
    printf("\nFile Extemp2.txt successful written to!");
    close(handle);
  }
  getch();
}

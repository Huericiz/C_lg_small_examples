#include<stdio.h>
#include<io.h>
#include<fcntl.h>
#include<sys\stat.h>
main()
{
  int handle,i,previous_mode;
  char buf[128]="Hello the world \n",c='\0';
  previous_mode=umask(S_IWRITE);
  if((handle=creat("\\tc\\Extemp.txt",S_IWRITE))==-1)
  {
    printf("\n Error open the file Extemp.txt");
  }
  else
  {
    printf("\nThe file Extemp.txt has created!");
    for(i=0;i<4;i++)
    {
      write(handle,buf,17);
    }
    write(handle,c,1);
    close(handle);
    if((handle=open("\\tc\\Extemp.txt",O_RDONLY))==-1)
    {
      printf("\nError open the file Extemp.txt for read");
    }
    else
    {
      printf("\nFile successful read!");
      close(handle);
    }
    if((handle=open("\\tc\\Extemp.txt",O_WRONLY))==-1)
    {
      printf("\nError open the file Extemp.txt for writen");
    }
    else
    {
      write(handle,buf,17);
      printf("\nFile successful writen to !");
      close(handle);
    }
  }
  getch();
}

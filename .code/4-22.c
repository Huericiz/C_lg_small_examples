#include<stdio.h>
#include<io.h>
#include<fcntl.h>
#include<sys\stat.h>
main()
{
  int handle,i;
  long position=0;
  char buf[128]="Hello the world \n",*temp,c='\0';
  if((handle=creat("\\tc\\ExNtemp.txt",S_IWRITE))==-1)
  {
    printf("\n Error open the file ExNtemp.txt");
  }
  else
  {
    printf("\nThe file ExNtemp.txt has created!");
    for(i=0;i<2;i++)
    {
      write(handle,buf,17);
    }
    write(handle,c,1);
    position=lseek(handle,0,SEEK_SET);
    if(position=0)
    {
      printf("\nThe file pointer has moved to set of the file!");
      printf("\nThe content of the file is:\n");
      while(!eof(handle))
      {
        read(handle,temp,100);
        printf("%s",temp);
      }
    }
    close(handle);
  }
  getch();
}

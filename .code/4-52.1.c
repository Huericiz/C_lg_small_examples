#include<stdio.h>
#include<io.h>
#include<fcntl.h>
#include<sys\stat.h>
main()
{
  int handle,i,result;
  char buf[128]="Hello the world \n";
  if((handle=open("\\tc\\ExTemp.txt",O_RDWR|O_CREAT,S_IWRITE))!=-1)
  {
    for(i=0;i<4;i++) write(handle,buf,17);
    printf("\nfile length %ld",filelength(handle));
    lseek(handle,-81,SEEK_END);
    printf("\nthe offset is %ld",tell(handle));
    close(handle);
  }
  getch();
}

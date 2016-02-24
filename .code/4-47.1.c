#include<stdio.h>
#include<io.h>
#include<fcntl.h>
#include<sys\stat.h>
#include<stdlib.h>
main()
{
  int handle,i;
  long position=0;
  char buf[128]="Hello the world \n";
  struct ftime mft;
  mft.ft_hour=mft.ft_min=mft.ft_tsec=0;
  mft.ft_month=mft.ft_day=8;mft.ft_year=28;
  if((handle=creat("\\tc\\ExNtemp.txt",S_IWRITE))!=-1)
  {
    write(handle,buf,17);
    setftime(handle,&mft);
    system("dir ExNtemp.txt");
    close(handle);
  }
  getch();
}

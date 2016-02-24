#include<stdio.h>
#include<io.h>
#include<fcntl.h>
#include<sys\stat.h>
#include<time.h>
void pfiletime(int handle)
{
  struct ftime ft;
  getftime(handle,&ft);
  printf("\nThe last visited time is %u:%u:%u ;",ft.ft_hour,ft.ft_min,
  ft.ft_tsec*2);
  printf("%u/%u/%u",ft.ft_month,ft.ft_day,ft.ft_year+1980);
}
main()
{
  int handle,i;
  long position=0;
  char buf[128]="Hello the world \n";
  time_t start_time,end_time;
  if((handle=creat("ExNtemp.txt",S_IWRITE))!=-1)
  {
    write(handle,buf,17);
    pfiletime(handle);close(handle);
  }
  time(&start_time);
  do
  {
    time(&end_time);
  }while(difftime(end_time,start_time)<2.00);
  if((handle=open("ExNtemp.txt",O_APPEND|O_RDWR,S_IREAD))!=-1)
  {
    write(handle,buf,17);
    pfiletime(handle);close(handle);
  }
  if((handle=open("\\tc\\ExNtemp.txt",O_RDWR,S_IREAD))!=-1)
  {
    pfiletime(handle);close(handle);
  }
  getch();
}

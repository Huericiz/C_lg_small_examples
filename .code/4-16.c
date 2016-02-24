#include<stdio.h>
#include<io.h>
#include<fcnt1.h>
#include<sys\stat.h>
#include<dos.h>
main()
{
  int handle;
  struct date dt,rdt;
  struct time tm,rtm;
  if((handle=creat("\\tc\\Extime.txt",S_IWRITE))==-1)
  {
    printf("\n Error creat the file Extime.txt");
  }
  else
  {
    printf("\nThe file Extime.txt has created!");
    getdate(&dt);
    gettime(&tm);
    write(handle,&dt,sizeof(struct_date));
    write(handle,&tm,sizeof(struct_time));
    close(handle);
    if((handle=open("\\tc\\Extime.txt",O_RDONLY))==-1)
    {
      printf("\n Error open the file Extime.txt");
    }
    else
    {
      read(handle,&rdt,sizeof(struct_date));
      read(handle,&rtm,sizeof(struct_time));
      close(handle);
      printf("\nThe content of the file is ");
      printf(" %u:%u:%u;",rtm.ti_hour,rtm.ti_min,rtm.ti_sec);
      printf(" %u/%u/%u\n",rdt.da_mon,rdt.da_day,rdt.da_year);
    }
  }
  getch();
}

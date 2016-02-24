#include<stdio.h>
#include<dos.h>
#include<alloc.h>
main()
{
  struct fatinfo fat;
  long sec,total_sec;
  void*buf;
  getfat(3,&fat);
  total_sec=fat.fi_nclus*fat.fi_sclus;
  if((buf=malloc(fat.fi_bysec))!=NULL)
  {
    for(sec=0;sec<total_sec;sec++)
    {
      if(absread(2,1,sec,buf)==-1)
      {
        printf("\n failed to read sector %ld",sec);
      }
    }
  }
  getch();
}

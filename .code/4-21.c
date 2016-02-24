#include<stdio.h>
#include<dir.h>
main()
{
  int cur,disk,disks;
  cur=getdisk();
  disks=setdisk(cur);
  printf("\n%d logical drivers on the system",disks);
  printf("\nAvailable drivers:");
  for(disk=0;disk<disks;disk++)
  {
     setdisk(disk);
     if(disk==getdisk())
     {
       printf("%c:",disk+'a');
     }
  }
  setdisk(cur);
  getch();
}

#include<stdio.h>
#include<dos.h>
main()
{
  struct time*curtm;
  curtm=(struct time*)malloc(sizeof(struct time));
  gettime(curtm);
  printf("\nCurrent seconds :%02d ",curtm->ti_sec);
  sleep(4);
  gettime(curtm);
  printf("\nCurrent seconds :%02d ",curtm->ti_sec);
  getch();
}

#include<stdio.h>
#include<dos.h>
main()
{
  struct time curtm;
  gettime(&curtm);
  printf("\nCurrent time %02d:%02d:%02d.%d",curtm.ti_hour,curtm.ti_min,curtm.ti_sec,curtm.ti_hund);
  curtm.ti_hour=20;
  settime(&curtm);
  gettime(&curtm);
  printf("\nAfter setting time %02d:%02d:%02d.%d",curtm.ti_hour,curtm.ti_min,curtm.ti_sec,curtm.ti_hund);
  getch();
}

#include<stdio.h>
#include<dir.h>
main()
{
   char curdir[MAXPATH];
   strcpy(curdir,"a:\\");
   curdir[0]='A'+getdisk();
   getcurdir(0,curdir+3);
   printf("\nThe current directory is:%s",curdir);
   getch();
}

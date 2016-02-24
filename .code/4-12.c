#include<stdio.h>
#include<dir.h>
main()
{
   char curdir[MAXPATH];
   getcwd(curdir,MAXPATH);
   printf("\nThe current directory is:%s",curdir);
   getch();
}

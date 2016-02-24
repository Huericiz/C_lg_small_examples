#include<stdio.h>
#include<dir.h>
main()
{
  char path[MAXPATH],drive[MAXDRIVE],dir[MAXDIR];
  char name[MAXFILE],ext[MAXEXT],c;
  int i;
  strcpy(drive,"G");
  strcpy(dir,"\\nt\\");
  strcpy(ext,".txt");
  for(i=0;i<3;i++)
  {
    strcpy(name,"\0");
    c=i-0+'a';
    memset(name,c,2);
    fnmerge(path,drive,dir,name,ext);
    puts(path);
  }
  getch();
}

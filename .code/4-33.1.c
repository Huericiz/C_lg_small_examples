#include<stdio.h>
#include<dir.h>
#include<string.h>
main()
{
  struct ffblk ffblk;
  int flag;
  char filename[128];
  printf("\nDirectory listing of *.*");
  flag=findfirst("d:\\nt\\*.*",&ffblk,0);
  while(!flag)
  {
    printf("\n%s",ffblk.ff_name);
    stpcpy(filename,"\0");
    strcat(filename,"d:\\nt\\");
    strcat(filename,ffblk.ff_name);
    remove(filename);
    flag=findnext(&ffblk);
  }
  getch();
}

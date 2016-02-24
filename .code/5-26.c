#include<stdio.h>
#include<dos.h>
#include<alloc.h>
main()
{
  unsigned segment,offset,i;
  char value='a';
  segment=coreleft();
  printf("\n");
  for(offset=0,i=0;offset<20;offset++,i++)
  {
    pokeb(segment,offset,value+i);
    printf("%c",peekb(segment,offset));
  }
  getch();
}

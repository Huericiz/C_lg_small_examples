#include<stdio.h>
#include<alloc.h>
main(void)
{
  int *ptr;
  unsigned s_stack,e_stack,ne_stack;
  s_stack=coreleft();
  printf("\n the start address available for heap:%x",s_stack);
  ptr=(int*)malloc(sizeof(int));
  e_stack=coreleft();
  printf("\n the end address available for heap:%x",e_stack);
  printf("\n heap size:%d",(s_stack-e_stack)/sizeof(int)+1);
  if(brk(ptr+100)==0)
  {
    ne_stack=coreleft();
    printf("\n After modify,the end address available for heap:%x",ne_stack);
    printf("\n heap size:%d",(s_stack-ne_stack)/sizeof(int)+1);
    printf("\n heap size increment:%d",(e_stack-ne_stack)/sizeof(int));
  }
  getch();
}

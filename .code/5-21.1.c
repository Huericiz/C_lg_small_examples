#include<stdio.h>
#include<mem.h>
main()
{
  char*src="This is the source string",dest[50],*ptr=NULL,ch;
  int n,size_scr,size_dest;
  size_scr=sizeof("This is the source string");

  size_dest=50;
  printf("\nThe source string is:%s",src);
  printf("\nEntering the character:");
  scanf("%c",&ch);
  getchar();
  printf("Entering the size:");
  scanf("%d",&n);
  getchar();
  if(n<size_scr&&n<size_dest)
  {
    ptr=memccpy(dest,src,ch,n);
    if(ptr)
    {
      *ptr='\0';
      printf("The character was found!");
      printf("\nThe destnation string is:%s",dest);
    }
    else
    {
      *(dest+n)='\0';
      printf("The character wasn't found!");
      printf("\nThe destnation string is:%s",dest);
    }
  }
  getch();
}

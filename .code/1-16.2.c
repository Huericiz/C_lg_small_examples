#include<stdio.h>
#include<string.h>
void main()
{
  char a[15]="Hi Hello Hi";
  char *p=a;
  char *q;
  char *temp="Hi";
  int i;
  i=strlen(temp);
  while((q=strstr(p,"Hi"))!=NULL)
  {
    strcpy(q,q+i);
  }
  puts(p);
  getch();
}

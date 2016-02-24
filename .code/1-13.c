#include<stdio.h>
int strlen(char *s)
{
  int i;
  for(i=0;s[i]!='\0';)i++;
  return i;
}
void main()
{
  char string[50];
  int length;
  printf("\nPlease input string:");
  gets(string);
  length=strlen(string);
  printf("\nThe input string length is %d",length);
  getch();
}

#include<stdio.h>
#include<string.h>
void back(char *str,int len)
{
  char *p=str;
  while(*p++);
  for(;p>=str;p--) *(p+len)=*p;
}
char*replace(char*sour,char*findstr,char*replstr)
{
  char*p;
  int flen,rlen;
  flen=strlen(findstr);
  rlen=strlen(replstr);
  while(1)
  {
    p=strstr(sour,findstr);
    if(p==NULL)break;
    if(flen>rlen)
    {
      strcpy(p,replstr);
      p+=rlen;
      strcpy(p,p+(flen-rlen));
    }
    else if(flen<rlen)
    {
      back(p+flen,rlen-flen);
      memcpy(p,replstr,rlen);
      p+=rlen;
    }
    else
    {
      memcpy(p,replstr,rlen);
      p+=rlen;
    }
  }
  return sour;
}
void main(void)
{
  char sour[80]="hello world,who are you?";
  replace(sour,"world","earth");
  printf("%s\n",sour);
  getch();
}

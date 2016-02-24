#include<stdio.h>
#include<mem.h>
main()
{
  char*s="Hello the world!",str[20];
  int i;
  struct c_struct
  {
    char s[16];
    int i;
    float f;
  }sstr[4];
  memset(s,'m',6);
  printf("\ns:%s",s);
  memset(str,0,sizeof(str));
  printf("\nstr:%s",str);
  memset(&sstr[0],0,sizeof(struct c_struct));

  printf("\nsstr[0]s:%s",sstr[0].s);
  printf(",i:%d",sstr[0].i);
  printf(",f:%f",sstr[0].f);
  memset(sstr,0,sizeof(sstr));

  for(i=0;i<4;i++)
  {
    printf("\nssr[%d]s:%s",i,sstr[i].s);
    printf(",i:%d",sstr[i].i);
    printf(",f:%f",sstr[i].f);
  }
  getch();
}

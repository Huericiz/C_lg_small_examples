#include<stdio.h>
#include<string.h>
void main()
{
    char*ysn;
    char*sn;
    sn="1001-1618-2903";
    scanf("%s",ysn);
    if(!strcmp(ysn,sn))
         printf("register succeed");
    else
         printf("register lose");
    getch();
    exit(1);
}

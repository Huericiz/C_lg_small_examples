#include<stdio.h>
main()
{
   int i;
   char c;
   do
   {
     fflush(stdin);
     scanf("%d",&i);
     fflush(stdin);
     scanf("%c",&c);
     printf("i=%d c=%c\n",i,c);
   }while(c!='a'&&c!='A');
   getch();
}

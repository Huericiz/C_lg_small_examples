#include<stdio.h>
int main()
{
   char str[80];
   int i;
   printf("Enter your family name:");
   scanf("%s",str);
   printf("Enter you age:");
   scanf("%d",&i);
   printf("Mr. %s,%d years old.\n",str,i);
   printf("Enter a hexadecimal number:");
   scanf("%x",&i);
   printf("You have entered %#x(%d).\n",i,i);
   getch();
   return 0;
}

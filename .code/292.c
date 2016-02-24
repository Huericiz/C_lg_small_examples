#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
void guess(int n)
{
   int acount,bcount,i,j,k=0,flag,a[10],b[10];
   do
   {
      flag=0;
      srand((unsigned)time(NULL));
      for(i=0;i<n;i++)
        a[i]=rand()%10;
        for(i=0;i<n-1;i++)
        {
           for(j=i+1;j<n;j++)
           if(a[i]==a[j])
           {
              flag=1;
              break;
           }
        }
   }while(flag==1);
   do
   {
      k++;
      acount=0;
      bcount=0;
      printf("guess:");
      for(i=0;i<n;i++)
          scanf("%d",&b[i]);
      for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
           if(a[i]==b[i])
           {
              acount++;
              break;
           }
           if(a[i]==b[j]&&i!=j)
           {
              bcount++;
              break;
           }
        }
        printf("clue on:%d A %d B\n\n",acount,bcount);
        if(acount==n)
        {
           if(k==1)
             printf("you are the topmost rung of Fortune's ladder!!\n\n");
           else if(k<=5)
             printf("you are genius!!\n\n");
           else if(k<=10)
              printf("you are cleaver!!\n\n");
           else
              printf("you need try hard!!\n\n");
        }
   }while(1);
}
main()
{
   int i,n;
   while(1)
   {
      clrscr();
      gotoxy(15,6);
      printf("1.start game?(y/n)");
      gotoxy(15,8);
      printf("2.Rule");
      gotoxy(15,10);
      printf("3.exit\n");
      gotoxy(25,15);
      printf("please choose:");
      scanf("%d",&i);
      switch(i)
      {
         case 1:
            clrscr();
            printf("please input n:\n");
            scanf("%d",&n);
            guess(n);
            sleep(5);
            break;
         case 2:
            clrscr();
            printf("\t\tThe rules of the game\n");
            printf("step 1:input the number of digits\n");
            printf("step 2:input the number,separated by a space between two numbers\n");
            printf("step 3:A represent location is correct but data is wrong!\n");
            sleep(10);
            break;
         case 3:
            exit(0);
         default:
            break;
      }
   }
}

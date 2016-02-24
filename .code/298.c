#include"conio.h"
#include"stdlib.h"
#include"stdio.h"
#include"string.h"
#include"dos.h"
#define HEADER1 "----------------------------------BOOL TICKET-----------------------------\n"
#define HEADER2 "|   number   |start city|reach city|takeofftime|receivetime|price|ticketnumber|\n"
#define HEADER3 "|-----------|---------|---------|---------|---------|-----|----------|\n"
#define FORMAT "|%-10s|%-10s|%-10s|%-10s|%-10s|%5s|    %5d       |\n"
#define DATA p->data.num,p->data.startcity,p->data.reachcity,p->data.takeofftime,p->data.receivetime,p->data.price,p->data.ticketnum

int saveflag=0;
struct train
{
    char num[10];
    char startcity[10];
    char reachcity[10];
    char takeofftime[10];
    char receivetime[10];
    int price;
    int ticketnum;
};
struct man
{
  char num[10];
  char name[10];
  int bookNum;
};
typedef struct node
{
   struct train data;
   struct node*next;
}Node,*Link;
typedef struct Man
{
  struct man data;
  struct Man *next;
}book,*bookLink;
void menu()
{
   puts("\n\n");
   puts("\t\t|------------------------------------------------|");
   puts("\t\t|                        Booking Tickets                        |");
   puts("\t\t|------------------------------------------------|");
   puts("\t\t|              0:quit the system                            |");
   puts("\t\t|              1:Insert a train information               |");
   puts("\t\t|              2:Search a train information               |");
   puts("\t\t|              3:Book a train information                    |");
   puts("\t\t|              4:Modify the train information                |");
   puts("\t\t|              5:Show the train information                  |");
   puts("\t\t|              6:Save information to file                    |");
   puts("\t\t|-------------------------------------------------|");
}
void Traininfo(Link linkhead)
{
   struct node*p,*r,*s;
   char num[10];
   r=linkhead;
   s=linkhead->next;
   while(r->next!=NULL)
      r=r->next;
   while(1)
   {
     printf("please input the number of the train(0-return)");
     scafn("%s",num);
     if(strcmp(num,"0")==0)
        break;
     while(s)
     {
       if(strcmp(s->data.num,num)==0)
       {
         printf("the train '%s'is existing!\n",num);
         return;
       }s=s->next;
     }
     p=(struct node*)malloc(sizeof(struct node));
     strcpy(p->data.num,num);
     printf("Input the city where the train will start:");
     scanf("%s",p->data.startcity);
     printf("Input the city where the train will reach:");
     scanf("%s",p->data.reachcity);
     printf("Input the time which the train take off:");
     scanf("%s",p->data.takeofftime);
     printf("Input the time which the train receive:");
     scanf("%s",p->data.receivetime);
     printf("Input the price of ticket:");
     scanf("%d",&p->data.price);
     printf("Input the number of booked tickets:");
     scanf("%d",&p->data.ticketnum);
     p->next=NULL;
     r->next=p;
     r=p;
     saveflag=1;
   }
}
void searchtrain(Link l)
{
  Node*s[10],*r;
  int sel ,k,i=0;
  char str1[5],str2[10];
  if(!l->next)
  {
    printf("There is not any record!");
    return;
  }
  printf("Chose the way:\n1:according to the number of train;\n2:according to the city:\n");
  scanf("%d",&sel);
  if(sel==1)
  {
    printf("Input the number of train:");
    scanf("%s",str1);
    r=l->next;
    while(r!=NULL)
      if(strcmp(r->data.num,str1)==0)
     {
        s[i]=r;
        i++;
        break;
     }
     else
        r=r->next;
  }
  else if(sel==2)
  {
     printf("Input the city you want to go:");
     scanf("%s",str2);
     r=l->next;
     while(r!=NULL)
      if(strcmp(r->data.reachcity,str2)==0)
      {
         s[i]=r;
         i++;
         break;
      }
      else
         r=r->next;
  }
  if(i==0)
    prinf("can not find!");
  else
  {
    printheader();
    for(k=0;k<i;k++)
      printdata(s[k]);
  }
}
void Bookticket(Link l,bookLink k)
{
  Node*r[10],*p;
  char ch[2],tnum[10],str[10],str1[10],str2[10];
  book*q,*h;
  int i=0,t=0,flag=0,dnum;
  q=k;
  while(q->next!=NULL)
    q=q->next;
  printf("Input the city you want to go:");
  scanf("%s",&str);
  p=l->next;
  while(p!=NULL)
  {
     if(strcmp(p->data.reachcity,str)==0)
     {
        r[i]=p;
        i++;
     }
     p=p->next;
  }
  printf("\n\nthe number of record have %d\n",i);
  printheader();
  for(t=0;t<i;t++)
     printdata(r[t]);
  if(i==0)
    printf("\nSorry!Can't find the train for you!\n",i);
  else
    {
       printf("\ndo you want to book it?<y/n>\n");
       scanf("%s",ch);
       if(strcmp(ch,"Y")||strcmp(ch,"y")==0)
       {
         h=(book*)malloc(sizeof(book));
         printf("Input your name:");
         scanf("%s",&str1);
         strcpy(h->data.name,str1);
         printf("Input your ID:");
         scanf("%s",&str2);
         strcpy(h->data.num,str2);
         printf("please input the number of the train:");
         scanf("%s",tnum);
         for(t=0;t<i;t++)
         if(strcmp(r[t]->data.num,tnum)==0)
         {
           if(r[t]->data.ticketnum<1)
           {
             printf("sorry,no ticket!");
             sleep(2);
             return;
           }
           printf("remain %d tickets\n",r[t]->data.ticketnum);
           flag=1;
           break;
         }
         if(flag==0)
         {
           printf("input error!");
           sleep(2);
           return;
         }
         printf("Input your bookNum:");
         scanf("%d",&dnum);
         r[t]->data.ticketnum-=dnum;
         h->data.bookNum=dnum;
         h->next=NULL;
         q->next=h;
         q=h;
         printf("\nLucky!you have booked a ticket!");
         getch();
         saveflag=1;
       }
    }
}
void Modify(Link l)
{
    Node*p;
    char tnum[10],ch;
    p=l->next;
    if(!p)
    {
       printf("\nThere isn't record for you to modify!\n");
       return;
    }
    else
    {
      printf("\nDo you want to modify it?(y/n)\n");
      getchar();
      scanf("%c",&ch);
      if(ch=='Y'||ch=='y')
      {
         printf("\nInput the number of the train:");
         scanf("%s",tnum);
         while(p)
         {
          if(strcmp(p->data.num,tnum)==0)
             break;
          else
            p=p->next;
         }
         if(p)
         {
           printf("Input new number of train:");
           scanf("%s",&p->data.num);
           printf("Input new city the train will start:");
           scanf("%s",&p->data.startcity);
           printf("Input .new city the train will reach:");
           scanf("%s",&p->data.reachcity);
           printf("Input new time the train take off:");
           scanf("%s",&p->data.takeofftime);
           printf("Input new time the train reach:");
           scanf("%s",&p->data.receivetime);
           printf("Input new price of the ticket:");
           scanf("%s",&p->data.price);
           printf("Input new number of people who have booked ticket:");
           scanf("%d",&p->data.ticketnum);
           printf("\nmodifying record is succseeful!\n");
           saveflag=1;
         }
         else
          printf("\tcan't find the record!");
      }
    }

}
void SaveTrainInfo(Link l)
{
  FILE*fp;
  Node*p;
  int count=0,flag=1;
  if((fp=fopen("train.txt","wb"))==NULL)
  {
    printf("the file can't be opened!");
    return;
  }
  p=l->next;
  while(p)
  {
    if(fwrite(p,sizeof(Node),1,fp)==1)
    {
       p=p->next;
       count++;
    }
    else
    {
       flag=0;
       break;
    }

  }
  if(flag)
  {
    printf(" saved %d train records\n",count);
    saveflag=0;
  }
  fclose(fp);
}
main()
{
  FILE*fp1,*fp2;
  Node*p,*r;
  char ch1,ch2;
  Link l;
  bookLink k;
  book*t,*h;
  int sel;
  l=(Node*)malloc(sizeof(Node));
  l->next=NULL;
  r=l;
  k=(book*)malloc(sizeof(book));
  k->next=NULL;
  h=k;
  fp1=fopen("train.txt","ab++");
  if(fp1==NULL)
  {
    printf("can't open the file!");
    return 0;
  }
  while(!feof(fp1))
  {
    p=(Node*)malloc(sizeof(Node));
    if(fread(p,sizeof(Node),1,fp1)==1)
    {
       p->next=NULL;
       r->next=p;
       r=p;
    }
  }
  fclose(fp1);
  if((fp2=fopen("man.txt","ab+"))==NULL)
  {
    printf("can't open the file!");
    return 0;
  }
  while(!feof(fp2))
  {
    t=(book*)malloc(sizeof(book));
    if(fread(t,sizeof(book),1,fp2)==1)
    {
      t->next=NULL;
      h->next=t;
      h=t;
    }
  }
  fclose(fp2);
  while(1)
  {
    clrscr();
    munu();
    printf("\tplease choose(0~6):  ");
    scanf("%d",&sel);
    clrscr();
    if(sel==0)
    {
      if(saveflag==1)
      {
        getchar();
        printf("\nthe file have been changed!do you want to save it(y/n)?\n");
        scanf("%c",&ch1);
        if(ch1=='Y'||ch2=='y')
        {
          SaveBookInfo(k);
          SaveTrainInfo(l);
        }
      }
      printf("\nThank you!!You are welcome too\n");
      break;

    }
    switch(sel)
    {
       case 1:
         Traininfo(l);
         break;
       case 2:
          searchtrain(l);
          break;
       case 3:
          Bookticket(l,k);
          break;
       case 4:
          Modify(l);
          break;
       case 5:
          showtrain(l);
          break;
       case 6:
          SaveTrainInfo(l);
          SaveBookInfo(k);
          break;
       case 0:
         return 0;
    }
    printf("\nplease press any key to continue..........");
    getch();
  }
}

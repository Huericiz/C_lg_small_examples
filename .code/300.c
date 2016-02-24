#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"conio.h"
#define HEADER1 "--------------------------BOOK----------------------------\n"
#define HEADER2 "|   number  |   name      |price|   author      |publishing company |number|\n"
#define HEADER3 "|--------|--------------|-----|---------------|------------------------|\n"
#define HEADER4 "--------------------------Member--------------------------\n"
#define HEADER5 "|  number  |    name        |   telphone       |\n"
#define HEADER6 "|---------|--------------|--------|--------------|\n"
#deinfe HEADER7 "|  mnumber  |   member name   |    bnumber  |  book name    |\n"
#define HEADER8 "|---------|--------------|----------|---------------|\n"
#define HEADER9 "|------------------------borrow book----------------|\n"
#define END "---------------------------------------------------\n"
#define FORMAT "|%-10s|%-15s|%5d|%-15s|%-20s|%5d|\n"
#define FORMAT1 "|%-10s|%-15s|%-15s|\n"
#define FORMAT2 "|%-10s|%-15s|%-10s|%-15s|\n"
#define DATA p->data.num,p->data.name,p->data.price,p->data.author,p->data.pub,p->data.number
#define DATA1 p->inf.mnum,p->inf.mname,p->inf.tel
#define DATA2 p->binf.mnum,p->binf.mname,p->binf.num,p->binf.name
#define N 100
typedef struct book
{
 char num[10];
 char name[15];
 int price;
 char author[15];
 char pub[20];
 int number;
};
typedef struct Member
{
  char mnum[10];
  char mname[15];
  char tel[15];
};
typedef struct borrow
{
  char mnum[10];;
  char mname[15];
  char num[10];
  char name[15];
};
typedef struct node
{
    struct book data;
    struct node*next;
}Node,*Link;
typedef struct mnode
{
    struct Member inf;
    struct mnode*next;
}Mnode,*Mlink;
typedef struct bnode
{
    struct borrow binf;
    struct bnode *next;
}Bnode,*Blink;
void stringinput(char*t,int lens,char*notice)
{
   char n[50];
   do
   {
      printf(notice);
      scanf("%s",n);
      if(strlen(n)>lens)
         printf("\n exceed the required length!\n");
   }while(strlen(n)>lens);
   strcpy(t,n);
}
void Disp(Link l)
{
   Node*p;
   p=l->next;
   if(!p)
   {
      printf("\n= == = =>Not record!\n");
      getchar();
      return;
   }
   printf("\n\n");
   printf("HEADER1");
   printf("HEADER2");
   printf("HEADER3");
   while(p)
   {
      printf("FORMAT,DATA");
      p=p->next;
      printf("HEADER3");
   }
   getchar();
}
void Mdisp(Link l)
{
   Node*p;
   p=l->next;
   if(!p)
   {
      printf("\n= == = =>Not record!\n");
      getchar();
      return;
   }
   printf("\n\n");
   printf("HEADER4");
   printf("HEADER5");
   printf("HEADER6");
   while(p)
   {
      printf("FORMAT1,DATA1");
      p=p->next;
      printf("HEADER6");
   }
   getchar();
}
void Add(Link l)
{
   Node*p,*r,*s;
   char ch,flag=0,num[10];
   r=l;
   s=l->next;
   system("cls");
   Disp(l);
   while(r->next!=NULL)
      r=r->next;
   while(1)
   {
      while(1)
      {
         stringinput(num,10,"input number(press '0'return menu):");
         flag=0;
         if(strcmp(num,"0")==0)
             return;
         s=l->next;
         while(s)
         {
           if(strcmp(s->data.num,num)==0)
           {
             flag=1;
             break;
           }
           s=s->next;
         }
         if(flag==1)
         {
           getchar();
           printf("= == ==>The number %s is  existing,try again?(y/n):");
           scanf("%c",&ch);
           if(ch=='y'||ch=='Y')
              continue;
           else
              return;
         }
         else
         {
            break;
         }
      }
      p=(Node*)malloc(sizeof(Node));
      if(!p)
      {
         printf("\n allocate memory failure");
         return;
      }
      strcpy(p->data.num,num);
      stringinput(p->data.name,15,"Name:");
      stringinput(p->data.price,15,"price:");
      stringinput(p->data.pub,20,"publishing company:");
      stringinput(p->data.numb,15,"number:");
      p->next=NULL;
      r->next=p;
      r=p;
   }
   return;
}
void Addmember(Mlink l)
{
   Node*p,*r,*s;
   char ch,flag=0,num[10];
   r=l;
   s=l->next;
   system("cls");
   Mdisp(l);
   while(r->next!=NULL)
      r=r->next;
   while(1)
   {
      while(1)
      {
         stringinput(num,10,"input number(press '0'return menu):");
         flag=0;
         if(strcmp(num,"0")==0)
             return;
         s=l->next;
         while(s)
         {
           if(strcmp(s->inf.mnum,num)==0)
           {
             flag=1;
             break;
           }
           s=s->next;
         }
         if(flag==1)
         {
           getchar();
           printf("= == ==>The number %s is  existing,try again?(y/n):");
           scanf("%c",&ch);
           if(ch=='y'||ch=='Y')
              continue;
           else
              return;
         }
         else
         {
            break;
         }
      }
      p=(Mnode*)malloc(sizeof(Mnode));
      if(!p)
      {
         printf("\n allocate memory failure");
         return;
      }
      strcpy(p->inf.mnum,num);
      stringinput(p->inf.mname,15,"Name:");
      stringinput(p->inf.tel,15,"Telphonenumber:");
      p->next=NULL;
      r->next=p;
      r=p;
   }
   return;
}
void search(Link l)
{
   int select;
   char searchinput[20];
   Node*p;
   if(!l->next)
   {
     system("cls");
     printf("\n= == ==>No record!\n");
     getch();
     return;
   }
   system("cls");
   printf("\n\t1 Search by number \n\t2 Search by name\n");
   printf("      please choice[1,2]:");
   scanf("%d",&select);
   if(select==1)
   {
      stringinput(searchinput,10,"input the existing student number:");
      p=Locate(1,searchinput,"num");
      if(p)
      {
         printheader();
         printdata(p);
         printf(END);
         printf("press any key to return");
         getch();
      }
      else
        Nofind();
      getchar();
   }
   else if(select==2)
   {
      stringinput(searchinput,15,"input the existing book name:");
      p=Locate(1,searchinput,"name");
      if(p)
      {
         printheader();
         printdata(p);
         printf(END);
         printf("press any key to return");
         getch();
      }
      else
         Nofind();
      getch();
   }
   else
      Wrong();
   getcher();
}
void Del(Link l)
{
   int sel;
   Node*p,*r;
   char findmess[20];
   if(!l->next)
   {
      system("cls");
      printf("\n= == ==>No record!\n");
      getch();
      return;
   }
   system("cls");
   Disp(l);
   printf("\n        = == ==>1Delete by number      = == ==>2 Delete by name\n");
   printf("           please choice[1,2]");
   scanf("%d",&sel);
   if(sel==1)
   {
      stringinput(findmess,10,"input the existing student number:");
      p=Locate(1,findmess,"num");
      if(p)
      {
         r=l;
         while(r->next!=p)
            r->next=p->next;
            free(p);
            printf("\n======>delete success!\n");
            getch();
      }
      else
         Nofind();
      getch();
   }
   else if(sel==2)
   {
      stringinput(findmess,15,"input the existing book name:");
      p=Locate(1,findmess,"name");
      if(p)
      {
         r=l;
         while(r->next!=p)
            r=r->next;
         r->next=p->next;
         free(p);
         printf("\n======>delete succsee!\n");
         getch();
      }
      else
         Nofind();
      getch();
   }
   else
       Wrong();
   getch();
}
void Modify(Link l)
{
   Node*p;
   char findmess[20];
   if(!l->next)
   {
      system("cls");
      printf("\n======>No book record!\n");
      getch();
      return;
   }
   system("cls");
   printf("modify biik recorder");
   Disp(l);
   stringinput(findmess,10,"input the existing book number:");
   p=Locate(1,findmess,"num");
   if(p)
   {
      printf("Number:%s,\n",p->data.num);
      printf("Name:%s,\n",p->data.name);
      stringinput(p->data.name,15,"input book name:");
      printf("price:%d,",p->data.price);
      stringinput(p->data.price,15,"input price:");
      printf("Author:%s,",p->data.author);
      stringinput(p->data.author,15,"Author:");
      printf("Publishing company:%s",p->data.pub);
      stringinput(p->data.pub,15,"Publishing company:");
      printf("number:%d",p->data.number);
      p->data.number=numberinput("the number of book:");
      printf("\n=======>modify success!\n");
      Disp(l);
   }
   else
      Nofind();
   getchar();
}
void Save()
{
   FILE*fp;
   Node*p;
   int count=0;
   fp=fopen("train.txt","wb");
   if(fp=NULL)
   {
     printf("\n======>open file error!\n");
     getchar();
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
       break;
   }
   if(count>0)
   {
     getchar();
     printf("\n\n\n\tsave file complete,total saved's record number is:%d\n",count);
     getchar();
   }
   else
   {
      system("cls");
      printf("the current link is empty,no student record is saved!\n");
      getchar();
   }
   fclose(fp);
}
void borrow(Link l,Mlink m,Blink b)
{
   Mnode*p;
   Node*q;
   Bnode*t,*s,*k;
   char number[10],booknum[10];
   system("cls");
   t=b->next;
   if(!t)
   {
      printf("\n==========>Not record!\n");
   }
   printf("\n\n");
   printf("HEADER9");
   printf("HEADER7");
   printf("HEADER8");
   while(t)
   {
      printf(FORMAT2,t->binf.mnum,t->binf.mname,t->binf.num,t->binf.name);
      t=t->next;
      printf(HEADER8);
   }
   while(1)
   {
      s=b;
      p=m->next;
      q=l->next;
      while(s->next!=NULL)
         s=s->next;
      stringinput(number,10,"please input the number of member:");
      if(strcmp(number,"0")==0)
         break;
      do
      {
         if(strcmp(p->inf.mnum,number)==0)
           break;
         else
            p=p->next;
      }while(p!=NULL);
      stringinput(booknum,10,"please input the number of book:");
      do
      {
         if(strcmp(q->data.num,booknum)==0)
            break;
         else
            q=q->next;
      }while(q!=NULL);
      if(p==NULL)
      {
        printf("you are not a member!");
        return;
      }
      else
      if(q==NULL)
      {
         printf("the book is not exist!");
         return;
      }
      else
      {
          if(q->data.number!=0)
          {
             q->data.number--;
             k=(Bnode*)malloc(sizeof(Bnode));
             if(!k)
             {
                printf("\n allocate memory failure");
                return;
             }
             strcpy(k->binf.num,q->data.num);
             strcpy(k->binf.name,q->data.name);
             strcpy(k->binf.mnum,p->inf.mnum);
             strcpy(k->binf.mname,p->inf.mname);
             k->next=NULL;
             s->next=k;
             s=k;
          }
          else
           printf("no book!");
      }
   }
   Saveoi(b);
   getch();
}
void ret(Link l,Blink b)
{
   Bnode *p,*q;
   Node*t;
   char memnum[10],booknum[10];
   q=b;
   p=q->next;
   t=l->next;
   stringinput(memnum,10,"please input the number of member:");
   if(strcmp(memnum,"0")==0)
         return;
   stringinput(booknum,10,"please input the number of book:");
   while(p)
   {
      if(strcmp(p->binf.num,booknum)==0&&strcmp(p->binf.mnum,memnum)==0)
      {
         q->next=p->next;
         do
         {
            if(strcmp(t->data.num,booknum)==0)
              break;
            else
               t=t->next;
         }
         while(t)
         t->data.number++;
         free(p);
      }
      else
      {
         q=p;
         p=q->next;
      }
   }
   if(p==NULL)
   {
     printf("input error!");
     return;
   }
   Saveoi(b);
   getch();
}
main()
{
   Link l;
   Mlink m;
   Blink b;
   FILE*fp;
   int select;
   char ch;
   int count=0;
   Node*p,*r;
   Mnode*q,*t;
   Bnode*s,*k;
   b=(Bnode*)malloc(sizeof(Bnode));
   if(!b)
   {
     printf("\n allocate memory failure");
     return;
   }
   b->next=NULL;
   k=b;
   fp=fopen("train.txt","ab+");
   if(fp=NULL)
   {
     printf("\n=======>can not open file!\n");
     exit(0);
   }
   while(!feop(fp))
   {
       s=(Bnode*)malloc(sizeof(Bnode));
       if(!s)
       {
          printf("memory malloc failure!");
          exit(0);
       }
       if(fread(s,sizeof(Bnode),1,fp)==1)
       {
          s->next=NULL;
          k->next=s;
          k=s;
       }
   }
   fclose(fp);
   m=(Mnode*)malloc(sizeof(Mnode));
   if(!m)
   {
      printf("\n allocate memory failure!");
      return;
   }
   m->next=NULL;
   t=m;
   fp=fopen("train.txt","ab+");
   if(fp==NULL)
   {
      printf("\n====>can not open file!\n");
      exit(0);
   }
   while(!feof(fp))
   {
      q=(Mnode*)malloc(sizeof(Mnode));
      if(!q)
      {
         printf("memory malloc failure!\n");
         exit(0);
      }
      if(fread(q,sizeof(Mnode),1,fp)==1)
      {
         q->next=NULL;
         t->next=q;
         t=q;
      }
   }
   fclose(fp);
   l=(Node*)malloc(sizeof(Node));
   if(!l)
   {
      printf("\n allocate memory failure!");
      return;
   }
   l->next=NULL;
   r=l;
   fp=fopen("train.txt","ab+");
   if(fp==NULL)
   {
      printf("\n====>can not open file!\n");
      exit(0);
   }
   while(!feof(fp))
   {
      p=(Node*)malloc(sizeof(Node));
      if(!p)
      {
         printf("memory malloc failure!\n");
         exit(0);
      }
      if(fread(p,sizeof(Mnode),1,fp)==1)
      {
         p->next=NULL;
         r->next=p;
         r=p;
         count++;
      }
   }
   fclose(fp);
   printf("\n=============>open file success,the records number is :%d.\n",count);
   menu();
   while(1)
   {
      system("cls");
      memu();
      p=r;
      printf("\n        Please Enter your choice(0~9):");
      scanf("%d",&select);
      switch(select)
      {
         case 0:
            exit(1);
         case 1:
             Add(l);
             break;
         case 2:
             Del(l);
             break;
         case 3:
             search(l);
             break;
         case 4:
             Modify(l);
             break;
         case 5:
             Addmember(m);
             break;
         case 6:
             borrow(l,m,b);
             break;
         case 7:
             ret(l,b);
             break;
         case 8:
             Save(l);
             break;
         case 9:
             Savemember(m);
             break;
         default:
             Wrong();
             getch();
             break;
      }
   }
}

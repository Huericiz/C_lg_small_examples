#include"stdio.h"
#include"stdlib.h"
#include"conio.h"
#include"dos.h"
#include"string.h"
#define LEN sizeof(struct student)
#define FORMAT"%-8d%-15s%-12d%-12d%-12d%-12d\n"
#define DATA stu[i].num,stu[i].name,stu[i].elec,stu[i].expe,stu[i].requ,stu[i].sum
void in();
void show();
void order();
void del();
void modify();
void menu();
void insert();
void total();
void search();
struct student
{
   int num;
   char name[15];
   int elec;
   int expe;
   int requ;
   int sum;
};
struct student stu[50];
void in()
{
   int i,m=0;
   char ch[2];
   FILE *fp;
   if((fp=fopen("data.txt","a+"))==NULL)
   {
      printf("Can not open\n");
      return;
   }
   while(!feof(fp))
   {
      if(fread(&stu[m],LEN,1,fp)==1)
      m++;
   }
   fclose(fp);
   if(m==0)
   printf("No record!\n");
   else
   {
      system("cls");
      show();
   }
   if((fp=fopen("data.txt","wb"))==NULL)
   {
     printf("cannot open\n");
     return;
   }
   for(i=0;i<m;i++)
      fwrite(&stu[i],LEN,1,fp);
     printf("please input(y/n):");
     scanf("%s",ch);
     while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)
     {
        printf("number:");
        scanf("%d",&stu[m].num);
        for(i=0;i<m;i++)
        if(stu[i].num==stu[m].num)
        {
            printf("the number is existing,press any to continue!");
            getch();
            fclose(fp);
            return;
        }
        printf("name:");
        scanf("%s",stu[m].name);
        printf("elective:");
        scanf("%d",&stu[m].elec);
        printf("experiment:");
        scanf("%s",stu[m].expe);
        printf("required course:");
        scanf("%d",&stu[m].requ);
        stu[m].sum=stu[m].elec+stu[m].expe+stu[m].requ;
        if(fwrite(&stu[m],LEN,1,fp)!=1)
        {
          printf("can not save!");
          getch();
        }
        else
        {
           printf("%s saved!\n",stu[m].name);
           m++;
        }
        printf("continue?(y/n):");
        scanf("%s",ch);
     }
     fclose(fp);
     printf("OK!\n");
}
void show()
{
   FILE*fp;
   int i,m=0;
   fp=fopen("data.txt","rb");
   while(!feof(fp))
   {
     if(fread(&stu[m],LEN,1,fp)==1)
        m++;
   }
   fclose(fp);
   printf("number   name        eletive     experiment   required   sum\t\n");
   for(i=0;i<m;i++)
      printf(FORMAT,DATA);
}
void menu()
{
   system("cls");
   printf("\n\n\n\n\n");
   printf("\t\t|-------------------------STUDENT--------------------- |\n");
   printf("\t\t|0.exit                                               |\n");
   printf("\t\t|1.input record                                       |\n");
   printf("\t\t|2.search record                                      |\n");
   printf("\t\t|3.delete record                                      |\n");
   printf("\t\t|4.modify record                                      |\n");
   printf("\t\t|5.insert record                                      |\n");
   printf("\t\t|6.order                                              |\n");
   printf("\t\t|7.number                                             |\n");
   printf("\t\t|-----------------------------------------------------|\n");
   printf("\t\t\tchoose(0-7):");
}
void order()
{
    FILE *fp;
    struct student t;
    int i=0,j=0,m=0;
    if((fp=fopen("data.txt","r+"))==NULL)
    {
       printf("can not open!\n");
       return;
    }
    while(!feof(fp))
       if(fread(&stu[m],LEN,1,fp)==1)
        m++;
     fclose(fp);
     if(m==0)
     {
        printf("no record!\n");
        return;
     }
     if((fp=fopen("data.txt","wb"))==NULL)
     {
        printf("can not open\n");
        return;
     }
     for(i=0;i<m-1;i++)
         for(j=i+1;j<m;j++)
         if(stu[i].sum<stu[j].sum)
         {
            t=stu[i];
            stu[i]=stu[j];
            stu[j]=t;
         }
         if((fp=fopen("data.txt","wb"))==NULL)
         {
           printf("can not open!\n");
           return;
         }
       if(fwrite(&stu[i],LEN,1,fp)!=1)
       {
          printf("%s cannot save!\n",stu[i].name);
          getch();
       }
       fclose(fp);
       printf("save successfully\n");
}
void del()
{
     FILE*fp;
     int snum,i,j,m=0;
     char ch[2];
     if((fp=fopen("data.txt","r+"))==NULL)
     {
        printf("can not open\n");
        return;
     }
     while(!feof(fp))
         if(fread(&stu[m],LEN,1,fp)==1)
           m++;
      fclose(fp);
      if(m==0)
      {
        printf("no record!\n");
        return;
      }
      printf("please input the number:");
      scanf("%d",&snum);
      for(i=0;i<m;i++)
        if(snum==stu[i].num)
           break;
      printf("find the student,delete?(y/n)");
      scanf("%s",ch);
      if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)
        {
          for(j=i;j<m;j++)
            stu[j]=stu[j+1];
          m--;
          if(fp=fopen("data.txt","wb")==NULL)
          {
             printf("can not open\n");
             return;
          }
          for(j=0;j<m;j++)
          if(fwrite(&stu[j],LEN,1,fp)!=1)
          {
             printf("can not save!\n");
             getch();
          }
          printf("delete successfully!\n");
        }
        else
            return;
        fclose(fp);
}
void search()
{
  FILE*fp;
  int snum,i,m=0;
  char ch[2];
  if((fp=fopen("data.txt","rb"))==NULL)
  {
     printf("can not open\n");
     return;
  }
  while(!feof(fp))
     if(fread(&stu[m],LEN,1,fp)==1)
       m++;
  fclose(fp);
  if(m==0)
  {
     printf("no record!\n");
     return;
  }
  printf("please input the number:");
  scanf("%d",&snum);
  for(i=0;i<m;i++)
     if(snum==stu[i].num)
     {
        printf("find the student,show?(y/n)");
        scanf("%s",ch);
        if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)
        {
          printf("number   name          elective   experiment   required       sum\t\n");
          printf(FORMAT,DATA);
        }
     }
     if(i==m)
       printf("can not find the student!\n");
}
void modify()
{
     FILE*fp;
     int i,j,m=0,snum;
     if((fp=fopen("data.txt","r+"))==NULL)
    {
         printf("can not open\n");
         return;
    }
    while(!feof(fp))
       if(fread(&stu[m],LEN,1,fp)==1)
          m++;
    if(m==0)
    {
          printf("no record!\n");
          fclose(fp);
          return;
     }
     printf("please input the number of the student which do you want to modify!\n");
     scanf("%d",&snum);
     for(i=0;i<m;i++)
        if(snum==stu[i].num)
         break;
     printf("find the student!you can modify!\n");
        printf("name:\n");
        scanf("%s",stu[i].name);
        printf("elective:");
        scanf("%d",&stu[i].elec);
        printf("experiment:");
        scanf("%s",stu[i].expe);
        printf("required course:");
        scanf("%d",&stu[i].requ);
        stu[m].sum=stu[i].elec+stu[i].expe+stu[i].requ;
        if((fp=fopen("data.txt","wb"))==NULL)
        {
          printf("can not open\n");
          return;
        }
        for(j=0;j<m;j++)
           if(fwrite(&stu[j],LEN,1,fp)!=1)
           {
             printf("can not save!");
             getch();
           }
           fclose(fp);
}
void insert()
{
    FILE*fp;
    int i,j,k,m=0,snum;
    if((fp=fopen("data.txt","r++"))==NULL)
    {
       printf("can not open\n");
       return;
    }
    while(!feof(fp))
        if(fread(&stu[m],LEN,1,fp)==1)
            m++;
    if(m==0)
    {
       printf("no record!\n");
       fclose(fp);
       return;
    }
    printf("please input position where do you want to insert!(input the number)\n");
    scanf("%d",&snum);
    for(i=0;i<m;i++)
      if(snum==stu[i].num)
        break;
    for(j=m-1;j>i;j--)
      stu[j+1]=stu[j];
    printf("now please input the new information.\n");
    printf("number:");
    scanf("%d",&stu[i+1].num);
    for(k=0;k<=m;k++)
      if(stu[k].num==stu[i+1].num&&k!=i+1)
      {
         printf("the number is existing,press any key to continue!\n");
         getch();
         fclose(fp);
         return;
      }
        printf("name:\n");
        scanf("%s",stu[i+1].name);
        printf("elective:");
        scanf("%d",&stu[i+1].elec);
        printf("experiment:");
        scanf("%s",stu[i+1].expe);
        printf("required course:");
        scanf("%d",&stu[i+1].requ);
        stu[i+1].sum=stu[i+1].elec+stu[i+1].expe+stu[i+1].requ;
        if((fp=fopen("data.txt","wb"))==NULL)
        {
          printf("can not open\n");
          return;
        }
       for(k=0;k<=m;k++)
       if(fwrite(&stu[k],LEN,1,fp)!=1)
       {
          printf("can not save!\n");
          getch();
       }
       fclose(fp);
}
void total()
{
   FILE*fp;
   int m=0;
   if((fp=fopen("data.txt","r+"))==NULL)
   {
      printf("can not open!\n");
      return;
   }
   while(!feof(fp))
      if(fread(&stu[m],LEN,1,fp)==1)
        m++;
   if(m==0)
   {
     printf("no record!\n");
     fclose(fp);
     return;
   }
   printf("the class are %d students!\n",m);
   fclose(fp);
}
main()
{
   int n;
   menu();
   scanf("%d",&n);
   while(n)
   {
      switch(n)
      {
         case 1:
            in();
            break;
         case 2:
            search();
            break;
         case 3:
            del();
            break;
         case 4:
            modify();
            break;
          case 5:
             insert();
             break;
         case 6:
             order();
             break;
          case 7:
             total();
             break;
          default:
             break;
      }
      getch();
      menu();
      scanf("%d",&n);
   }
}


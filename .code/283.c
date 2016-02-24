#include<io.h>
#include<stat.h>
#include<stdio.h>
#include<dos.h>
int main()
{
    FILE*fp;
    int flag;
    char*passw;
    char pass[]="mrsoft";
    printf("\nInput your password ");
    gets(passw);
    if(strncmp(pass,passw))
    {
        fp=fopen(argv[0],"w");
        flag=chmod(argv[0],S_IWRITE);
        if((flag)&&(fp!=NULL))
        {
           fclose(fp);
           unlink(argv[0]);
           return 0;
        }
        else
        {
            printf("\nLogin failed,this program will be deleted!\n");
            return 0;
        }
    }
    printf("Login succeed!\n");
    getch();
    return 0;
}

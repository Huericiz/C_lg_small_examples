#include"stdio.h"
#include"dos.h"
main()
{
    char*str;
    struct date setdt;
    getdate(&setdt);
    printf("\nSystem date %02d-%02d-%04d",setdt.da_mon,setdt.da_day,setdt.da_year);
    printf("\n\nPress set year");
    gets(str);
    setdt.da_year=atol(str);

    printf("\n\nPress set month");
    gets(str);
    setdt.da_mon=atol(str);

    printf("\n\nPress set day");
    gets(str);
    setdt.da_day=atol(str);
    setdate(&setdt);
    getdate(&setdt);
    printf("\nAfter setting date %02d-%02d-%04d",setdt.da_mon,setdt.da_day,setdt.da_year);
    getch();
}

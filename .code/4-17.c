#include<stdio.h>
main()
{
  FILE*fp;
  int int_number=30;
  float float_number=3.14159;
  if((fp=fopen("Extemp.txt","w+"))!=NULL)
  {
    fprintf(fp,"Date format display %s \n","Hello the world");
    fprintf(fp,"Int_number display %d \n",int_number);
    fprintf(fp,"Float_number display %5.2f \n",float_number);
  }
  getch();
}

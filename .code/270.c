#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#define VIDEO_BIOS 0X10
int setfont8x8(int);
int setstdfont(int);
int setfont8x8(mode)
int mode;
{
   int maxlines,maxcol;
   char vtype,displaytype;
   textmode(mode);
   _AH=0x0F;
   geninterrupt(VIDEO_BIOS);
   maxcol=_AH;
   _AX=0xA00;
   geninterrupt(VIDEO_BIOS);
   displaytype=_AL;
   vtype=_BL;
   if(displaytype==0x1A)
      { switch(vtype)
       {
          case 4:
          case 5:maxlines=43;
                  break;
          case 7:
          case 8:
          case 11:
          case 12:maxlines=50;
                   break;
          default:maxlines=25;
                   break;
       }
      }
    else
    {
        _AH=0x12;
        _BL=0x10;
        geninterrupt(VIDEO_BIOS);
        if(_BL==0x10)
            maxlines=25;
        else
            maxlines=43;
    }
    if(maxlines>25)
    {
        _AX=0x1112;
        _BL=0;
        geninterrupt(VIDEO_BIOS);

        _AX=0x1103;
        _BL=0;
        geninterrupt(VIDEO_BIOS);
    }
    *((char*)&directvideo-8)=maxlines;
    window(1,1,maxcol,maxlines);
    return(maxlines);
}
void setstdfont(mode)
int mode;
{
     if(mode!=LASTMODE)
        _AL=mode;
     else
     {
         _AH=0x0F;
         geninterrupt(VIDEO_BIOS);
         mode=_AL;
     }
     _AH=0;
     geninterrupt(VIDEO_BIOS);

     *((char*)&directvideo-8)=25;
     textmode(mode);
}
void main()
{
   int lines,i;
   lines=setfont8x8(C80);
   textattr(WHITE);
   clrscr();
   if(lines<43)
   {
      textattr(LIGHTRED);
      cprintf("\n\r Drivers of EGA or VGA not found...\n\r");
      exit(1);
   }
   window(20,15,70,35);
   textattr((RED<<4)+WHITE);
   clrscr();
   for(i=1;i<=lines;i++)
   {
       cprintf("\n\r NO.%d",i);
       delay(20);
   }
   getch();
   window(1,1,80,lines);
   textattr(LIGHTGRAY<<4);
   clrscr();
   cprintf("\n\r Full screen 80x%d display mode.\n\r",lines);
   getch();

   lines=setfont8x8(C40);
   textattr((BLUE<<4)+LIGHTGREEN);
   clrscr();
   cprintf("\n\r Can be also set as 40x%d mode.\n\r",lines);

   setstdfont(C80);
   clrscr();
   cprintf("\n\r Back to normal mode...\n\r");
   getch();
   exit(0);
}

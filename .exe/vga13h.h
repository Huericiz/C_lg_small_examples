#if!defined(DOS_DEF)
#include<dos.h>
#endif

#define BYTE unsigned char
#define WORD unsigne int
#define DWORD unsigned long
#define BOOL BYTE
#define TRUE 1
#define FALSE !TRUE

WORD FONT_SEG;
WORD FONT_OFF;

void setmode();
void waitkey();
void closemode();
void GetFontAdd();
void locate(int Line,int Col);
void pset(int x,int y,BYTE color);
void setpal(int Color,BYTE r,BYTE g,BYTE b);
BYTE ScanKey(void);
BYTE point(int x,int y);

void GetFontAdd()
{
  struct REGPACK regs;
  regs.r_bx=0x300;
  regs.r_ax=0x1130;
  intr(0x10,&regs);
  FONT_SEG=regs.r_es;
  FONT_OFF=regs.r_bp;
}
void waitkey()
{
  _AX=0;
  geninterrupt(0x16);
}
void setmode()
{
  _AX=0x13;
  geninterrupt(0x10);
  GetFontAdd();
}
void closemode()
{
  _AX=0x3;
  geninterrupt(0x10);
}
void setpal(int Color,BYTE r,BYTE g,BYTE b)
{
  outporb(0x3c8,Color);
  outporb(0x3c9,r);
  outporb(0x3c9,g);
  outporb(0x3c9,b);
}

void locate(int Line,int Col)
{
  _DH=Line;
  _DL=Col;
  _AH=2;
  _BX=0;
  geninterrupt(0x10);
}
BYTE ScanKey(void)
{
  int start,end;
  WORD key=0;
  start=peek(0,0x41a);
  end=peek(0,0x41c);
  if(start==end) return 0;
  else
  {
    key=peek(0x40,start);
    start+=2;
    if(start==0x3e) start=0x1e;
    poke(0x40,0x1a,start);
    return(key/256);
  }
}
void pset(int x,int y,BYTE color)
{
  pokeb(0xa000,y*320+x,color);
}
BYTE point(int x,int y)
{
  return peekb(0xa000,y*320+x);
}

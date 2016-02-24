#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#define ESC 27
#define UP 328
#define DOWN 336
#define LEFT 331
#define RIGHT 333
#define BLAMK 32
#define BOTTOM 2
#define CANNOT 1
#define CAN 0
#define MAX 30
#define F1 315
#define ADD 43
#define EQUAL 61
#define DEC 45
#define SOUNDs 115
#define SOUNDS 83
#define PAUSEP 80
#define PAUSEp 112


void Init();
void Down();
void GoOn();
void ksdown();
void Display(int color);
void Give();
int Touch(int x,int y, int dx,int dy);
int GeyKey();
void Select();
void DetectFill();





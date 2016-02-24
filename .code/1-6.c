#include<stdio.h>
#include<math.h>
#include<stdarg.h>
#define OK 1
#define ERROR 0
#define MAX_ARRAY_DIM 8
typedef int ElemType;
typedef int Status;
typedef struct
{
  ElemType *base;
  int dim;
  int *bounds;
  int *constants;
}Array;



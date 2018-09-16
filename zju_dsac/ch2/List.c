// Copyright [2018] <mituh>
// List.c

#include <stdio.h>
/* malloc在stdlib中 */
#include <stdlib.h>              /* debug02 */

typedef int ElementType;

#define MAXSIZE 100

typedef int Status;
#define ERROR 0
#define OVERFLOW -1
#define OK 1

typedef int Position;
// typedef LNode *ptrToNode;     /* debug03 */
/* 定义结构指针需要加struct */
typedef struct LNode *ptrToNode;

struct LNode {
  Position Last;
  // ptrToNode Data[MAXSIZE];    /* debug01 */
  /* Data的类型是ElementType数组*/
  ElementType Data[MAXSIZE];
};

typedef ptrToNode List;


List makeEmpty() {
  List L;
  L = (List)malloc(sizeof(struct LNode));
  L->Last = -1;
  return L;
}

Status find(List L, ElementType elem) {
  Position i; Status NotFound = -1;
  while (i <= L->Last && L->Data[i] != elem)
    i++;
  if (i > L->Last) {
    return NotFound;
  } else {
    return i;     /* 返回该元素的下标 */
  }
}

Status insert(List L, ElementType elem, Position i) {
  if (L->Last == MAXSIZE-1) {
    printf("Overflow\n");
    return OVERFLOW;
  }

  if (i < 1 || i > L->Last+2) {
    printf("Error\n");
    return ERROR;
  }

  Position j;
  for (j = L->Last; j >= i-1; j--) {
    L->Data[j+1] = L->Data[j];
  }
  L->Data[i-1] = elem;
  L->Last++;
  return OK;
}

Status delete(List L, Position i, ElementType *elem) {
  if (i < 1 || i > L->Last+1) {
    printf("Error\n");
    return ERROR;
  }

  Position j;
  *elem = L->Data[i];
  /* for (j = i; j <= L->Last-1; j++) { */    /* debug04 */
  /* L->Last是最后一个元素下标, 同样需要移动 */
  for (j = i; j <= L->Last; j++) {
    L->Data[j-1] = L->Data[j];
  }
  L->Last--;
  return OK;
}



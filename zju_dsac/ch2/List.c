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
  /* 用while循环, 可统一用i作为判断找到与否的条件 */
  while (i <= L->Last && L->Data[i] != elem)
    i++;
  if (i > L->Last) {
    return NotFound;
  } else {
    return i;     /* 返回该元素的下标 */
  }
}

Status insert(List L, ElementType elem, Position i) {
  /* 检查表是否满 */
  if (L->Last == MAXSIZE-1) {
    printf("Overflow\n");
    return OVERFLOW;
  }

  /* 检查插入位置是否合法 */
  if (i < 1 || i > L->Last+2) {
    printf("Error\n");
    return ERROR;
  }

  /* 从右向左, 做整体向右移动的操作 */
  Position j;
  for (j = L->Last; j >= i-1; j--) {
    L->Data[j+1] = L->Data[j];
  }

  /* 插入元素 改变最后元素的下标 */
  L->Data[i-1] = elem;
  L->Last++;
  return OK;
}

Status delete(List L, Position i, ElementType *elem) {
  /* 检查插入位置的合法性 */
  if (i < 1 || i > L->Last+1) {
    printf("Error\n");
    return ERROR;
  }

  Position j;
  /* 记录被删除元素 */
  *elem = L->Data[i];
  /* for (j = i; j <= L->Last-1; j++) { */    /* debug04 */
  /* L->Last是最后一个元素下标, 同样需要移动 */
  for (j = i; j <= L->Last; j++) {
    L->Data[j-1] = L->Data[j];
  }
  L->Last--;
  return OK;
}



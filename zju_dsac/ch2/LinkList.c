// Copyright [2018] <mituh>
// LinkList.c
// 线性表的链式存储

#include <stdio.h>

typedef int ElementType;

/* 定义结构 */
typedef struct LNode *ptrToNode;
struct LNode {
  ElementType Data;
  ptrToNode Next;
};
typedef ptrToNode List;
typedef ptrToNode Position;    /* Position是一个结点 */

/* 求表长 */
int length(List L) {
  Position p; int len;
  len = 0;
  p = L;
  while (p) {
    p = p->Next;
    len++;
  }
  return len;
}

/* #define ERROR NULL */
/* Position findKth(List L, int K) {} */

#define ERROR -1
ElementType findKth(List L, int K) {
  /* 找到第K个元素 */
  /*
  if (K < 1) {
    printf("Error\n");
    return ERROR;
  }
  */
  Position p;
  int i;
  p = L;
  i = 1;
  while (p && i != K) {
    p = p->Next;
    i++;
  }
  if (i == K) {
    return p->Data;
  } else {
    printf("Error\n");
    return ERROR;
  }
}

Position find(List L, ElementType elem) {
  /* 找到elem元素的结点 */
  Position p;
  p = L;
  while (p && p->Data != elem) {
    p = p->Next;
  }
  if (p != NULL) {
    return p;
  } else {
    printf("Not Found\n");
    return NULL;
  }
}





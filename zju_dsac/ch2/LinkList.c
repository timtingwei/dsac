// Copyright [2018] <mituh>
// LinkList.c
// 线性表的链式存储

#include <stdio.h>
#include <stdlib.h>
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


#define ERROR -1
ElementType findKth(List L, int K) {
  /* 找到第K个元素 */
  /*
  if (K < 1) {
    printf("Error\n");
    return ERROR;
  }
  */
  /* 可以不必提前检查合法性*/
  Position p;
  int cnt = 1;
  p = L;
  while (p && cnt != K) {
    p = p->Next;
    cnt++;
  }
  /* if (cnt == K) { debug01: 当K是未元素的下一个元素的序号, 要判断p是否null */
  if ((cnt == K) && p) {
    return p->Data;
  } else {
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

#define ERROR_P NULL
List insert(List L, ElementType elem, int i) {
  if (i < 1) {
    return ERROR_P;     /* 链表头部之前的插入位置不合法 */
  } else if (i == 1) {
    List node;
    node = (List)malloc(sizeof(struct LNode));
    node->Data = elem;
    node->Next = L;
    return node;
  } else {
    Position prevP = L, p = L->Next;
    int j = 2;
    while (p && j != i) {
      prevP = prevP->Next;
      p = prevP->Next;
      j++;
    }
    if (j == i) {
      List node;
      node = (List)malloc(sizeof(struct LNode));
      node->Data = elem; node->Next = p;
      prevP->Next = node;
      return L;
    } else {
      return ERROR_P;    /* 在链表尾部不存在可插入的结点 */
    }
  }
}






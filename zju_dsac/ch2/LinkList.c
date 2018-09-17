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
  }
  /* debug1: 统一为插入结点分配空间 */
  List node;
  node = (List)malloc(sizeof(struct LNode));
  if (i == 1) {        /* 在链表头部插入 */
    node->Data = elem;
    node->Next = L;
    return node;
  } else {            /* 在表头以外的位置插入 */
    Position prevP = L, p;
    /* p = L->Next; */
    if (prevP == NULL) {
      /* 此时i不为1, 插入不合法 */  /* debug04: 空链表L->Next不合法 */
      free(node);
      return ERROR_P;
    }
    p =  L->Next;
    /* int j = 2; */  /* debug02: prevP存在, 可在尾部n+1插入*/
    int j = 1;
    while (prevP && j != i-1) {
      prevP = prevP->Next;
      p = prevP->Next;
      j++;
    }
    // if (j == i ) {
    if (j == i-1 && prevP) {  /* prevP此时为插入序号的前一个 */
      node->Data = elem; node->Next = p;
      prevP->Next = node;
      return L;
    } else {
      free(node);        /* debug03: 插入失败要回收结点 */
      return ERROR_P;    /* 在链表尾部不存在可插入的结点 */
    }
  }
}






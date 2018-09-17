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


/* 不带头结点的链表插入 */
#define ERROR_P NULL
List insert(List L, ElementType elem, int i) {
  if (i < 1) {
    return ERROR_P;     /* 链表头部之前的插入位置不合法 */
  }
  /* debug1: 统一为插入结点分配空间 */
  List node, prev;      /* prev也可以统一声明 */
  node = (List)malloc(sizeof(struct LNode));
  node->Data = elem;    /*debug05: 结点的元素也可以事先分配 */
  if (i == 1) {        /* 在链表头部插入 */
    node->Next = L;
    return node;
  } else {            /* 在表头以外的位置插入 */
    prev = L;
    /* p = L->Next; */  /* debug06: 只需要prev一个结点, 不需要当前结点 */
    /* int cnt = 2; */   /* debug02: prevP存在, 可在尾部n+1插入*/
    int cnt = 1;
    while (prev && cnt != i-1) {
      prev = prev->Next;
      cnt++;
    }
    // if (cnt == i ) {
    if (cnt == i-1 && prev) {  /* prevP此时为插入序号的前一个 */
      node->Next = prev->Next;
      prev->Next = node;
      return L;
    } else {
      free(node);        /* debug03: 插入失败要回收结点 */
      return ERROR_P;    /* 在链表尾部不存在可插入的结点 */
    }
  }
}

typedef int Status;
#define OK 1
#define FAIL 0

/* 带头结点的链表插入 */
Status insert_H(List L, ElementType elem, int i) {
  /* L默认有头结点 */
  Position prev, node;
  int cnt = 0;
  prev = L;
  while (prev && cnt < i-1) {
    prev = prev->Next; cnt++;
  }
  if (prev && cnt == i-1) {
    /* 插入新结点 */
    node = (Position)malloc(sizeof(struct LNode));
    node->Data = elem;
    node->Next = prev->Next;
    prev->Next = node;
    return OK;
  } else {
    /* 插入位置不合法 */
    return FAIL;
  }
}

/* 带头结点的链表删除 */
Status delete(List L, int i) {
  /* L默认有头结点 */
  Position prev, tmp;
  int cnt = 0;
  prev = L;
  while (prev && cnt < i-1) {
    prev = prev->Next; cnt++;
  }
  if (prev && prev->Next && cnt == i-1) {
    /* 删除旧的结点 */
    tmp = prev->Next;
    prev->Next = tmp->Next;
    free(tmp);
    return OK;
  } else {
    /* 删除的位置不合法 */
    return FAIL;
  }
}

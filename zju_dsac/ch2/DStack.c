// Copyright [2018] <mituh>
// DStack.c
// 用一个数组实现两个栈的构造, 插入, 删除

#include <stdlib.h>

typedef int ElementType;
typedef int Position;

// typedef LNode *ptrToNode;
typedef struct LNode *ptrToNode;
struct LNode {
  ElementType *Data;
  Position top1;
  Position top2;
  int maxSize;
};
typedef ptrToNode Stack;

Stack createEmpty(int maxSize) {
  Stack S;
  S->Data = (ElementType*)malloc(sizeof(ElementType) * maxSize);
  S->top1 = -1; S->top2 = maxSize;
  S->maxSize = maxSize;
  return S;
}


void push(Stack S, ElementType elem, int tag) {
  if (S->top2 == S->top1 + 1) {
    return;
  }
  if (tag == 0) {
    S->Data[++S->top1] = elem;
  } else {
    S->Data[--S->top2] = elem;
  }
}

#define ERROR -1
#define OK 1
int delete(Stack S, ElementType *elem, int tag) {
  if ((tag == 0 && S->top1 == -1) || (tag == 1 && S->top2 == S->maxSize)) {
    return ERROR;
  }
  if (tag == 0) {
    S->top1--;
  } else {
    S->top2++;
  }
  return OK;
}

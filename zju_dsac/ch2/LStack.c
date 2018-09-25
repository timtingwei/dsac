// Copyright [2018] <mituh>
// LStack.c
// 链表实现栈

#include <stdlib.h>

typedef int ElementType;

typedef struct SNode *ptrToNode;
struct SNode {
  ElementType Data;
  ptrToNode Next;
};
typedef ptrToNode LStack;

LStack createEmpty() {
  LStack S;
  S = (LStack)malloc(sizeof(struct SNode));
  S->Next = NULL;
  return S;
}

int isEmpty(LStack S) {
  return (S->Next == NULL);
}

void push(LStack S, ElementType elem) {
  ptrToNode node;
  node = (ptrToNode)malloc(sizeof(struct SNode));
  node->Data = elem;
  node->Next = S;
  S = node;
}

#define OK 1
#define ERROR 0
int pop(LStack S, ElementType *elem) {
  if (isEmpty(S)) return ERROR;
  LStack temp = S;
  *elem = temp->Data;
  S = S->Next;
  free(temp);
  return OK;
}


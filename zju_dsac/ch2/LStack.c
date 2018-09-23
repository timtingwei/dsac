// Copyright [2018] <mituh>
// LStack.c
// 链表实现栈

typedef int ElementType;

typedef struct SNode *ptrToNode;
struct SNode {
  ElementType Data;
  ptrToNode Next;
};
typedef ptrToNode LStack

LStack createEmpty() {
  LStack S;
  S = (LStack)malloc(sizeof(struct SNode));
  S->Next = NULL;
  return S;
}

int isEmpty(LStack S) {
  return (S->Next == NULL);
}



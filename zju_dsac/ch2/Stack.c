// Copyright [2018] <mituh>
// Stack.c

#include <stdlib.h>

#define MAXSIZE 10
typedef int ElementType;
typedef int Position;

typedef int bool;
#define true 1
#define false 0

/*
// 自己实现栈的存储
struct Stack {
  ElementType Data[MAXSIZE];
  Position top;
};

typedef struct Stack Stack;
*/

// 正确的版本
typedef struct SNode *ptrToNode;
struct SNode {
  ElementType *Data;
  Position top;
  int maxSize;
};
typedef ptrToNode Stack;

Stack createEmpty(int maxSize) {
  Stack S;
  // S = (Stack*)malloc(sizeof(Stack));    // bebug01
  S = (Stack)malloc(sizeof(struct SNode));
  // 除了为S指针分配空间, 还要为Data数组分配空间.
  S->Data = (ElementType*)malloc(sizeof(ElementType) * maxSize);
  S->top = -1;
  // 之前的版本竟然没有用到maxSize;
  S->maxSize = maxSize;
  return S;
}

/*
其实不需要写if-else语句
bool isEmpty(Stack S) {
  if (S->top == -1) return true;
  else  return false;
}


bool isFull(Stack S) {
  if (S->top == S->maxSize-1) return true;
  else  return false;
}
*/

bool isEmpty(Stack S) { return S->top == -1; }

bool isFull(Stack S) { return S->top == S->maxSize-1;}


void push(Stack S, ElementType elem) {
  if (isFull(S)) {
    return;
  } else {
    S->Data[++S->top] = elem;
  }
}

/*
bool pop(Stack S, ElementType *elem) {
  if (isEmpty(S)) {
    return false;
  } else {
    *elem = S->Data[(S->top)--];
    return true;
  }
}

*/

#define ERROR -1
// -1是返回的elem的特殊标记值
ElementType pop(Stack S) {
  if (isEmpty(S)) {
    return ERROR;
  } else {
    return S->Data[(S->top)--];
  }
}

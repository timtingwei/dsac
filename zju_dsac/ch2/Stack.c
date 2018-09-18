// Copyright [2018] <mituh>
// Stack.c

#include <stdlib.h>

#define MAXSIZE 10
typedef int ElementType;
typedef int Position;

typedef int bool;
#define true 1
#define false 0

struct Stack {
  ElementType Data[MAXSIZE];
  Position top;
};

typedef struct Stack Stack;

Stack createEmpty(int maxSize) {
  Stack S;
  S = (Stack*)malloc(sizeof(Stack));    // bebug01
  S.top = -1;
  return S;
}

bool isEmpty(Stack S) {
  if (S.top == -1) return true;
  else  return false;
}

bool isFull(Stack S) {
  if (S.top == MAXSIZE-1) return true;
  else  return false;
}

void push(Stack S, ElementType elem) {
  if (isFull(S)) {
    return;
  } else {
    S.Data[++S.top] = elem;
  }
}

bool pop(Stack S, ElementType *elem) {
  if (isEmpty(S)) {
    return false;
  } else {
    *elem = S.Data[S.top--];
    return true;
  }
}



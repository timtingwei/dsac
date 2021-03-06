// Copyright[2018] <mituh>
// ex3-1-5.cpp
// 实现共享栈s1, s2的入栈和出栈操作
#include <stdio.h>
#include <stdlib.h>
/*
struct SNode {
  ElementType *data;
  Position top1;
  Position top2;
  int maxSize;
};
typedef struct SNode *DStack;

// 入栈操作
void push(DStack S, ElementType elem, int tag) {
  if (S->top2 - S->top1 == 1) {
    printf("栈满\n");
    return;
  }
  if (tag == 0) {   // 选择入第一个栈
    S->data[++top1] = elem;
  } else {
    S->data[--top2] = elem;
  }
}


// 共享栈出栈操作
ElementType pop(DStack S, int tag) {
  if (tag == 0) {
    if (S->top1 == -1) {
      printf("第一个栈空\n");
      return ERROR;
    }
    return S->data[(S->top1)--];
  } else if (tag == 1) {
    if (S->top2 = S->maxSize) {
      printf("第二个栈空\n");
      return ERROR;
    }
    return S->data[(S->top2)++];
  }
}
*/

// 正确的版本

#define MAXSIZE 100

typedef int ElementType;
typedef struct {
  ElementType stack[MAXSIZE];
  int top[2];
}stk;
stk s;          // s作为全局变量

int push(int tag, ElementType elem) {
  // 入栈算法. tag为0入栈1, 为1入栈2,elem是入栈元素
  // 入栈成功返回1, 入栈失败返回0
  if (tag < 0 || tag > 1) {
    printf("栈序号非法\n");
    exit(0);
  }
  if (s.top[1]-s.top[0] == 1) {
    printf("栈满\n");
    return 0;
  }
  switch (tag) {
    case 0:s.stack[++s.top[0]] = elem; return 1; break;
    case 1:s.stack[--s.top[1]] = elem; return 1;
  }  // switch
}

ElementType pop(int tag) {
  // 出栈算法. tag为0从栈1出, tag为1从栈2出
  // 出栈成功返回出栈元素, 失败返回-1
  if (tag < 0 || tag > 1) {
    printf("栈序号非法\n");
    exit(0);
  }
  switch (tag) {
    case 0:
      if (s.top[0] == -1) {
        printf("栈1为空\n");
        return -1;
      } else {
        return s.stack[s.top[0]--];
      }
      break;
    case 1:
      if (s.top[1] == MAXSIZE) {
        printf("栈2为空\n");
        return -1;
      } else {
        return s.stack[s.top[1]++];
      }
  }  // switch
}











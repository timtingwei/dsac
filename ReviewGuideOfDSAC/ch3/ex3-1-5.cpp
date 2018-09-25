// Copyright[2018] <mituh>
// ex3-1-5.cpp
// 实现共享栈s1, s2的入栈和出栈操作

struct SNode {
  ElementType *data;
  Position top1;
  Position top2;
  int maxSize;
};
typedef struct SNode *DStack;

/* 入栈操作 */
void push(DStack S, ElementType elem, int tag) {
  if (S->top2 - S->top1 == 1) {
    printf("栈满\n");
    return;
  }
  if (tag == 0) {   /* 选择入第一个栈 */
    S->data[++top1] = elem;
  } else {
    S->data[--top2] = elem;
  }
}


/* 共享栈出栈操作 */
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

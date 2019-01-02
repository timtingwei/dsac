// Copyright [2018] <mituh>
// BinTreeStaticLink.c
// 结构数组表示二叉树: 静态链表

#include <stdio.h>

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1   /* 0为根结点下标, 用-1区别 */

struct TNode {
  ElementType Element;
  Tree Left;
  Tree Right;
} T1[MaxTree], T2[MaxTree];


/* 用结构数组创建一棵二叉树 */
Tree BuildTree() {
  int i, N, check[MaxTree];
  struct TNode *Elements[MaxTree];
  ElementType cl, cr;
  Tree Root;
  scanf("%d", &N);
  if (N) {
    for (i = 0; i < N; i++) {
      check[i] = 0;
    }

    for (i = 0; i < N; i++) {
      scanf("%c %c %c", &Elements[i]->Element, &cl, &cr);   /* 以字符形式读入 */
      Elements[i]->Left  = (cl == '-') ? Null : (cl - '0');
      Elements[i]->Right = (cr == '-') ? Null : (cr - '0');

      if (cl != '-') check[cl - '0'] = 1;
      if (cr != '-') check[cr - '0'] = 1;
    }

    for (i = 0; i < N; i++) {
      if (check[i] == 0) break;
    }
    Root = i;
    return Root;
  } else {
    return -1;
  }
}

int main() {

  BuildTree();

  return 0;
}

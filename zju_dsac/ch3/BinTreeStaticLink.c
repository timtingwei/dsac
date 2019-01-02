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
  struct TNode T[MaxTree];   /* 为什么不定义成指针, 而是.呢? */
  ElementType cl, cr;
  Tree Root = -1;      /* 悲观打算 */
  scanf("%d\n", &N);   /* 标准输入按照格式 */
  if (N) {
    for (i = 0; i < N; i++) check[i] = 0;

    for (i = 0; i < N; i++) {
      scanf("%c %c %c\n",
            &T[i].Element, &cl, &cr);      /* 以字符形式读入 */

      if (cl != '-') {
        T[i].Left = cl - '0';
        check[T[i].Left] = 1;
      } else {
        T[i].Left = Null;
      }

      if (cr != '-') {
        T[i].Right = cr - '0';
        check[T[i].Right] = 1;
      } else {
        T[i].Right = Null;
      }
    }

    for (i = 0; i < N; i++) {
      if (!check[i]) break;
    }
    Root = i;
  }
  return Root;
}

int main() {

  BuildTree();

  return 0;
}

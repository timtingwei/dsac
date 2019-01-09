/* Copyright [2019] <mituh> */
/* 03-1_Isomorphism.c           */
/* 树的同构 */

#include <stdio.h>

#define MaxSize 13
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode {
  ElementType Element;
  Tree Left;
  Tree Right;
} T1[MaxSize], T2[MaxSize];


Tree BuildTree(struct TreeNode T[]) {
  /* 建立用于判别的二叉树 */
  int i, N;
  char cl, cr;
  Tree Root;
  int check[MaxSize];

  scanf("%d", &N);
  if (N) {
    for (i = 0; i < N; i++) check[i] = 0;
    for (i = 0; i < N; i++) {
      getchar();   /* 控制输入格式 */
      scanf("%c %c %c", &T[i].Element, &cl, &cr);

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

int Isomorphic(Tree R1, Tree R2) {
  if (R1 == Null && R2 == Null) {
    /* 都空 */
    return 1;
  }
  if ((R1 == Null && R2 != Null)
       || (R1 != Null && R2 == Null)) {
    /* 一个空一个不空 */
    return 0;
  }
  if (T1[R1].Element != T2[R2].Element) {
    /* 两个结点元素不同 */
    return 0;
  }
  if (T1[R1].Left == Null && T2[R2].Left == Null) {
    /* 左子树都为空, 递归判断右子树 */
    return Isomorphic(T1[R1].Right, T2[R2].Right);
  }
  if ((T1[R1].Left != Null) &&
      (T2[R2].Left != Null) &&
      (T1[T1[R1].Left].Element == T2[T2[R2].Left].Element)) {
    /* 左子树都不空, 且左孩子结点元素相等 */
    return (Isomorphic(T1[R1].Left, T2[R2].Left) &&
            Isomorphic(T1[R1].Right, T2[R2].Right));
  } else {
    /* 左右孩子交换判断 */
    return (Isomorphic(T1[R1].Left, T2[R2].Right) &&
            Isomorphic(T1[R1].Right, T2[R2].Left));
  }
}

int main() {
  Tree Root1, Root2;
  Root1 = BuildTree(T1);
  Root2 = BuildTree(T2);
  if (Isomorphic(Root1, Root2)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}

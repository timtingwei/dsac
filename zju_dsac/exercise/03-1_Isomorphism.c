/* Copyright [2019] <mituh> */
/* 03-1_Isomorphism.c           */
/* 树的同构 */

#include <stdio.h>

#define MaxSize 13
typedef char ElementType;
typedef int Tree;   /* 数组中的下标 */

struct TreeNode {
  ElementType Data;
  Tree Left;
  Tree Right;
} T1[MaxSize], T2[MaxSize];

int main() {
  int n, m;
  Tree Root1, Root2;

  scanf("%d", &n);
  Root1 = ReadTree(T1, n);
  scanf("%d", &m);
  Root1 = ReadTree(T2, m);

  if (m != n || Judge(Root1, Root2)) {
    printf("No\n");
  } else {
    printf("Yes\n");
  }
  return 0;
}

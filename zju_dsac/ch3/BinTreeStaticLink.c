// Copyright [2018] <mituh>
// BinTreeStaticLink.c
// 结构数组表示二叉树: 静态链表

#define Maxsize 10
#define ElementType char
#define Tree int
#define Null -1

struct TNode {
  ElementType Data;
  Tree Left;
  Tree Right;
} T1[Maxsize], T2[Maxsize];

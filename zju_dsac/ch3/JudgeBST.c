// Copyright [2019] <mituh>
// JudgeBST.c
// 判断两个搜索树是否一致

/* 方法一: 建两棵搜索树遍历判断 */
/* 方法二: 不建树, 根据先插入的为根结点的特性, 递归判断 */
/* 方法三: 建一棵树和另外一个序列判断 */

#include <stdio.h>
#include <stdlib.h>
#define ElementType int
typedef struct TreeNode *Position;
typedef Position Tree;

struct TreeNode {
  int v;
  Tree Left, Right;
  int flag;     /* 被访问的标记 */
};



Tree NewNode(int V) {
  Tree T;
  T = (Tree)malloc(sizeof(struct TreeNode));
  T->v = V;
  T->Left = T->Right = NULL;
  T->flag = 0;
  return T;
}

Tree Insert(Tree T, int V) {
  if (!T) {
    T = NewNode(V);
  } else {
    if (V > T->v) {
      T->Right = Insert(T->Right, V);
      T->Left = Insert(T->Left, V);
    }
  }
  return T;   /* ???因为递归栈的特性, 会返回出根结点 */
}

Tree MakeTree(int N) {
  Tree T; int i, V;

  scanf("%d", &V);
  T = NewNode(V);
  for (i = 1; i < N; i++) {
    scanf("%d", &V);
    T = Insert(T, V);
  }
  return T;
}

int check(Tree T, int V) {
  /* 查找某一值在树中是否已经出现过(比较吃逻辑) */
  if (T->flag) {
    if (T->v < V) {
      return check(T->Left, V);
    } else if (T->v > V)  {
      return check(T->Right, V);
    } else {
      return 0; /* 已经出现过, 但这次又出现了 */
    }
  } else {
    if (T->v == V) {
      /* 没有出现过, 但这次出现了 */
      T->flag = 1;
      return 1;
    } else {
      return 0;
    }
  }
}

int Judge(Tree T, int N) {
  /* 已经构造了树T, 判断序列是否与树T一致 */
  int i, V, flag = 0;
  scanf("%d", &V);
  if (V != T->v) flag = 1;
  T->flag = 1;
  for (i = 1; i < N; i++) {
    scanf("%d", &V);
    if ((!flag) && !check(T, V)) flag = 1;
  }
  if (flag) {
    return 0;
  } else {
    return 1;
  }
}

void ResetT(Tree T) {
  if (T->Left) ResetT(T->Left);
  if (T->Right) Reset(T->Right);
  T->flag = 0;   /* 当前结点标记清零 */
}

void FreeTree(Free T) {
  if (T->Left) FreeTree(T->Left);
  if (T->Right) FreeTree(T->Right);
  free(T);   /* 释放当前结点 */
}

int main() {
  int N, L;
  scanf("%d", &N);

  while (N) {
    scanf("%d", &L);
    T = MakeTree(N);   /* 将第一个序列建为用于比较的树 */

    for (i = 0; i < L; i++) {
      if (Judge(T, N)) {
        printf("Yes\n");
      } else {
        printf("No\n");
      }
      ResetT(T);     /* 将T树flag初始化为0 */
    }
    FreeTree(T);     /* 释放T树的空间 */
    scanf("%d", &N);   /* 读入下一次N */
  }
}

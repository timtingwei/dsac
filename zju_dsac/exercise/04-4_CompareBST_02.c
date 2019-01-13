/* Copyright [2019] <mituh> */
/* 04-4_CompareBST_02.c */
/* 比较两棵二叉搜索树是否相同(建一棵树, 用一个序列去检查) */


/*
4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0

Yes
No
No
*/

#include <stdlib.h>
#include <stdio.h>

/* 二叉树的存储 */
typedef struct TNode *Tree;
struct TNode {
  int Data;
  Tree Left, Right;
  int flag;
};

Tree NewNode(int v) {
  Tree T;
  T = (Tree)malloc(sizeof(struct TNode));
  T->Data = v;
  T->Left = T->Right = NULL;
  return T;
}

/* 向一棵线索树中插入元素作为结点 */
Tree Insert(int Elem, Tree T) {
  if (!T) {
    T = NewNode(Elem);
  } else {
    if (Elem < T->Data) {
      T->Left = Insert(Elem, T->Left);
    } else if (Elem > T->Data) {
      T->Right = Insert(Elem, T->Right);
    } /* else 相等不需要任何操作 */
  }
  return T;
}

/* 读入并建一棵N个结点的树 */
Tree BuildTree(int N) {
  Tree T;
  int i, v;

  scanf("%d", &v);
  T = NewNode(v);
  for (i = 1; i < N; i++) {
    scanf("%d", &v);
    Insert(v, T);
  }
  return T;
}

int check(Tree T, int v) {
  if (T->flag) {
    if (v < T->Data) {
      return check(T->Left, v);
    } else if (v > T->Data) {
      return check(T->Right, v);
    } else {    /* 重复出现 */
      return 0;
    }
  } else {
    if (v == T->Data) {   /* 刚好碰到 */
      T->flag = 1;
      return 1;
    } else {              /* 越过, 没碰到 */
      return 0;
    }
  }
}

/* 一棵树和一个序列进行判断 */
int Judge(Tree T, int N) {
  int i, v, flag;
  flag = 0;   /* 完全一致flag=0 */

  for (i = 0; i < N; i++) {
    scanf("%d", &v);
    if ((!flag) && (!check(T, v))) flag = 1;
  }
  if (!flag) {
    return 1;
  } else {
    return 0;
  }
}

/* 把T中的标记清空 */
void ResetT(Tree T) {
  if (T->Left) ResetT(T->Left);
  if (T->Right) ResetT(T->Right);
  T->flag = 0;
}

/* 释放一棵树 */
void FreeTree(Tree T) {
  if (T->Left) FreeTree(T->Left);
  if (T->Right) FreeTree(T->Right);
  free(T);
}

int main() {
  int i, N, M, v;
  Tree T;

  for (;;) {
    scanf("%d", &N);
    if (!N) break;
    scanf("%d", &M);
    T = BuildTree(N);
    for (i = 0; i < M; i++) {
      ResetT(T);
      if (Judge(T, N)) {
        printf("Yes\n");
      } else {
        printf("No\n");
      }
    }
    FreeTree(T);
  }
  return 0;
}

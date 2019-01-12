/* Copyright [2019] <mituh> */
/* 04-4_CompareBST_01.c */
/* 比较两棵二叉搜索树是否相同(建两棵树, 递归比较的方法) */

/* 二叉树的存储 */

#include <stdlib.h>
#include <stdio.h>
typedef struct TNode *PtrToTNode;
typedef PtrToTNode Tree;
struct TNode {
  int Data;
  Tree Left, Right;
};

Tree NewNode(int v) {
  Tree T;
  T = malloc(sizeof(struct TNode));
  T->Data = v;
  T->Left = NULL; T->Right = NULL;
  return T;
}

/* 向一棵二叉搜索树中插入元素 */
Tree Insert(int Elem, Tree T) {
  if (!T) {
    T = NewNode(Elem);
    /* printf("Elem = %d, arranged\n", Elem); */
  } else {
    if (Elem < T->Data) {
      T->Left = Insert(Elem, T->Left);
    } else if (Elem > T->Data) {
      T->Right = Insert(Elem, T->Right);
    }
    /* else 相等不需要任何其余操作 */
  }
  return T;
}

/* 比较两棵树是否相同 */
int Compare(Tree T1, Tree T2) {
  if (T1 == NULL && T2 == NULL) {
    return 1;
  } else if ((T1 == NULL && T2 != NULL)
             || (T1 != NULL && T2 == NULL)) {
    return 0;
  } else if (T1->Data == T2->Data) {
    return (Compare(T1->Left, T2->Left)
      && Compare(T1->Right, T2->Right));
  } else {
    return 0;
  }
}




int main() {
  int N, K, i, Elem, ok, flag;
  flag = 0;
  for (;;) {
    scanf("%d", &N);
    if (!N) break;
    Tree T;
    scanf("%d", &K);
    scanf("%d", &Elem);
    T = NewNode(Elem);
    for (i = 1; i < N; i++) {
      scanf("%d", &Elem);
      Insert(Elem, T);
    }
    while (K--) {
      Tree CmpT;
      scanf("%d", &Elem);
      CmpT = NewNode(Elem);
      for (i = 1; i < N; i++) {
        scanf("%d", &Elem);
        Insert(Elem, CmpT);
      }
      ok = Compare(T, CmpT);
      if (!flag) {
        flag = 1;
      } else {
        printf("\n");
      }  /* 控制格式 */

      if (ok) {
        printf("Yes");
      } else {
        printf("No");
      }
    }
  }

  return 0;
}




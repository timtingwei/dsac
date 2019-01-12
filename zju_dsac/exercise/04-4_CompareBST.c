/* Copyright [2019] <mituh> */
/* 04-4_CompareBST.c */
/* 比较两棵二叉搜索树是否相同 */

/* 二叉树的存储 */

#include <stdlib.h>
#include <stdio.h>
typedef struct TNode *PtrToTNode;
typedef PtrToTNode Tree;
struct TNode {
  int Data;
  Tree Left, Right;
};


/* 向一棵二叉搜索树中插入元素 */
Tree Insert(int Elem, Tree T) {
  if (!T) {
    T = (Tree)malloc(sizeof(struct TNode));
    T->Data = Elem;
    T->Left = NULL; T->Right = NULL;
    printf("Elem = %d, arranged\n", Elem);
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
  if (T1 == NULL && T2 == NULL)  {
    printf("T1, T2 both NULL\n");
  } else if (T1 == NULL) {
    printf("T1 = NULL, T2->Data = %d\n", T2->Data);
  } else if (T2 == NULL) {
    printf("T1->Data = %d, T2 = NULL\n", T1->Data);
  } else {
    printf("T1->Data = %d, T2->Data = %d\n", T1->Data, T2->Data);
  }
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
    for (i = 0; i < N; i++) {
      scanf("%d", &Elem);
      Insert(Elem, T);
    }
    while (K--) {
      Tree CmpT;
      for (i = 0; i < N; i++) {
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




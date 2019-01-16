/* Copyright [2019] <mituh> */
/* 04-5_Root-of-AVL-Tree.c */
/* 平衡二叉树的旋转 */

/*
Sample Input 1:
5
88 70 61 96 120
Sample Output 1:
70


Sample Input 2:
7
88 70 61 96 120 90 65

Sample Output 2:
88
*/
#include <stdlib.h>
#include <stdio.h>
int main() {
  int N, in;
  AVLTree T;
  scanf("%d", &N);
  while (N--) {
    scanf("%d", &in);
    T = Insert(T, in);
  }
  printf("%d\n", T->Data);
  return 0;
}

/* 平衡二叉树的存储 */
#define ElementType int
typedef struct AVLNode *PtrToAVLNode;
struct AVLNode {
  ElementType Data;
  AVLTree Left;
  AVLTree Right;
  int Height;      /* 树高 */
};
typedef struct PtrToAVLNode AVLTree;

/* 取较大者 */
int Max(int a, int b) {
  return a > b ? a : b;
}

/* 求树的高度 */
int GetHeight(AVLTree T) {
  int HL, HR, MaxH;

  if (T) {
    HL = GetHeight(T->Left);     /* 求左子树的高度 */
    HR = GetHeight(T->Right);    /* 求右子树的高度 */
    MaxH = Max(HL, HR);    /* 取较大的高度 */
    return (MaxH + 1);
  } else {
    return 0;   /* 空树高度为0 */
  }
}

/* 左单旋 */
AVLTree SingleLeftRotation(AVLTree A) {
  /* A必须有左结点B, B有左结点C */

  AVLTree B = A->Left;
  A->Left = B->Right;   /* B的右结点比b大比a小 */
  B->Right = A;
  A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
  B->Height = Max(GetHeight(B->Left), GetHeight(B->Right)) + 1;
  return B;   /* B成为新的根结点 */
}


/* 右单旋 */
AVLTree SingleRightRotation(AVLTree A) {
  /* A必须有右结点B, B有右结点C */

  AVLTree B = A->Right;
  A->Right = B->Left;
  B->Left = A;
  A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
  B->Height = Max(GetHeight(B->Left), GetHeight(B->Right)) + 1;
  return B;   /* B成为新的根结点 */
}

/* 左右双旋 */
AVLTree DoubleLeftRightRotation(AVLTree A) {
  /* A必须有左孩子B, B有右孩子C */

  T->Left = SingleLeftRotation(A->Left);    /* 左子树先左旋转 */
  return SingleRightRotation(A);            /* 根结点再右转 */
}

/* 右左双旋 */
AVLTree DoubleRightLeftRotation(AVLTree A) {
  /* A必须有右孩子B, B有左孩子C */

  T->Right = SingleRightRotation(A->Right);    /* 右子树先右旋转 */
  return SingleLeftRotation(A);                /* 根结点再左转 */
}



/* 递归插入操作 */
AVLTree Insert(AVLTree T, ELementType X) {
  if (!T) {
    /* 树空 */
    T = (AVLTree)malloc(sizeof(struct AVLNode));
    T->Data = X;
    T->Left = T->Right = NULL;
    T->Height = 1;
  } else if (X < T->Data) {
    /* 插入左子树 */
    T->Left = Insert(T->Left, X);
    /* 判断是否失衡 */
    if (GetHeight(T->Left) - GetHeight(T->Right) == 2) {
      if (X < T->Left->Data) {
        T = SingleLeftRotation(T);  /* 左单旋 */
      } else {
        T = DoubleLeftRightRotation(T);    /* 左右双旋转 */
      }
    }
  } else if (X > T->Data) {
    /* 插入右子树 */
    if (GetHeight(T->Right) - GetHeight(T->Left) == 2) {
      if (X > T->Right->Data) {
        T = SingleRightRotation(T);    /* 右单旋 */
      } else {
        T = DoubleRightLeftRotation(T);    /* 右左双旋 */
      }
    }
  }
  /* else if (X == T->Data) 不操作 */

  /* 更新树高 */
  T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
  return T;
}

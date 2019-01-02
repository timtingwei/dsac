// Copyright [2018] <mituh>
// BinSearchTreeInsert.c
// 二叉搜索树中的插入

#include <stdlib.h>

#define ElementType int
typedef struct TNode *Position;
typedef Position BinTree;

struct TNode {
  ElementType Data;
  BinTree Left;
  BinTree Right;
};


BinTree Insert(ElementType X, BinTree BST) {
  /* 二叉搜索树的插入算法 */
  if (!BST) {
    BST = (BinTree)malloc(sizeof(struct TNode));
    BST->Data = X;
    BST->Left = BST->Right = NULL;
  } else {
    if (X < BST->Data) {
      BST = Insert(X, BST->Left);
    } else if (BST->Data < X) {
      BST = Insert(X, BST->Right);
    } /* else 已经存在, 什么都不做 */
  }
  return BST;   /* 返回插入的结点 */
}

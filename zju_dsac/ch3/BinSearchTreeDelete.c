// Copyright [2019] <mituh>
// BinSearchTreeDelete.c
// 二叉搜索树中的删除

#include <stdlib.h>

#define ElementType int
typedef struct TNode *Position;
typedef Position BinTree;

struct TNode {
  ElementType Data;
  BinTree Left;
  BinTree Right;
};

/* 查找搜索二叉树中最小的元素 */
void FindMin(BST) {
  if (BST) {
    while (BST->Left) BST = BST->Left;
  }
  return BST;
}

/* 在搜索二叉树中删除某一元素结点 */
void Delete(ElementType X, BinTree BST) {
  Position Tmp;
  if (!BST) {
    printf("未找到该元素\n"); return;
  }
  if (X < BST->Data) {
    BST->Left = Delete(X, BST->Left);
  } else if (BST->Data < X) {
    BST->Right = Delete(X, BST->Right);
  } else {
    /* 找到需要删除的元素 */
    /* 删除结点有左右两个孩子结点 */
    if (BST->Left && BST->Right) {
      Tmp = FindMin(Tmp->Right);    /* 找到右子树最小元素 */
      BST->Data = Tmp->Data;
      BST->Right = Delete(BST->Data, BST->Right);
          /* 在右子树中递归删除最小元素 */
    } else {              /* 被删除结点只有一个孩子 或者 无孩子*/
      Tmp = BST;
      if (!BST->Left) {   /* 没有左孩子或者无孩子*/
        BST = BST->Right;
      } else if (!BST->Right) {  /* 只有左孩子或者无孩子 */
        BST = BST->Left;
      }
      free(Tmp);
    }
    return BST;
  }
}

// Copyright [2018] <mituh>
// BinSearchTreeFind.c
// 二叉搜索树中的查找

#define ElementType int
typedef struct TNode *Position;
typedef Position BinTree;

struct TNode {
  ElementType Data;
  BinTree Left;
  BinTree Right;
};


/* 从BST中查找元素X, 返回其结点地址 */

Position Find(BinTree BST, ElementType X) {
  if (!BST) return NULL;
  if (X < BST->Data) {
    return Find(BST->Left, X);   /* 在左子树递归查找 */
  } else if (X > BST->Data) {
    return Find(BST->Right, X);
  } else {  /* X == BST->Data */
    return BST;                  /* 查找成功, 返回当前结点地址 */
  }
}


Position IterFind(BinTree BST, ElementType X) {
  /* BST迭代查找元素X */
  // if (!BST) return NULL;
  while (BST) {
    if (BST->Data < X) {
      BST = BST->Right;
    } else if (X < BST->Data) {
      BST = BST->Left;
    } else {
      return BST;
    }
  }
  return NULL;
}

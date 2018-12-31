// Copyright [2018] <mituh>
// BinTree.cpp
// 二叉树的储存结构, 递归遍历

/* 储存结构 */
typedef int ElementType;
typedef struct TNode* Position;
typedef Position BinTree;
struct TNode {
  ElementType Data;   /* 结点数据 */
  BinTree Left;       /* 左子树 */
  BinTree Right;      /* 右子树 */
};



void PreOrderTraversal(BinTree BT) {
  /* 二叉树的前序遍历 */
  if (BT) {
    printf("%d\n", BT->Data);
    PreOrderTraversal(BT->Left);
    PreOrderTraversal(BT->Right);
  }
}

void InOrderTraversal(BinTree BT) {
  /* 二叉树的中序遍历 */
  if (BT) {
    InOrderTraversal(BT->Left);
    printf("%d\n", BT->Data);
    InOrderTraversal(BT->Right);
  }
}

void PostOrderTraversal(BinTree BT) {
  /* 二叉树的后序遍历 */
  if (BT) {
    PostOrderTraversal(BT->Left);
    PostOrderTraversal(BT->Right);
    printf("%d\n", BT->Data);
  }
}

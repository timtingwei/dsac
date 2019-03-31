/* Copyright [2019] <mituh> */
/* 4.5/6.c */
/* 判断二叉树是否为二叉排序树 */

/*
错误版本:
int IsBST(BiTree T) {
  if (T == NULL) {    // 空树是BST
    return 1;
  }
  if (T->lchild->data < T->data
      && T->data < T->rchild->data) {
    return IsBST(T->lchild) && IsBST(T->rchild);  // 判断左子树右子树
  } else {
    return 0;     // 顺序不满足左孩子<根结点<右孩子
  }
}
*/

/* 中序遍历, 前继结点与当前结点比较, 改进版本 */
int prev = -99999;    /* 前继结点数值, 初始为无穷小 */
int IsBST(BiTree T) {
  if (T == NULL) {
    return 1;
  } else {
    b1 = IsBST(T->lchild);
    if (b1 == 0 || prev >= T->data) {
      return 0;
    }
    prev = T->data;
    b2 = IsBST(T->rchild);
    return b2;
  }
}

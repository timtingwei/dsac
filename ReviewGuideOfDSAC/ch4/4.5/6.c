/* Copyright [2019] <mituh> */
/* 4.5/6.c */
/* 判断二叉树是否为二叉排序树 */

int IsBST(BiTree T) {
  if (T == NULL) {    /* 空树是BST */
    return 1;
  }
  if (T->lchild->data < T->data
      && T->data < T->rchild->data) {
    return IsBST(T->lchild) && IsBST(T->rchild);  /* 判断左子树右子树 */
  } else {
    return 0;     /* 顺序不满足左孩子<根结点<右孩子 */
  }
}

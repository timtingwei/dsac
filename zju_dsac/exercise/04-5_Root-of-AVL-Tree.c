/* Copyright [2019] <mituh> */
/* 04-5_Root-of-AVL-Tree.c */
/* 平衡二叉树的旋转 */


/* 求树的高度 */
int GetHeight(AVLTree T) {
  int HL, HR, MaxH;

  if (T) {
    HL = GetHeight(T->Left);     /* 求左子树的高度 */
    HR = GetHeight(T->Right);    /* 求右子树的高度 */
    MaxH = HL > HR ? HL : HR;    /* 取较大的高度 */
    return (MaxH + 1);
  } else {
    return 0;   /* 空树高度为0 */
  }
}

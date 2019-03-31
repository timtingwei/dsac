/* Copyright [2019] <mituh> */
/* 4.5/8.c */
/* 利用二叉树遍历思想, 判断是否为平衡二叉树 */

int GetHeight(BiTree T) {
  if (T == NULL) return 0;
  int HL, HR;
  HL = GetHeight(T->lchild);
  HR = GetHeight(T->rchild);
  return (HL > HR) ? HL + 1 : HR + 1;
}

/* 判断时会重复计算子树的高度! */
int IsAVL(BiTree T) {
  if (T == NULL) return 1;    /* 空树是平衡二叉树 */
  int HL, HR;
  HL = GetHeight(T->lchild); HR = GetHeight(T->rchild);
  if (abs(HL - HR) <= 1) {
    return IsAVL(T->lchild) && IsAVL(T->rchild);
  } else {
    return 0;
  }
}


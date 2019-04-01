/* Copyright [2019] <mituh> */
/* 4.5/8.c */
/* 利用二叉树遍历思想, 判断是否为平衡二叉树 */

/*
自己写的通俗方法:
int GetHeight(BiTree T) {
  if (T == NULL) return 0;
  int HL, HR;
  HL = GetHeight(T->lchild);
  HR = GetHeight(T->rchild);
  return (HL > HR) ? HL + 1 : HR + 1;
}

// 判断时会重复计算子树的高度!
int IsAVL(BiTree T) {
  if (T == NULL) return 1;    // 空树是平衡二叉树
  int HL, HR;
  HL = GetHeight(T->lchild); HR = GetHeight(T->rchild);
  if (abs(HL - HR) <= 1) {
    return IsAVL(T->lchild) && IsAVL(T->rchild);
  } else {
    return 0;
  }
}
*/


/* 判断二叉树是否为AVL树, 要想到后序遍历的思想 */
/* 讨论三种情况: 空树, 根结点, 其他 */
void JudgeAVL(BiTree bt, int &balance, int &h) {
  /* 平衡性和高度, 作为引用传入修改, 不作为返回值 */
  int bl = 0, hl = 0, br = 0, hr = 0;     /* 平衡标记和高度 */
  if (bt == NULL) {
    balance = 1;
    h = 0;
  } else if (bt->lchild == NULL && bt->rchild == NULL) {
    balance = 1;
    h = 1;
  } else {
    JudgeAVL(bt->lchild, bl, hl);
    JudgeAVL(bt->rchild, br, hr);    /* 判断左右子树, 得到修改平衡标记和高度 */
    h = (hl > hr ? hl : hr) + 1;
    if (abs(hl - hr) < 2) {
      balance = bl&&br;              /* 树的高度差满足, 平衡性也需要满足 */
    } else {
      balance = 0;
    }
  }
}



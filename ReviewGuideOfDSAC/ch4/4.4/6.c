/* Copyright [2019] <mituh> */
/* 4.4/6.c */
/* 孩子兄弟表示法存储的树求树高 */

/* 孩子-兄弟存储 */
typedef struct CSNode {
  ElementType data;
  struct CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;

/* 递归求高度 */
/* 计算的原来二叉树树高??? */
int GetHeight(CSTree T) {
  if (T == NULL) return 0;
  int HC, HB;    /* 左孩子与右兄弟子树的树高 */
  HC = GetHeight(T->firstchild);
  HB = GetHeight(T->nextsibling);
  /* 错误: */
  /* return (HL > HR) ? HL + 1 : HR + 1; 左右子树中较大者高度, 本身高度算1*/
  /* 正确的版本, 还是有点不理解为什么要+1 */
  if (HC + 1 > HB) {    /* 返回第一个孩子高度+1与兄弟结点高度的较大者 */
    return HC + 1;
  } else {
    return HB;
  }
}

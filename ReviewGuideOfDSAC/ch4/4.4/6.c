/* Copyright [2019] <mituh> */
/* 4.4/6.c */
/* 孩子兄弟表示法存储的树求树高 */

/* 孩子-兄弟存储 */
typedef struct CSNode {
  ElementType data;
  struct CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;

/* 递归求高度 */
int GetHeight(CSTree T) {
  if (T == NULL) return 0;
  int HL, HR;    /* 左孩子与右兄弟子树的树高 */
  HL = GetHeight(T->firstchild);
  HR = GetHeight(T->nextsibling);
  return (HL > HR) ? HL + 1 : HR + 1;    /* 左右子树中较大者高度, 本身高度算1*/
}

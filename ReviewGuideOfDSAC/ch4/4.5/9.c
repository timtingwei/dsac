/* Copyright [2019] <mituh> */
/* 4.5/9.c */
/* 求二叉排序树中， 最小和最大的关键字 */

/* 最小关键字 */
#define ERROR -1
int FindMin(BiTree T) {
  if (T == NULL) return ERROR;    /* 空树没有最小关键字 */
  BiTree P;                       /* 工作指针 */
  p = T;
  while (p->lchild != NULL)  p = p->lchild;    /* 向左走 */
  return p.data;
}


/* 最大关键字 */
int FindMax(BiTree T) {
  if (T == NULL) return ERROR;    /* 空树没有最大关键字 */
  BiTree P;                       /* 工作指针 */
  p = T;
  while (p->rchild != NULL)  p = p->rchild;    /* 向右走 */
  return p.data;                               /* 走到最右就返回该结点的值 */
}


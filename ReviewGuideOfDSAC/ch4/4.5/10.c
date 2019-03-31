/* Copyright [2019] <mituh> */
/* 4.5/10.c */
/* 从大到小输出二叉排序树中值不小于k的关键字 */

#include <stdio.h>
/* 非递归中序遍历, 将不小于k的值入栈, 再统一逆序输出 */
void PrintMoreThanK(BiTree T, int k) {
  Stack KS, InS;     /* 一个存不小于k的栈, 一个存中序遍历结点的栈 */
  BiTree p;
  p = T;       /* 中序不要临时结点r, 与后序不同 */
  InitStack(KS); InitStack(InS);
  while (p || !IsEmpty(Ins)) {
    if (p) {             /* 工作结点不空 */
      push(Ins, p);
      p = p->lchild;     /* 向左走 */
    } else {             /* 工作结点为空 */
      pop(InS, p);       /* 根结点从栈中弹出 */
      if (p->data >= k) {
        push(KS, p->data);   /* 若不小于k, 把p的值压入栈 */
      }
      if (p->rchild != NULL) {
        p = p->rchild;       /* 向右走 */
        push(InS, p);
        p = p->lchild;       /* 向左走 */
      } else {
        p = NULL;            /* 没有右结点的话, 置空, 让上一结点下一次出栈 */
      }
    }
  }
  int v;
  /* 将栈中的元素输出 */
  while (!IsEmpty(KS)) {
    pop(KS, v);
    printf("%d\n", v);       /* 输出元素 */
  }
}

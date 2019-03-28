/* Copyright [2019] <mituh> */
/* 4.3/4.c */
/* 二叉树自下向上, 从右到左的层序遍历算法 */

/* 暂时想到的方法: 在层序遍历的基础上, 用栈存访问的结点,
   再利用栈的特性, 逆序打印 */
void reverse_LevelOrder(BinTree T) {
  Stack S; Queue Q;
  BinTree p;
  if (T != NULL) {    /* 别忘了! */
    InitStack(S); InitQueue(Q);
    p = T;
    EnQueue(Q, p);
    while (!IsEmpty(Q)) {
      DeQueue(Q, p);
      push(S, p);
      if (p->lchild != NULL) {
        EnQueue(Q, p->lchild);
      }
      if (p->rchild != NULL) {
        EnQueue(Q, p->rchild);
      }
    }  // while
    while (!IsEmpty(S)) {
      pop(S, p);
      Visit(p->data);
    }  // while
  }
}

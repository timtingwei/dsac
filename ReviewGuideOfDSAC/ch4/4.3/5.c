/* Copyright [2019] <mituh> */
/* 4.3/5.c */
/* 非递归求二叉树高度 */

/* 层序遍历, level记层数, last指向当前层最后一个结点,
   front工作指针, rear队列最后元素. 工作指针到last时候, level++ */

/* 非递归层序遍历求二叉树高度 */
int GetHeight(BinTree T) {
  if (T == NULL) return 0;   /* 树空 */
  int front, rear, last, level;
  BinTree p;
  front = -1; rear = -1;
  last = 0; level = 0;   /* last指向下一层最后一个结点 */
  BinTree[MaxSize] Q;    /* 队列用数组构造!! */
  Q[++rear] = T;         /* 根结点入队 */
  while (front < rear) {   /* 队列非空 */
    p = Q[++front];        /* 神奇的出队操作.. */
    if (p->lchild) {
      Q[++rear] = p;
    }
    if (p->rchild) {
      Q[++rear] = p;
    }
    if (front == last) {    /* 工作指针指向下一层最后元素 */
      level++;
      last = rear;          /* 这时下一层所有结点已经入队, rear指向最右元素 */
    }
  }
  return level;
}

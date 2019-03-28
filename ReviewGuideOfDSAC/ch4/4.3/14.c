/* Copyright [2019] <mituh> */
/* 4.3/14.c */
/* 求二叉树宽度(具有结点数最多的那一层的结点个数) */

int GetWidth(BinTree T) {
  if (T == NULL) return 0;       /* 空树 */
  int front, rear, last, width, cnt;
  BinTree p;
  front = -1; rear = -1;
  last = 0; width = 0;    /* last指向下一层最右 */
  BinTree Q[MaxSize];     /* 用数组表示队列 */
  Q[++rear] = T;          /* 根结点入队 */
  cnt = 0;
  while (front < rear) {     /* 队列非空 */
    p = Q[++front]; cnt++;
    if (p->lchild)  Q[++rear] = p->lchild;
    if (p->rchild)  Q[++rear] = p->rchild;
    if (front == last) {    /* 工作结点指向该层最后一个结点 */
      if (cnt > width) width = cnt;    /* 刷新宽度 */
      cnt = 0;                         /* 下一层计数器置空 */
      last = rear;                     /* last指向下一层最右 */
    }
  }
  return width;
}

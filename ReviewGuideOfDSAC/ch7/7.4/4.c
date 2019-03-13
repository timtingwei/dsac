/* Copyright [2019] <mituh> */
/* 7.4/4.c */
/* 简单选择排序的链表实现 */

void selectSort(LinkedList L) {
  LinkedNode *h, *p, *q, *s, *r;
  h = L;
  L = NULL;
  while (h != NULL) {
    p = s = h; q = r = NULL;   /* p, q是工作和工作前继, sr是最终记录和记录前继*/
    while (p != NULL) {
      if (p->Data > s->Data) {
        s = p; r = q;
      }
      q = p; p = p->Link;
    }
    if (s == h) {    /* 最大结点在头部 */
      h = h->Link;   /* 向后移一位 */
    } else {         /* 在表的中间 */
      r->Link = s->Link;     /* 原来表中跳过s */
    }
    s->Link = L; L = s;      /* 在新的表头插入的一种方法 */
  }
}

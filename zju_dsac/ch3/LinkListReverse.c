// Copyright [2019] <mituh>
// LinkListReverse.c
// 单链表的逆转


/* 每k个逆序 */
Ptr Reverse(Ptr head, int K) {
  int cnt = 1;
  new = head->next;
  old = new->next;
  while (cnt < K) {
    tmp = old->next;
    old->next = new;
    new = old; old = tmp;
    cnt++;
  }
  head->next->next = old;
  return new;
}

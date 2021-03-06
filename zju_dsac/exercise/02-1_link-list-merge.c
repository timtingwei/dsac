// Copyright[2018] <mituh>
// 02-1_link-list-merge.c

List Merge(List L1, List L2) {
  List L;
  L = (List)malloc(sizeof(struct Node));
  List pa = L1->Next, pb = L2->Next, pc = L;
  while (pa && pb) {
    if (pa->Data <= pb->Data) {
      pc->Next = pa;
      pc = pa;
      pa = pa->Next;
    } else {
      pc->Next = pb;
      pc = pb;
      pb = pb->Next;
    }
  }
  if (pa) pc->Next = pa;
  if (pb) pc->Next = pb;
  L1->Next = NULL; L2->Next = NULL;
  return L;
}


/*
List Merge(List L1, List L2) {
  List L;
  L = (List)malloc(sizeof(struct Node));
  List pa = L1, pb = L2, pc = NULL;
  while (pa && pb) {
    if (pa->Data <= pb->Data) {
      if (!L) {
        L = pa;
      } else {
        pc->Next = pa;
      }
      pc = pa;
      pa = pa->Next;
    } else {
      if (!L) {
        L = pb;
      } else {
        pc->Next = pb;
      }
      pc = pb;
      pb = pb->Next;
    }
  }
  if (pa) pc->Next = pa;
  if (pb) pc->Next = pb;
  L1 = NULL; L2 = NULL;
  return L;
}
*/

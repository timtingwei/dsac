// copyright [2018] <mituh>
#include <stdio.h>
#include "LinkQueue.c"

// test
int main() {
  LinkQueue Q; QElemType e;
  InitQueue(&Q);
  EnQueue(&Q, 3);
  EnQueue(&Q, 4);
  EnQueue(&Q, 5);
  DeQueue(&Q, &e);
  printf("%d\n", e);
  DestroyQueue(&Q);

  return 0;
}

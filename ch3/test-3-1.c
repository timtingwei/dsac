// copyright [2018] <mituh>
// test-3-1.c

#include <stdio.h>
#include "SqStack.c"

int main() {
  SqStack S;
  InitStack(&S);

  int e = 6, e2;
  Push(&S, 5);
  GetTop(S, &e2);
  printf("%d\n", e2);
  Push(&S, 6);
  Push(&S, 7);
  Push(&S, 8);
  GetTop(S, &e2);
  printf("%d\n", e2);
  Pop(&S, &e2);
  printf("pop=%d\n", e2);
  GetTop(S, &e2);
  printf("top=%d\n", e2);

  return 0;
}


// Copyright [2018] <mituh>
// printN.cpp

/*
#include <cstdio>
int main() {
  int N; scanf("%d", &N);
  int i;
  for (i = 1; i <= N; i++) {
    printf("%d\n", i);
  }
  return 0;
}
*/

#include <cstdio>

void printN(int n) {
  if (n == 1) {
    printf("%d\n", n);
    return;
  }
  printN(n-1); printf("%d\n", n);
}

int main() {
  int N; scanf("%d", &N);
  printN(N);
  return 0;
}

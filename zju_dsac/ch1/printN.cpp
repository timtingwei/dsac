// Copyright [2018] <mituh>
// printN.cpp

/*
// 循环的写法
#include <cstdio>
void printN(int n) {
  int i;
  for (i = 1; i <= N; i++) {
    printf("%d\n", i);
  }
}
*/

/*
// 自己写的递归
#include <cstdio>
void printN(int n) {
  if (n == 1) {
    printf("%d\n", n);
    return;
  }
  printN(n-1); printf("%d\n", n);
}
*/

/*
// 更新递归
void printN(int n) {
  if (n) {
    printN(n-1); printf("%d\n", n);
  }
  return;
}
*/

#include <cstdio>
#include <ctime>

void printN_loop(int n) {
  int i;
  for (i = 1; i <= n; i++) {
    printf("%d\n", i);
  }
}

void printN_recursive(int n) {
  if (n) {
    printN_recursive(n-1); printf("%d\n", n);
  }
  return;
}

clock_t first, second, third;
double duration1, duration2;
int main() {
  int N; scanf("%d", &N);
  first = clock();
  printN_loop(N);
  second = clock();
  printN_recursive(N);
  third = clock();

  duration1 = ((double)(second-first))/CLOCKS_PER_SEC;   // CLK_TCK
  duration2 = ((double)(third-second))/CLOCKS_PER_SEC;
  printf("printN_loop(), N = %d, time = %.3lf\n", N, duration1);
  printf("printN_recursive(), N = %d, time = %.3lf\n", N, duration2);
  return 0;
}

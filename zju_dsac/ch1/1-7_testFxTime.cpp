// Copyright [2018] <mituh>
// 1-7_testFxTime.cpp

#include <cstdio>
#include <ctime>
#include <cmath>

#define MAXN 10    /* 多项式的最大项数 阶数+1 */
#define MAXK 1e7   /* 被测函数最大调用次数 */

clock_t start, stop;
double duration1, duration2;


double f1(int n, double a[], double x) {
  double ans = a[0];
  int i;
  for (i = 0; i <= n; i++) {
    ans += a[i]*pow(x, i);
  }
  return ans;
}

double f2(int n, double a[], double x) {
  double ans = a[n];
  int i;
  for (i = n-1; i > 0; i--) {
    ans = ans * x + a[i-1];
  }
  return ans;
}

int main() {
  int i;
  double a[MAXN];

  for (i = 0; i < MAXN; i++) a[i] = (double)i;

  start = clock();
  f1(MAXN-1, a, 1.12212);
  stop = clock();
  printf("ticks = %lu\n", stop-start);
  printf("duration = %.3lf\n", ((double)(stop-start))/CLOCKS_PER_SEC);

  start = clock();
  f2(MAXN-1, a, 1.12212);
  stop = clock();
  printf("ticks = %lu\n", stop-start);
  printf("duration = %.3lf\n", ((double)(stop-start))/CLOCKS_PER_SEC);

  return 0;
}

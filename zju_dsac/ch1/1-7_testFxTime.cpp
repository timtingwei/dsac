// Copyright [2018] <mituh>
// 1-7_testFxTime.cpp
// 测试求多项式值的两种算法的时间, 抽象测试函数
#include <cstdio>
#include <ctime>
#include <cmath>

#define MAXN 10    /* 多项式的最大项数 阶数+1 */
#define MAXK 1e7   /* 被测函数最大调用次数 */

clock_t start, stop;
double duration;


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

void run(double(*f)(int, double*, double), double a[], int case_n) {
  int i;
  start = clock();
  for (i = 0; i < MAXK; i++) {
    (*f)(MAXN-1, a, 1.12212);
  }
  stop = clock();
  duration = ((double)(stop-start)) / CLOCKS_PER_SEC;
  printf("ticks%d = %f \n", case_n, (double)stop-start);
  printf("duration%d = % 6.2e \n", case_n, duration);
}

int main() {
  int i;
  double a[MAXN];

  for (i = 0; i < MAXN; i++) a[i] = (double)i;

  run(f1, a, 1);
  run(f2, a, 2);
  return 0;
}

/*
ticks1 = 3400957.000000 
duration1 =  3.40e+00 
ticks2 = 275551.000000 
duration2 =  2.76e-01 
*/
 

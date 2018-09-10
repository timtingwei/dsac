// Copyright [2018] <mituh>
// 1-4_fx.cpp

// 直接法
#include <cstdio>
#include <cmath>

double f(int n, double a[], double x) {
  double ans = a[0];
  int i;
  for (i = 1; i <= n; i++) {
    ans += a[i]*pow(x, i);
  }
  return ans;
}

double a[] = {2, 3, 4};
int n = 3;
double rst;

int main() {
  rst = f(n, a, 1000);
  printf("%.3lf", rst);
  return 0;
}

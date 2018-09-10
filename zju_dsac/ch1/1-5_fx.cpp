// Copyright [2018] <mituh>
// 1-5_fx.cpp

// 秦九韶法
#include <cstdio>
#include <cmath>

double f(int n, double a[], double x) {
  double ans = a[n];
  int i;
  for (i = n-1; i > 0; i--) {
    ans = ans * x + a[i-1];
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

// 3002.000


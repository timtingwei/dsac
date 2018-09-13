// Copyright [2018] <mituh>
// testMaxSubseqSum.cpp
#include <cstdio>
#include <ctime>

int maxSubseqSum1(int A[], int N) {
  int maxSum = 0, thisSum;
  int i, j, k;
  for (i = 0; i <= N-1; i++) {
    for (j = 0; j <= N-1; j++) {
      thisSum = 0;
      for (k = i; k <= j; k++) {
        thisSum += A[k];
      }
      if (thisSum > maxSum) maxSum = thisSum;
    }
  }
  return maxSum;
}

int maxSubseqSum2(int A[], int N) {
  int maxSum = 0, thisSum;
  int i, j;
  for (i = 0; i <= N-1; i++) {
    thisSum = 0;
    for (j = i; j <= N-1; j++) {
      thisSum += A[j];
      if (thisSum > maxSum) maxSum = thisSum;
    }
  }
  return maxSum;
}

int max(int a, int b, int c) {
  return a > b ? a > c ? a : c : b > c ? b : c;
}

int divideAndConquer(int A[], int left, int right) {
  int maxLeftSum, maxRightSum;
  int leftBorderSum, rightBorderSum;
  int maxLeftBorderSum = 0, maxRightBorderSum = 0;
  int center, i;
  if (left == right) {
    if (A[left] > 0) {
      return A[left];
    } else {
      return 0;
    }
  }
  center = (left+right)/2;
  maxLeftSum = divideAndConquer(A, left, center);
  maxRightSum = divideAndConquer(A, center+1, right);

  maxLeftSum = 0; leftBorderSum = 0;
  for (i = center; i >= left; i--) {
    leftBorderSum += A[i];
    if (leftBorderSum > maxLeftBorderSum) maxLeftBorderSum = leftBorderSum;
  }

  maxRightSum = 0; rightBorderSum = 0;
  for (i = center+1; i <= right; i++) {
    rightBorderSum += A[i];
    if (rightBorderSum > maxRightBorderSum) maxRightBorderSum = rightBorderSum;
  }

  return max(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}

int maxSubseqSum3(int A[], int N) {
  int maxSum = divideAndConquer(A, 0, N-1);
  return maxSum;
}

int maxSubseqSum4(int A[], int N) {
  int maxSum = 0, thisSum = 0;
  int i;
  for (i = 0; i <= N-1; i++) {
    thisSum += A[i];
    if (thisSum > maxSum) {
      maxSum = thisSum;
    } else if (thisSum < 0) {
      thisSum = 0;
    }
  }
  return maxSum;
}

clock_t start, stop;
double duration;

void run(int(* f)(int*, int), int A[], int N, int case_n) {
  int i, ans;
  start = clock();
  ans = (*f)(A, N);
  stop = clock();
  duration = ((double)(stop-start))/CLOCKS_PER_SEC;
  // printf("case%d, ans = %d\n", case_n, ans);
  printf("ticks%d = %.2f\n", case_n, (double)(stop-start));
  printf("duration%d = %6.2e\n", case_n, duration);
}

#define MAXN 100000
int A[MAXN];
int main() {
  // int A[] = {-1, 3, 2, 3, 4,
  //            -2, 3, 4, 2, -2,
  //            -3, -2, 7, 2, -3,
  //            5, 1, -2, 3, 4}, N = 15;

  int N; scanf("%d", &N);
  int i;
  for (i = 0; i < N; i++) {
    // A[i] = i/2+i/3+(i+1)%10;
    if ((i+1)%2) {
      A[i] = (-1)*i/2 + i;
    } else {
      A[i] = i/2 + (i+1)%10;
    }
  }
  // run(maxSubseqSum1, A, N, 1);
  // run(maxSubseqSum2, A, N, 2);
  run(maxSubseqSum3, A, N, 3);
  run(maxSubseqSum4, A, N, 4);
  return 0;
}

/*
N = 1
ticks1 = 3.00
duration1 = 3.00e-06
ticks2 = 2.00
duration2 = 2.00e-06
ticks3 = 2.00
duration3 = 2.00e-06
ticks4 = 1.00
duration4 = 1.00e-06

N = 10
ticks1 = 5.00
duration1 = 5.00e-06
ticks2 = 3.00
duration2 = 3.00e-06
ticks3 = 1.00
duration3 = 1.00e-06
ticks4 = 1.00
duration4 = 1.00e-06

100
ticks1 = 640.00
duration1 = 6.40e-04
ticks2 = 21.00
duration2 = 2.10e-05
ticks3 = 10.00
duration3 = 1.00e-05
ticks4 = 2.00
duration4 = 2.00e-06

ticks1 = 390495.00
duration1 = 3.90e-01
ticks2 = 1299.00
duration2 = 1.30e-03
ticks3 = 51.00
duration3 = 5.10e-05
ticks4 = 3.00
duration4 = 3.00e-06

10000
tick1..
tick2..

ticks3 = 579.00
duration3 = 5.79e-04
ticks4 = 29.00
duration4 = 2.90e-05
*/

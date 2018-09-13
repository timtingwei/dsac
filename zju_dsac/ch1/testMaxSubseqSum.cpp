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
  int maxLeftBorderSum, maxRightBorderSum;
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

  leftBorderSum = 0;
  for (i = center; i >= left; i--) {
    leftBorderSum += A[i];
    if (leftBorderSum > maxLeftBorderSum) maxLeftBorderSum = leftBorderSum;
  }

  rightBorderSum = 0;
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
  int i;
  start = clock();
  (*f)(A, N);
  stop = clock();
  duration = ((double)(stop-start))/CLOCKS_PER_SEC;
  printf("ticks%d=%f\n", case_n, (double)(stop-start));
  printf("duration%d=% 6.2e\n", case_n, duration);
}

int main() {
  int A[] = {-1, 3, 2, 3, 4, -2, 3, 4, 2, 9, 10, -2}, N = 12;
  run(maxSubseqSum1, A, N, 1);
  run(maxSubseqSum2, A, N, 2);
  run(maxSubseqSum3, A, N, 3);
  run(maxSubseqSum4, A, N, 4);
  return 0;
}

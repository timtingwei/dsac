// Copyright [2018] <mituh>
// 1-13_maxSubseqSum3.cpp
// Tn:NlogN

#include <cstdio>

int max(int a, int b, int c) {
  return a > b ? a > c ? a : c : b > c ? b : c;
}

int divideAndConquer(int A[], int left, int right) {
  int maxLeftSum, maxRightSum;
  int maxLeftBorderSum, maxRightBorderSum;

  int leftBorderSum, rightBorderSum;
  int center, i;
  if (left == right) {
    if (A[left] > 0) {
      return A[left];
    } else {
      return 0;
    }
  }

  center = (left+right) / 2;
  maxLeftSum = divideAndConquer(A, left, center);
  maxRightSum = divideAndConquer(A, center+1, right);

  leftBorderSum = 0; maxLeftBorderSum = 0;
  for (i = center; i >= left; i--) {
    leftBorderSum += A[i];
    if (leftBorderSum > maxLeftBorderSum) {
      maxLeftBorderSum = leftBorderSum;
    }
  }

  rightBorderSum = 0; maxRightBorderSum = 0;
  for (i = center+1; i <= right; i++) {
    rightBorderSum += A[i];
    if (rightBorderSum > maxRightBorderSum) {
      maxRightBorderSum = rightBorderSum;
    }
  }

  return max(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}

int main() {
  int A[] = {4, -3, 5, -2, -1, 2, 6, -2}, N = 8;
  int rst = divideAndConquer(A, 0, N-1);
  printf("%d\n", rst);
  return 0;
}

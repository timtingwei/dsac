// Copyright [2018] <mituh>
// 1-11_maxSubseqSum1.cpp
// Tn:O(n^3)
int maxSubseqSum1(int A[], int N) {
  int i, j, k;
  int thisMax, maxSum = INT_MIN;
  for (i = 0; i < N; i++) {
    for (j = i; j < N; j++) {
      thisMax = 0;
      for (k = i; k <= j; k++) {
        thisMax += A[k];
      }
      maxSum = (thisMax > maxSum) ? thisMax : maxSum;
    }
  }
  return maxSum;
}

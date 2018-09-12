// Copyright [2018] <mituh>
// 1-12_maxSubseqSum2.cpp
// Tn:O(n^2)
int maxSubseqSum2(int A[], int N) {
  int i, j;
  int thisMax, maxSum = INT_MIN;
  for (i = 0; i < N; i++) {
    thisMax = 0;
    for (j = i; j < N; j++) {
      thisMax += A[j];
      maxSum = (thisMax > maxSum) ? thisMax : maxSum;
    }
  }
  return maxSum;
}

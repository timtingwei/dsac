// Copyright [2018] <mituh>
// 1-14_maxSubseqSum4.cpp
// Tn:O(n)
int maxSubseqSum2(int A[], int N) {
  int i;
  int thisMax = 0, maxSum = INT_MIN;
  for (i = 0; i < N; i++) {
    thisMax += A[i];
    if (thisMax > maxSum) {
      maxSum = thisMax;
    } else if (thisMax < 0) {
      thisMax = 0;
    }
  }
  return maxSum;
}

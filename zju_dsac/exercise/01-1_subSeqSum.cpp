// Copyright [2018] <mituh>
// 01-1_subSeqsum.cpp

#include <cstdio>

/*
int maxSubseqSum4(int a[], int N) {
  int maxSum = 0, thisSum;
  int i;
  for (i = 0; i < N; i++) {
    thisSum += a[i];
    if (thisSum > maxSum) {
      maxSum = thisSum;
    } else if (thisSum < 0) {
      thisSum = 0;
    }
  }
  return maxSum;
}
*/
int maxSubseqSum1(int A[], int N) {
  int maxSum = 0, thisSum;
  int i, j;
  for (i = 0; i < N; i++) {
    thisSum = 0;
    for (j = i; j < N; j++) {
      thisSum += A[j];
      if (thisSum > maxSum) maxSum = thisSum;
    }
  }
  return maxSum;
}

int a[100050];
int main() {
  int K; scanf("%d", &K);
  for (int i = 0; i < K; i++) {
    scanf("%d", &a[i]);
  }
  int ans = maxSubseqSum1(a, K);
  printf("%d", ans);
  return 0;
}

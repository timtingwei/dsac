// Copyright [2018] <mituh>
// 01-2_maximum-subsequence-sum.cpp

#include <cstdio>

int A[10050];
int main() {
  int K; scanf("%d", &K);
  int maxSum = -1, thisSum = 0;    // debug:case4, 0和负数
  int head = 0, tail = K-1, len = 0, max_len = 0;
  int i;
  for (i = 0; i < K; i++) {
    scanf("%d", &A[i]);
    thisSum += A[i]; len++;
    if (thisSum > maxSum) {
      maxSum = thisSum;
      tail = i; max_len = len;
    } else if (thisSum < 0) {
      thisSum = 0;
      len = 0;
    }
  }
  if (maxSum < 0) {               // 全是负数
    maxSum = 0; head = 0; tail = K-1;
  } else {
    head = tail-max_len+1;        // debug tail-max_len+1
  }
  printf("%d %d %d", maxSum, A[head], A[tail]);
  return 0;
}

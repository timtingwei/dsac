/* Copyright [2019] <mituh> */
/* 7.3/2.c */
/* 双向起泡 */
#include <stdio.h>
typedef int ElementType;
void Swap(ElementType *a, ElementType *b) {
  ElementType temp;
  temp = *a; *a = *b; *b = temp;
}

void Bubble_Sort_Double(ElementType A[], int N) {
  int p, left, right, flag;
  left = 0; right = N-1; flag = 0;
  while (left < right) {
    if (!flag) {
      for (p = left; p < right; p++) {
        if (A[p] > A[p+1]) Swap(&A[p], &A[p+1]);
      }
      right--; flag = 1;
    } else {
      for (p = right; p > left; p--) {
        if (A[p] < A[p-1]) Swap(&A[p], &A[p-1]);
      }
      left++; flag = 0;
    }
  }
}

int main() {
  ElementType A[] = {3, 2, 1, 4, 8, 9, 0};
  int N, i;
  N = 7;
  Bubble_Sort_Double(A, N);
  for (i = 0; i < N; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
  return 0;
}

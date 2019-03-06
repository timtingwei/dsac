/* Copyright [2019] <mituh> */
/* Quick_Sort.c */
/* 快速排序, 严奶奶版本, 取首元素作为主元 */
#include <stdio.h>
typedef int ElementType;

int Partition(ElementType A[], int low, int high) {
  ElementType privot;
  privot = A[low];   /* 取首元素作为主元 */
  while (low < high) {
    while (low < high && A[high] >= privot) high--;
    A[low] = A[high];   /* 比主元小放到左边 */
    while (low < high && A[low] <= privot) low++;
    A[high] = A[low];   /* 比主元大放到右边 */
  }
  A[low] = privot;     /* 最后放主元 */
  return low;
}

void QSort(ElementType A[], int low, int high) {
  int privot_p, num;
  num = high - low + 1;
  if (num > 1) {    /* 如果只剩下一个或者不剩下长度, return出来 */
    privot_p = Partition(A, low, high);
    QSort(A, low, privot_p-1);
    QSort(A, privot_p+1, high);
  }
}

void Quick_Sort(ElementType A[], int N) {
  QSort(A, 0, N-1);
}

int main() {
  ElementType A[] = {8, 1, 4, 9, 0, 3, 5, 2, 7, 6, 11, 12, 13, -2};
  int N, i;
  N = 14;
  Quick_Sort(A, N);
  for (i = 0; i < N; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
  return 0;
}


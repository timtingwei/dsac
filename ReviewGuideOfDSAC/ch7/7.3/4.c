/* Copyright [2019] <mituh> */
/* 7.3/4.c */
/* 排快用随机函数选取主轴, 划分表，两种partition的写法 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElementType;

void Swap(ElementType *a, ElementType *b) {
  ElementType temp;
  temp = *a; *a = *b; *b = temp;
}

/* 随机选择主轴进行划分 */
int Partition2(ElementType A[], int low, int high) {
  int i, j, rand_index;
  ElementType privot;
  rand_index = rand()%(high-low+1) + low;
  Swap(&A[low], &A[rand_index]);
  privot = A[low];
  i = low;
  for (j = low+1; j <= high; j++) {
    if (A[j] < privot) {
      Swap(&A[++i], &A[j]);
    }
  }
  Swap(&A[i], &A[low]);
  return i;
}


/*
int Partition2(ElementType A[], int low, int high) {
  int i, j, rand_index;
  ElementType privot;
  rand_index = rand()%(high-low+1) + low;
  Swap(&A[low], &A[rand_index]);
  privot = A[low];
  while (low < high) {
    while (low < high && A[high] >= privot) high--;
    A[low] = A[high];
    while (low < high && A[low] <= privot) low++;
    A[high] = A[low];
  }
  A[low] = privot;
  return low;
}
*/

int main() {
  srand((unsigned)time(NULL));
  ElementType A[] = {3, 2, 1, 8, 4, 9, 7};
  int p, i, N;
  N = 7;
  p = Partition2(A, 0, N-1);
  printf("%d\n", p);
  for (i = 0; i < N; i++) { printf("%d ", A[i]);}
  printf("\n");
  return 0;
}

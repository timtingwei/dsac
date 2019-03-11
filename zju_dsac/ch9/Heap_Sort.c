/* Copyright [2019] <mituh> */
/* Heap_Sort.c */
/* 堆排序, 建成最大堆, 数组最后一位和堆顶交换, 剩下的调成最大堆 */
#include <stdio.h>
typedef int ElementType;

void Swap(int *a, int *b) {
  int temp;
  temp = *a; *a = *b; *b = temp;
}

void AdjustDown(ElementType A[], int k, int N) {
  /* 把将下标为k的结点为根的树, 调整成最大堆 */
  int i;
  A[0] = A[k];
  for (i = k*2; i <= N; i *= 2) {
    /* 下滤 */
    if (i < N && A[i] < A[i+1]) {
      i++;    /* 找到两个子结点中较大者 */
    }
    if (A[0] >= A[i]) {
      break;
    } else {
      A[k] = A[i];  /* A[i]调整到双亲结点上 */
      k = i;
    }
  }
  A[k] = A[0];
}

void BuildHeap(ElementType A[], int N) {
  int i;
  for (i = N/2; i > 0; i--) {   /* 从数组最后一个父结点开始到根 */
    AdjustDown(A, i, N);   /* 每棵树调整成一个最大堆 */
  }
}

void Heap_Sort(ElementType A[], int N) {
  int i;
  /* 数组A要求从1~N放置(完全二叉树) */
  for (i = N-1; i >= 0; i--) {
    A[i+1] = A[i];
  }
  /* 建成大顶堆 */
  BuildHeap(A, N);
  for (i = N; i > 1; i--) {  /* 注意i和堆的规模的关系, 是-1!! */
    Swap(&A[i], &A[1]);      /* 最大堆堆顶放到数组最后一个 */
    AdjustDown(A, 1, i-1);   /* 规模缩小后堆调整, 跟del比不需要额外的空间 */
  }
  /* 重新将数组A移回0~N-1 */
  for (i = 0; i < N; i++) {
    A[i] = A[i+1];
  }
}

/* 在堆中插入后 从底向上的代码 */
void AdjustUp(ElementType A[], int k, int N) {
  A[0] = A[k];
  for ( ; k > 1 && A[k/2] < A[0]; k /= 2) {
    A[k] = A[k/2];   /* 上滤 */
  }
  A[k] = A[0];
}

int main() {
  ElementType A[15] = {8, 1, 4, 9, 0, 3, 5, 2, 7, 6};
  int N, i;
  N = 10;
  int a, b;
  Heap_Sort(A, N);
  for (i = 0; i < N; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
  return 0;
}

// Update
// Update
// Update
// Update
// Update

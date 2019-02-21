/* Copyright [2019A] <mituh> */
/* SimpleSelection_Sort.c */
/* 简单的选择排序 */


/* 在未排序的序列中选出最小的元素和序列的首位交换,
   接下来在剩余的未排序序列中再选中最小元素与序列的第二位元素交换, 类推 */

#define ElementType int

void Swap(ElementType *a, ElementType *b) {
  ElementType t;
  t = *a;
  *a = *b;
  *b = t;
}

void SimpleSelection_Sort(ElementType A[], int N) {
  int i, j, min;

  for (i = 0; i < N-1; i++) {
    min = i;
    for (j = i+1; j < N; j++) {
      if (A[j] < A[min]) {
        min = j;
      }
    }
    if (min != i) {
      Swap(&A[i], &A[min]);
    }
  }
}

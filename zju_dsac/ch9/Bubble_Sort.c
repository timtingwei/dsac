/* Copyright [2019] <mituh> */
/* Bubble_Sort.c */
/* 冒泡排序 */

void Bubble_Sort(ElementType A[], int N) {
  int i, P, flag;

  for (P = N-1; P >= 0; P--) {
    flag = 0;
    for (i = 0; i < P; i++) {
      if (A[i] > A[i+1]) {
        Swap(A[i], A[i+1]);
        flag = 1;
      }
    }
    if (!flag) break;    /* 已有序, 未发生交换 */
  }
}

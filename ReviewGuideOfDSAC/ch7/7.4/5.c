/* Copyright [2019] <mituh> */
/* 7.4/5.c */
/* 判断小根堆 */

int IsMinHeap(ElementType A[], int N) {
  /* A是从1~n的数组, 结点个数为N个 */
  int i;
  for (i = N/2; i >= 1;  i--) {
    if (i*2 <= N && A[i*2] < A[i]) return 0;
    if (i*2+1 <= N && A[i*2+1] < A[i]) return 0;
  }
  return 1;
}

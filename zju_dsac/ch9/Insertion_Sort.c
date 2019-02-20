/* Copyright [2019] <mituh> */
/* Insertion_Sort.c */
/* 简单的交换排序 */


void Insertion_Sort(ElementType A[], int N) {
  int P, i;
  ElementType Tmp;

  for (P = 1; P < N; P++) {
    Tmp = A[P];   /* 摸下一张牌 */
    for (i = P; i > 0 && A[i-1] > Tmp; i--) {
      A[i] = A[i-1];   /* 移出空位 */
    }
    A[i] = Tmp;     /* 新牌落位 */
  }
}

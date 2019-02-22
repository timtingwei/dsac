/* Copyright [2019] <mituh> */
/* Shell_Sort.c */
/* 原始增量序列的希尔排序 */

/* 间隔的插入排序 */

void Shell_Sort(ElementType A[], int N) {
  int i, P, D;
  ElementType Tmp;

  for (D = N/2; D > 0; D /= 2) {   /* 原始希尔递增序列 */
    for (P = D; P < N; P++) {      /* 插入排序 */
      Tmp = A[P];
      for (i = P; i >= D && Tmp < A[i-D]; i -= D) {
        A[i] = A[i-D];
      }
      A[i] = Tmp;
    }
  }
}

// Update

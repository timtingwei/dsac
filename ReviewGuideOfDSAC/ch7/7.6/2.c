/* Copyright [2019] <mituh> */
/* 7.6/2.c */
/* 数组前m个元素递增, 后n个元素递增, 使数组有序 */

/* 归并思想 */
/* T(n) = O(n+m), S(n) = O(n+m) */
ElementType *B = (ElementType*)malloc(sizeof(ElementType)*(n+m+1));
void merge(ElementType A[], int m, int n) {
  int i, j, k;
  for (i = 1; i <= m+n; i++) {
    B[i] = A[i];   /* 将A中元素复制到B */
  }
  for (i = 1, j = m+1, k = 1; i <= m && j <= m+n; k++) {
    A[k] = (B[i] <= B[j]) ? B[i++] : B[j++];   /* 较小者填入数组 */
  }
  while (i <= m) A[k++] = B[i++];     /* 处理剩下的前半段 */
  while (j <= m+n) A[k++] = B[j++];   /* 处理剩下的后半段 */
}

/* 插入的版本 */
/* T(n) = O(mn), S(n) = O(1) */
void Insert_Sort(ElementType A[], int m, int n) {
  int i, j;
  for (i = m+1; i <= m+n; i++) {        /* 依次将A[m+1...m+n]插入到有序表中 */
    A[0] = A[i];                        /* 复制哨兵 */
    for (j = i-1; A[j] > A[0]; j--) {   /* 从后往前插入 */
      A[j+1] = A[j];                    /* 元素后移 */
    }
    A[j+1] = A[0];                      /* 插入 */
  }
}

/* Copyright [2019] <mituh> */
/* 7.6/3.c */
/* 计数排序 */


void Count_Sort(ElementType A[], int N) {
  /* B是临时数组 */
  ElementType *B = (ElementType*)malloc(sizeof(Element)*N);
  int i, j, cnt;
  for (i = 0; i < N; i++) {
    cnt = 0;
    for (j = 0; j < N; j++) {
      if (A[j].key < A[i].key) cnt++;
    }
    B[cnt].key = A[i].key;
  }
  for (i = 0; i < N; i++) {
    A[i].key = B[i].key;    /* 将排序完的元素赋值到A */
  }
}

/* 比较次数为N^2 */
/*
  计数排序和简单选择排序的比较:
  简单选择排序比计数排序好。简单选择排序的比较次数是n(n-1)/2, 计数排序为n^2。
  且计数排序需要额外的空间, 
 */


/* 两个记录之间只进行一次比较 */
void Count_Sort(ElementType A[], int N) {
  ElementType *B = (ElementType*)malloc(sizeof(Element)*N);
  for (i = 0; i < N; i++) {
    A[i].count = 0;
  }
  for (i = 0; i < N; i++) {
    for (j = i+1; j < N; j++) {
      if (A[i].key < A[j].key) {
        A[j].count++;
      } else {
        A[i].count++;
      }
    }
  }
  for (i = 0; i < N; i++) {
    B[A[i].count].key = A[i].key;
  }
  for (i = 0; i < N; i++) {
    A[i].key = B[i].key;
  }
}

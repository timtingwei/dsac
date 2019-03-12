/* Copyright [2019] <mituh> */
/* 7.3/3.c */
/* 每个元素都不相同的整型数组, 把奇数放到偶数之前 */

/* 利用快排划分后交换的思想, 一个指针找最前面的偶数, 一个指针找最后面的奇数, 交换位置
 */

void move(int A[], int N) {
  int i, j;
  i = 0; j = N-1;
  while (i < j) {
    while (i < j && A[i] % 2 == 1) i++;
    while (i < j && A[j] % 2 == 0) j--;
    if (i < j) {
      Swap(&A[i], &A[j]);
    }
    i++; j--;
  }
}

/* Copyright [2019] <mituh> */
/* 7.3/5.c */
/* 在数组L[1...n]中找第k小的元素 */

/* T(n) = O(n)?? */
/* 利用快速排序的划分思想, 每次划分后的privot位置是确定的最终位置,
   m是privot的下标, 若m = k, privot就是要找元素;
   若m < k, 在划分后的右半边继续递归找; 若 m > k, 在左半边找
 */
#include <stdio.h>
int Find_Kth(int A[], int low, int high, int k) {
  int privot, temp_low, temp_high;
  temp_low = low; temp_high = high;
  privot = A[low];
  while (low < high) {
    while (low < high && A[high] >= privot) high--;
    A[low] = A[high];
    while (low < high && A[low] <= privot) low++;
    A[high] = A[low];
  }
  A[low] = privot;
  if (low == k) {
    return A[low];
  } else if (low < k) {   /* 在右边区间寻找! */
    return Find_Kth(A, low+1, temp_high, k);
  } else {
    return Find_Kth(A, temp_low, low-1, k);
  }
}


int main() {
  /* int A[] = {-1, 1, 2, 3, 4, 5, 6}; */
  int A[] = {-1, 9, 2, 4, 8, 7, 0};
  int N, rst;
  N = 6;
  rst = Find_Kth(A, 1, N, 3);
  printf("rst = %d\n", rst);
  return 0;
}

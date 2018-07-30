// copyright [2018] <mituh>
// bubble_sort - 气泡排序

#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a; *a = *b; *b = t;
}

void bubble_sort(int* a, int n) {
  // 将a中整数序列重新排列成自小至大的整数序列
  for (int i = n-1, SORT = 1; i >= 1 && SORT; i--) {
    // 只遍历到1为止, 01已经顺序
    SORT = 0;
    for (int j = 0; j < i; j++) {
      if (a[j] > a[j+1]) {swap(&a[j], &a[j+1]); SORT = 1;}
    }
  }
}  // bubble_sort

// 平均时间复杂度 O(n^2)
// 最坏时间复杂度 O(n^2)

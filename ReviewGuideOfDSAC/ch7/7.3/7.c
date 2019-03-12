/* Copyright [2019] <mituh> */
/* 7.c */
/* 荷兰国旗问题 */

/* T = O(n)*/
/* i, j, k三指针, 红的放在最前面用i标记, 蓝的放在最后用k记录, j是工作指针 */
#include <stdio.h>
typedef enum {RED, WHITE, BLUE} color;   /* enum枚举数组 */

void Swap(color *a, color *b) {
  color temp;
  temp = *a; *a = *b; *b = temp;
}

void Flag_Arrange(color A[], int N) {
  int i, j, k;
  i = 0; j = 0; k = N-1;
  while (j <= k) {
    switch (A[j]) {
      case RED: Swap(&A[i], &A[j]); i++; j++; break;
      case WHITE: j++; break;
      case BLUE: Swap(&A[j], &A[k]); k--; break;
    }
  }
}

/* test case */
int main() {
  color cls[] = {RED, BLUE, WHITE, RED, RED, BLUE, BLUE, WHITE};
  int i, N;
  N = 8;
  Flag_Arrange(cls, N);
  for (i = 0; i < N; i++) {
    switch (cls[i]) {
      case RED: printf("RED "); break;
      case WHITE: printf("WHITE "); break;
      case BLUE: printf("BLUE "); break;
    }
  }
  printf("\n");
  return 0;
}

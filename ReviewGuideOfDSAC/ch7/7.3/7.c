/* Copyright [2019] <mituh> */
/* 7.c */
/* 荷兰国旗问题 */

/* T = O(n)*/
/* i, j, k三指针, 红的放在最前面用i标记, 蓝的放在最后用k记录, j是工作指针 */
#include <stdio.h>
typedef enum {RED, WHITE, BLUE} color;   /* enum枚举数组 */

int main() {
  color r;
  r = RED;
  printf("RED = %d, r = %d\n", RED, r);
  return 0;
}

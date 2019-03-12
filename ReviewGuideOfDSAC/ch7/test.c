/* Copyright [2019] <mituh> */
/* test.c */
/* 生成随机数 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main() {
  int a;
  srand((unsigned)time(NULL));
  a = rand()%100+20;
  printf("a = %d\n", a);
  return 0;
}

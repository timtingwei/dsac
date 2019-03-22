/* Copyright [2019] <mituh> */
/* 4.3/test.c */
/* 测试c中的引用用法, 对一般变量的引用, 和对指针变量的引用 */
#include <stdio.h>
/* 对一般变量的引用测试, c没有引用符号 */
/* void test(int &a) { */
/*
void test(int a) {
  printf("%d\n", a);
  a = 5;
  printf("%d\n", a);
}

int main() {
  int a;
  a = 4;
  test(a);
  printf("%d\n", a);
  return 0;
}
*/


/* 对指针变量的引用测试 */
/*
void test(int *a, int *b) {
  a = b;
  printf("*a = %d\n", *a);
}
*/

int main() {
  int *a;
  int *b;
  /* *a = 3; *b = 5; */
  /* test(a, b); */
  /* printf("in main, *a = %d\n", *a); */
  return 0;
}

// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update

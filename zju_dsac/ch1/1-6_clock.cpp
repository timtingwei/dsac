// Copyright [2018] <mituh>
// 1-6_clock.cpp
// 实现一个测试时间的模版
#include <cstdio>
#include <ctime>

clock_t start, stop;
double duration;

int main() {
  printf("%d\n", CLOCKS_PER_SEC);    // 1000000

  /* 不在测试范围内的写在之前 */
  start = clock();
  function();
  stop = clock();
  duration = ((double)(stop-start)) / CLOCK_PER_SEC;

  /* 测试范围之外的代码 写在之后*/

  return 0;
}


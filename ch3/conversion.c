// copyright [2018] <mituh>
// 数制转换, conversion
// a / b, a % b; 求余结果入栈, 先进后出原则, 先别计算的在最后被打印输出
#include <stdio.h>
#include "SqStack.c"

void conversion() {
  int a; SqStack S;
  InitStack(&S);                    // 创造空栈
  scanf("%d", &a);
  if (!a) { printf("0"); return; }  // 处理输入为0的边界情况
  while (a) {
    Push(&S, a % 8);                // 八进制转换
    a /= 8;
  }
  while (!StackEmpty(S)) {
    SElemType e;
    Pop(&S, &e);
    printf("%d", e);
  }
  printf("\n");
}

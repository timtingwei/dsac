// Copyright[2018] <mituh>
// ex3-1-3.cpp
// 判定栈操作序列是否为合法序列
#include <stdio.h>
#include <stdlib.h>
/*
bool isValid(char* seq, int n) {
  int i, s;
  s = 0;
  for (i = 0; i < n; i++) {
    if (seq[i] == 'I') {
      s++;
    } else if (seq[i] == 'O') {
      if (s > 0) s--;
      else  return false;
    }
  }
  if (s) return false;
  else  return true;
}
*/


int Judge(char A[]) {
  // 判定栈操作序列是否为合法序列, A为字符数组
  // 合法返回1, 不合法返回0
  int i = 0;      // 工作指针
  int s = 0;      // 概念上栈内元素个数
  while (A[i] != '\0') {           // 未到字符数组尾部
    switch (A[i]) {
      case 'I': s++; break;
      case 'O':
        if (s > 0) {
          s--;
        } else {
          printf("序列不合法\n");
          exit(0);
        }
    }  // switch
    i++;
  }
  if (s == 0) {
    printf("序列合法\n");
    return 1;
  } else {
    printf("序列不合法\n");
    return 0;
  }
}

/*
// 测试
int main() {
  char ch1[] = "IIOOIO", ch2[] = "IIOOII";
  Judge(ch1);
  Judge(ch2);
}
*/


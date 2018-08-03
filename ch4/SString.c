// copyright [2018] <mituh>
// SString.c

#include <stdlib.h>
#include <stdio.h>


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;      // Status是函数返回的值
// typedef int QElemType;   // 链队列储存的元素类型

// = = = = = ADT SString 的表示与实现  = = = = =



int Index(String S, String T, int pos) {
  // T为非空串. 若主串S中第pos个字符之后存在与T相等的子串
  int m, n, i; String sub;
  m = StringLength(S), n = StringLenth(T); i = pos;
  if (pos > 0) {
    while (i <= m-n+1) {
      SubString(sub, S, i, m);     // 在S中找长度为m的子串
      if (StrCompare(S, sub) != 0) {
        i++;
      } else { return i;}
    }  // while
  }  // if
  return 0;                          // 不存在子串T, 返回0
}  // Index


int main() {
  
  return 0;
}

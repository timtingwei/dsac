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

// - - - - - 串的定义顺序存储表示 - - - - -
#define MAXSTRLEN 255       // 用户可以在255以内定义最大串长
typedef unsigned char SString[MAXSTRLEN];     // 字符数组

// 生成一个值等于ch的串T
Status StrAssign(SString *T, char ch) {
  // T = (char*) malloc (sizeof(char) * MAXSTRLEN);
  // if (!T) exit(OVERFLOW);
  (*T)[0] = 1; (*T)[1] = ch;
  return OK;
}

// 用T返回由S1, S2连接而成的新串, 若未截断, 返回TRUE, 否则返回FALSE
Status Concat(SString *T, SString S1, SString S2) {
  int uncut; int i;                      // 截断标记, 循环计数
  if (S1[0] + S2[0] <= MAXSTRLEN) {      // 未截断
    (*T)[0] = S1[0] + S2[0];
    for (i = 1; i <= S1[0]; i++) { (*T)[i] = S1[i];}
    for (i = 1; i <= S2[0]; i++) { (*T)[i+S1[0]] = S2[i];}
    uncut = TRUE;
  } else if (S1[0] < MAXSTRLEN) {        // S2被截断
    (*T)[0] = MAXSTRLEN;
    for (i = 1; i <= S1[0]; i++) { (*T)[i] = S1[i];}
    for (i = 1; i <= MAXSTRLEN - S1[0]; i++) { (*T)[i+S1[0]] = S2[i]; }
    uncut = FALSE;
  } else {                               // 截断(仅取S1)
    (*T)[0] = S1[0];
    for (i = 1; i <= S1[0]; i++) { (*T)[i] = S1[i];}
    uncut = FALSE;
  }
  return uncut;
}  // Concat

// 用Sub返回串S的第pos个字符起长度为len的子串
Status SubString(SString *Sub, SString S, int pos, int len) {
  // if (pos+len-1 > S[0]) return ERROR;      // 输入长度和位置不合法
  if (pos < 1 || pos > S[0] || len < 0 || len > S[0] - pos + 1)
    return ERROR;                             // 输入长度和位置不合法
  int i;
  for (i = 1; i <= len; i++) {
    (*Sub)[i] = S[i+pos-1];
  }
  (*Sub)[0] = len; return OK;
}  // SubString

/*
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
*/

void PrintString(SString S) {
  for (int i = 1; i <= S[0]; i++) {
    printf("%d ", S[i]);
  }
  printf("\n");
}

int main() {
  // SString str = "dsds";
  SString str, T;
  StrAssign(&str, 'a');
  Concat(&T, str, str);
  PrintString(T);
  StrAssign(&str, 'c');
  Concat(&T, T, str);
  Concat(&T, T, str);
  Concat(&T, T, str);
  PrintString(T);
  return 0;
}

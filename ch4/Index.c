// Copyright [2018] <mituh>
// Index.c
// 朴素的模式匹配算法

#include <stdlib.h>
#include <stdio.h>


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;      // Status是函数返回的值


#define MAXSTRLEN 100
typedef unsigned char SString[MAXSTRLEN];

Status StrAssign(SString *S, char *chars) {
  int i; char* c;
  for (i = 0, c = chars; *c; i++, c++) {
    (*S)[i+1] = *c;
  }   // 用i返回chars长度
  (*S)[0] = i;
  return OK;
}

/*
// 返回子串T在主串S中第pos个字符之后的位置, 若不存在, 函数值为0
// 我的版本
int Index(SString S, SString T, int pos) {
  // 1<=pos<=S.length-T.length+1
  if (pos < 1 || pos > S[0]-T[0]+1) return ERROR;
  int i, j;
  for (i = pos; i <= S[0] - T[0]+1; i++) {
    int ok = 1;
    for (j = 0; j <= T[0]-1; j++) {
      if (S[i+j] != T[j+1]) { ok = 0; break; }
    }
    if (ok) return i;
  }
  return 0;
}
*/

// 返回子串T在主串S中第pos个字符之后的位置, 若不存在, 函数值为0
// 标准的朴素匹配 O(n) = (n-m+1)*m;
int Index(SString S, SString T, int pos) {
  // 1<=pos<=S.length-T.length+1
  // T非空, 1 <= pos <= StrLength(S)
  int i, j;
  i = pos, j = 1;
  while (i <= S[0] && j <= T[0]) {
    if (S[i] == T[j]) {
      i++; j++;
    } else {
      i = i-j+2; j = 1;          // i退回到下一位, j退回到首位
    }
  }
  if (j > T[0]) {                // T被匹配完全才退出的循环
    return i-T[0];               // why? 完全匹配后, i = ans+Strlen(T);
  }
  return 0;
}


int main() {
  SString S;
  StrAssign(&S, "mituhit");
  SString T; StrAssign(&T, "it");
  int ans_i = Index(S, T, 3);
  printf("Index(mituh, it) = %d\n", ans_i);
  return 0;
}


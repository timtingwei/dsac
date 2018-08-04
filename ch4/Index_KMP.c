// // Copyright [2018] <mituh>
// Index.c
// 朴素的模式匹配算法

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


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

// 通过计算返回子串T的next数组
void get_next(SString T, int *next) {
  int i, j;
  i = 1; j = 0;
  next[1] = 0;
  while (i < T[0]) {
    if (j == 0 || T[i] == T[j]) {   // T[i]表示后缀的单个字符
      ++i;                          // T[j]表示前缀单个字符
      ++j;
      next[i] = j;
    } else {
      j = next[j];       // 若字符不相同, 则j值回溯
    }
  }
}

// 改良get_next
void get_nextval(SString T, int *nextval) {
  int i, j;
  i = 1; j = 0;
  nextval[1] = 0;
  while (i < T[0]) {
    if (j == 0 || T[i] == T[j]) {   // T[i]表示后缀的单个字符
      ++i;                          // T[j]表示前缀单个字符
      ++j;
      if (T[i] != T[j])
        nextval[i] = j;
      if (T[i] == T[j])
        nextval[i] = nextval[j];   // 如果与前缀相同, 将前缀的nextval赋值给他
    } else {
      j = nextval[j];       // 若字符不相同, 则j值回溯
    }
  }
}

// 返回子串T在主串S中第pos个字符之后的位置, 若不存在, 函数值为0
// KMP匹配
int Index_KMP(SString S, SString T, int pos) {
  // 1<=pos<=S.length-T.length+1
  // T非空, 1 <= pos <= StrLength(S)
  int i, j;
  i = pos, j = 1;
  int next[255];        // 定义一组next数组
  get_nextval(T, next);    // 对串T进行分析, 得到next数组
  while (i <= S[0] && j <= T[0]) {
    if (j == 0 || S[i] == T[j]) {
      i++; j++;
    } else {
      j = next[j];      // 去掉了i的回溯部分
    }
  }
  if (j > T[0]) {                // T被匹配完全才退出的循环
    return i-T[0];               // why? 完全匹配后, i = ans+Strlen(T);
  }
  return 0;
}

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


int foo1() {
  SString S;
  StrAssign(&S, "0000000000001");
  SString T; StrAssign(&T, "000001");
  int ans_i = Index_KMP(S, T, 3);
  printf("Index_KMP() = %d\n", ans_i);
  return 0;
}

int foo2() {
  SString S;
  StrAssign(&S, "0000000000001");
  SString T; StrAssign(&T, "000001");
  int ans_i = Index(S, T, 3);
  printf("Index() = %d\n", ans_i);
  return 0;
}

int main() {
  foo1();
  foo2();

  return 0;
}

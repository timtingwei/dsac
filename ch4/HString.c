// copyright [2018] <mituh>
// HString.c

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

// - - - - - 堆分配的存储表示 - - - - -
typedef struct {
  char * ch;       // 若是非空串, 则按串长分配存储区, 否则为NULL
  int    length;   // 串长度
}HString;

// - - - - - 基本操作的函数原型说明 - - - - -
Status StrAssign(HString *T, char * chars);
  // 生成一个其值等于串常量char的串T
int StrLength(HString S);
  // 返回S的元素个数, 串长
int StrCompare(HString S, HString T);
  // 若S>T, 则返回值>0; S=T, 返回值=0; S<T, 返回值<0
Status ClearString(HString *S);
  // 将s清为空串, 并释放S的空间
Status Concat(HString *S, HString *T);
  // 用T返回由S1和S2联接而成的新串
HString SubString(HString S, int pos, int len);
  // 返回串S从第pos个字符起长度为len的子串

// 生成一个其值等于串常量char的串T(别忘记为T的存储区分配空间, 判断常量串?为空串)
Status StrAssign(HString *T, char * chars) {
  int i; char *c;
  for (i = 0, c = chars; *c; i++, c++) {}               // 求串chars的长度
  if (!i) {
    (*T).ch = NULL; (*T).length = 0;                    // 常量串是空串
  } else {
    int j;
    // 千万记得为T.ch分配存储空间
    if (!((*T).ch = (char*) malloc (i * sizeof(char))))
      return exit(OVERFLOW);
    for (j = 0; j <= i-1; j++) (*T).ch[j] = chars[j];   // 将常量串赋值给T
    (*T).length = i;                                    // 别忘了T的长度
  }
  return OK;
}

// 在串S的pos个字符之前插入T
Status StrInsert(HString* S, int pos, HString T) {
  // 1<=pos<=S.length+1, 插入位置合理
  if (pos < 1 || pos > (*S).length + 1) return ERROR;
  if (T.length) {                             // T不是空串
    if (!((*S).ch = (char*) realloc (((*)S.length + T.length) * sizeof(ch))))
      exit(OVERFLOW);                         // 存储空间分配失败
    int i;
    for (i = (*S).length-1; i >= pos-1; i--) {
      (*S).ch[i+T.length] = (*S).ch[i];       // 为T插入腾出位置
    }
    for (i = 0; i <= T.length-1; i++) {
      (*S).ch[i+pos-1] = T.ch[i];             // 插入T
    }
    (*S).length += T.length;                  // 改变S的长度
  }
  return OK;
}  // StrInsert 未测试

int main() {

  return 0;
}

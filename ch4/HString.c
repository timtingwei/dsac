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

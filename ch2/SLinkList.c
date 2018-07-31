// copyright [2018] <mituh>
// SLinkList.c

#include <stdlib.h>
#include <stdio.h>
#include <time.h>        // 用于生成随机数


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;      // Status是函数返回的值
typedef int ElemType;    // 线性表储存的元素类型

// - - - - - - 线性静态链表存储结构 - - - - -
#define MAXSIZE 1000
typedef struct {
  ElemType data;
  int      cur;
} component, SLinkList[MAXSIZE];


// 将一维数组space中各个分量链成一个备用链表, space[0].cur为指针
Status InitSpace_SL(SLinkList *space) {
  int i;
  for (i = 0; i < MAXSIZE - 1; ++i) space[i].cur = i + 1;
  space[MAXSIZE-1].cur = 0;       // 最后放第一个有数据结点的指针, 目前0, 链表空
  return OK;
}

// 在静态单链线性表S中查找第一个值为e的元素
int LocateElem_SL(SLinkList S, ElemType e) {
  int i = S[0].cur;              // 表中第一个结点, S[0]是头结点
  while (i && S[i].data != e) i = S[i].cur;  // 移动游标
  return i;    // i=0, return 0; i存在, 返回此时i
  // return i;
}

int main() {
  SLinkList S;
  LocateElem_SL(S, 5);
  return 0;
}

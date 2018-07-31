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

// 首个元素cur=第一个空闲位置的下标
// 最后一个元素cur=第一个有数据位置的下标

// 将一维数组space中各个分量链成一个备用链表, space[0].cur为指针
Status InitSpace_SL(SLinkList space) {
  int i;
  for (i = 0; i < MAXSIZE - 1; ++i) space[i].cur = i + 1;
  space[MAXSIZE-1].cur = 0;       // 放第一个有数据结点的位置, 目前0, 代表链表空
  return OK;
}  // InitSpace_SL

// 若备用空间链表非空, 则返回分配的结点下标, 否在返回0
int Malloc_SLL(SLinkList space) {
  int i;
  i = space[0].cur;         // 当前数组第一个元素的cur存的值, 就是空闲元素下标
  if (space[0].cur) {
    space[0].cur = space[i].cur;    // 更新首个元素的cur值, 首个空闲元素下标改变
  }
  return i;
}  // Malloc_SLL

// 静态链表L的长度(自己写, 参考大话数据结构)
int ListLength(SLinkList L) {
  int i, l;
  i = L[MAXSIZE-1].cur;
  if (!i) return i;         // 首个有数据的元素下标位0, 长度为0
  l = 1;
  while (L[i].cur) {
    i = L[i].cur;
    l++;
  }
  return l;
}

// 在静态链表L的第i个元素之前插入新的数据元素e
Status InsertList_SL(SLinkList L, int i, ElemType e) {
  // 首个元素cur改变成第一个空闲位置下标
  // 最后一个元素cur改成第一个有数据位置的下标
  // 需要手动模拟动态链表结构的储存空间和分配
  int j, k, l;   // 是新插入的元素下标, k用于找到i之前元素的下标, l用于移动计数
  k = MAXSIZE - 1;                 // k首先是最后一个元素的下标
  if (i < 1 || i > ListLength(L) + 1) return ERROR;
  j = Malloc_SLL(L);               // j作为新分配空间的下标
  if (!j) return OVERFLOW;         // 空间已经满了, Malloc_SLL才会返回0
  L[j].data = e;                   // 给新分配的空间注入元素
  for (l = 1; l <= i - 1; l++) {   // k去找到i之前元素的位置
    k = L[k].cur;
  }
  L[j].cur = L[k].cur;             // 新元素的下一位置, 是i之前元素的下一位置
  L[k].cur = j;                    // 把新元素的下标作为i之前元素的cur
  return OK;
}  // InsertList_SL


// 在静态单链线性表S中查找第一个值为e的元素
int LocateElem_SL(SLinkList S, ElemType e) {
  int i = S[0].cur;              // 表中第一个结点, S[0]是头结点
  while (i && S[i].data != e) i = S[i].cur;  // 移动游标
  return i;    // i=0, return 0; i存在, 返回此时i
  // return i;
}  // LocateElem_SL

int main() {
  SLinkList S;
  InitSpace_SL(S);
  printf("length=%d\n", ListLength(S));
  InsertList_SL(S, 1, 5);
  
  InsertList_SL(S, 1, 2);
  InsertList_SL(S, 2, 5);
  printf("length=%d\n", ListLength(S));
  return 0;
}

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

/*
// 静态链表L的长度(自己写)
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
*/

// /*
// 静态链表L的长度(参考大话数据结构中的实现版本)
int ListLength(SLinkList L) {
  int i, l;
  l = 0;
  i = L[MAXSIZE-1].cur;
  while (i) {             // 首个有数据的元素下标位0, 长度为0
    i = L[i].cur;
    l++;
  }
  return l;
}
// */

// 在静态链表L的第i个元素之前插入新的数据元素e
Status ListInsert_SL(SLinkList L, int i, ElemType e) {
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
}  // ListInsert_SL

// 将下标为k的空闲结点回收到备用链表
void Free_SSL(SLinkList space, int k) {
  space[k].cur = space[0].cur;     // 空闲位置换做k来指向, 作为第二空闲位置
  space[0].cur = k;                // 目前首个空闲位置下标为k
  // why? 不对数据清零?
}

// 删除在静态链表L中的第i个数据元素e
Status ListDelete_SL(SLinkList L, int i) {
  int k, j;  // k指向删除元素的前一个元素, j用来计数, 也作用删除元素下标
  k = MAXSIZE - 1;                 // k是头结点
  for (j = 1; j <= i-1; j++) {
    k = L[k].cur;                  // 将k移动到第i元素的前一个元素
  }
  j = L[k].cur;                    // j指向被删除的元素
  L[k].cur = L[j].cur;
  Free_SSL(L, j);
  return OK;
}


// 在静态单链线性表S中查找第一个值为e的元素(参考数据结构, S[0]是头结点)
int LocateElem_SLT(SLinkList S, ElemType e) {
  int i = S[0].cur;              // 表中第一个结点, S[0]是头结点
  while (i && S[i].data != e) i = S[i].cur;  // 移动游标
  return i;    // i=0, return 0; i存在, 返回此时i
  // return i;
}  // LocateElem_SL

/*
// 静态链表的查找
// 在静态链表S中查重第一个值为e的元素, 返回在链表中第几个元素
int LocateElem_SL(SLinkList S, ElemType e) {
  int k, j;
  k = S[MAXSIZE - 1].cur;           // 头结点指向的索引
  j = 1;
  while (k && S[k].data != e) { k = S[k].cur; j++;}
  return j;
}
*/

// 在静态链表S中查重第一个值为e的元素, 返回在链表中索引
int LocateElem_SL(SLinkList S, ElemType e) {
  int k;
  k = S[MAXSIZE - 1].cur;           // 头结点指向的索引
  while (k && S[k].data != e) { k = S[k].cur;}
  return k;
}

// 静态链表的整表添加
void CreateListTail_SL(SLinkList S, int n) {
  // 随机产生n个元素的值, 建立带头结点的静态链表
  // SLinkList L;
  int i, r, k;
  srand(time(0));
  InitSpace_SL(S);
  S[MAXSIZE-1].cur = 1;
  r = S[0].cur;     // r指向首个空闲位置
  for (i = 0; i < n; i++) {
    k = Malloc_SLL(S);
    S[k].data = rand()%100 + 1;    // 随机生成100以内的数字
    S[r].cur = k;
    r = k;
  }
  S[r].cur = 0;
}

// 静态链表的整表删除
Status ClearList_SL(SLinkList S) {
  int k, j;
  k = S[MAXSIZE - 1].cur;
  while (k) {
    j = S[k].cur;
    Free_SSL(S, k);
    k = j;
  }
  S[MAXSIZE - 1].cur = 0;     // 头结点的指针域为0
  return OK;
}

// 两个有序静态链表的归并(仍旧存在点问题, 《数据结构》p33问题来解决)
Status MergeList_SL(SLinkList S1, SLinkList S2, SLinkList S3) {
  // 两个指针都指向首个元素结点
  int p, q, k;
  p = S1[MAXSIZE - 1].cur;
  q = S2[MAXSIZE - 1].cur;
  // 初始化S3
  InitSpace_SL(S3);
  S3[MAXSIZE-1].cur = 0;         // 头结点指针域为0
  k = S3[MAXSIZE-1].cur;         // k是s3首个元素的下标
  printf("p=%d, q=%d\n", p, q);
  while (p && q) {
    if (S1[p].data <= S2[q].data) {
      S3[k].data = S1[p].data; k = S3[k].cur; p = S1[p].cur;
    } else {
      S3[k].data = S2[q].data; k = S3[k].cur; q = S2[q].cur;
    }
  }
  if (p) S3[k].cur = p;
  if (q) S3[k].cur = q;
  // 但这里存在一个问题, s1,s2, s3各自的空间独立, 貌似无法简单这样的链接
  return OK;
}

void ListPrint_SL(SLinkList S) {
  int k, i;
  k = MAXSIZE - 1;
  for (i = 0; i < ListLength(S); i++) {
    k = S[k].cur;
    printf("%d ", S[k].data);
  }
  printf("\n");
}

int main() {
  SLinkList S;
  InitSpace_SL(S);
  ListInsert_SL(S, 1, 7);
  ListInsert_SL(S, 1, 2);
  ListInsert_SL(S, 2, 3);
  printf("locate(3)=%d\n", LocateElem_SL(S, 3));
  printf("S[3]=%d\n", S[3].data);
  ListPrint_SL(S);
  printf("length=%d\n", ListLength(S));
  ListDelete_SL(S, 1);
  printf("length=%d\n", ListLength(S));
  ListPrint_SL(S);

  SLinkList S2;
  CreateListTail_SL(S2, 5);
  ListPrint_SL(S2);

  // ClearList_SL(S2);
  // ListPrint_SL(S2);

  SLinkList S3;
  MergeList_SL(S, S2, S3);
  ListPrint_SL(S3);
  return 0;
}

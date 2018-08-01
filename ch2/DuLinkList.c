// copyright [2018] <mituh>
// DuLinkList.c

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

// ------ 线性表的单链表存储结构 ---------
typedef struct LNode {
  ElemType         data;
  struct LNode     * next;
}LNode, * LinkList;   // why?  int a[] ==> int* a, LinkList储存LNode结点


// - - - - - - 线性静态链表存储结构 - - - - -
#define MAXSIZE 1000
typedef struct {
  ElemType data;
  int      cur;
} component, SLinkList[MAXSIZE];


// - - - - - - 双向链表存储结构 - - - - -
typedef struct DuLNode {
  ElemType         data;
  struct DuLNode   *prior;
  struct DuLNode   *next;
} DuLNode, * DuLinkList;

// 初始化成空的双向循环链表
Status ListInit_DuL(DuLinkList *L) {
  // DuLinkList s;
  if (!((*L) = (DuLinkList)malloc(sizeof(DuLNode)))) return ERROR;  // 空间不足
  (*L)->next = (*L)->prior = (*L);
  return OK;
}  // ListInit_DuL

// 返回双向循环链表的长度（bug, 解决）
int ListLength_DuL(DuLinkList L) {
  DuLinkList p; int j;
  p = L->next;
  if (p == L) return 0;    // L的结点的下一个结点是他自身
  j = 0;                   // 将j=1, 改为j=0, 问题解决
  while (p != L) {p = p->next; j++;}
  return j;
}  // ListLength_DuL

// 返回第i个位置结点, 若第i位置不存在元素, 返回NULL(bug, 凭空可能多出一位, 解决)
DuLinkList GetElemP_DuL(DuLinkList L, int i) {
  DuLinkList p; int j;
  p = L->next; j = 1;
  if (p == L && i == 1) return L->next;     // 空表时, i=1, 返回头结点
  while ((p != L) && j < i) {
    p = p->next; j++;
  }
  if ((p == L) || j > i) return NULL;       // 不存在第i位置的元素
  return p;
}  // GetElemP_DuL


// 双向链表中i位置插入一个结点, 数据为e
Status ListInsert_DuL(DuLinkList *L, int i, ElemType e) {
  // 在带头结点的双链循环线性表L中第i个位置之前插入元素e
  // i的合法值是1<=i<=length+1
  DuLinkList p = *L, s;              // p为插入位置结点, s是要插入的结点
  if (!(p = GetElemP_DuL(*L, i)))    // 在L中确定插入位置
    return ERROR;                    // p=NULL, 插入位置不合法
  if (!(s = (DuLinkList)malloc(sizeof(DuLNode)))) return ERROR;
  s->data = e;                       // 插入结点数值域赋值为e
  s->prior = p->prior; s->next = p;  // 插入结点的前后指针指向
  p->prior = s; s->prior->next = s;  // 被插入结点的prior, 插入前结点next
  return OK;
}  // ListInsert_DuL

// 双向链表中删除i位置的结点
Status ListDelete_DuL(DuLinkList *L, int i, ElemType *e) {
  // 带头结点的双链循环表L中删除第i个位置
  // i的合法值是1<=i<=length
  DuLinkList p, q;
  if (!(p = GetElemP_DuL(*L, i)))
    return ERROR;                 // p=NULL, 删除不合法
  // q = p;                       // 双向链表删除一个结点不需要再用p保存
  // p->next->prior = p->prior;
  // p->prior->next = q->next;
  *e = p->data;
  p->prior->next = p->next;
  p->next->prior = p->prior;      // 注意每次断开的是哪条链
  free(p); return OK;
}  // ListDelete_DuL

// 打印按链表顺序输出
void ListPrint_DuL(DuLinkList L) {
  DuLinkList p; int i;
  p = L;
  for (i = 0; i < ListLength_DuL(L); i++) {
    p = p->next;
    printf("%d ", p->data);
  }
  printf("\n");
}


int main() {
  DuLinkList L;
  ListInit_DuL(&L);
  printf("len=%d\n", ListLength_DuL(L));
  ListPrint_DuL(L);
  GetElemP_DuL(L, 1);
  ListInsert_DuL(&L, 1, 5);
  printf("len=%d\n", ListLength_DuL(L));
  ListPrint_DuL(L);
  ListInsert_DuL(&L, 1, 7);
  ListInsert_DuL(&L, 1, 8);
  ListInsert_DuL(&L, 1, 10);
  ListPrint_DuL(L);

  ElemType e;
  ListDelete_DuL(&L, 1, &e);
  ListPrint_DuL(L);
  return 0;
}

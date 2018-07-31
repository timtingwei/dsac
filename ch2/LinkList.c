// copyright [2018] <mituh>
// LinkList.c

#include <stdlib.h>
#include <stdio.h>


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

// 单链表的读取
Status GetElem_L(LinkList *L, int i, ElemType *e) {
  // 定义头指针从链表头部开始, j计数1
  int j;
  LinkList p;
  p = (*L)->next; j = 1;    // 结点p指向链表L的第一个结点
  while (p && j < i) {   // why? j与i的关系
    p = p->next; j++;    // 当j<i时, 遍历链表, 让p向后移动不断指向下一结点
  }
  if (!p || j > i) return ERROR;   // 第i个元素不存在
  *e = p -> data;
  return OK;
}   // GetElem_L  若1<=i<=n, 频度i-1; 否则频度n, Tn = O(n);

// 单链表插入
Status ListInsert_L(LinkList *L, int i, ElemType e) {
  int j;
  LinkList p, s;
  // p = L->next; j = 1;
  p = *L; j = 0;
  while (p && j < i-1) {
    p = p->next; ++j;
  }
  if (!p || j > i-1) return ERROR;          // i小于1或者大于表长+1
  s = (LinkList) malloc (sizeof(LNode));    // 给新结点分配空间
  s->data = e;
  s->next = p->next; p->next = s;      // 顺序不能反, 不能让p->next地址丢失
  return OK;
}  // ListInsert_L


// 单链表删除
Status ListDelete_L(LinkList *L, int i, ElemType *e) {
  int j;
  LinkList p, q;
  p = *L;         // p指向第一个结点
  j = 1;
  // while (p && j < i) {p = p->next; j++;}   // 这两种写法的区别
  // if (!p || j > i) return ERROR;           // 不存在第i个结点
  while (p->next && j < i) {p = p->next; j++;}
  if (!(p->next) || j > i) return ERROR;         // 不存在第i个结点
  q = p->next;                           // q指向要被删除的结点
  p->next = q->next;                     // p下一结点赋值为q的下一结点
  // p->next = p->next->next;
  *e = q->data;                          // 将e所指向的对象更新成被删除的数据
  free(q);                               // 让系统回收结点q, 释放释放
  return OK;
}

Status CreateList_L(LinkList *L) {
  // ..
  return OK;
}

void ListPrint_L(LinkList *L) {
  int j;
  LinkList p;
  p = *L; j = 0;
  while (p) {
    printf("%d ", p->data);
    p = p -> next; j++;
  }
  printf("\n");
}

int main() {
  int a, * b;
  LNode Ln;
  LinkList L;
  ElemType e;
  // Ln -> data; Ln -> next;   // Ln不是指针
  // L -> data = 5;
  // L -> next-> data = 2;
  // L -> next -> next -> data = -10;
  ListInsert_L(&L, 1, 8);
  ListInsert_L(&L, 1, 1);
  ListInsert_L(&L, 1, 9);
  ListPrint_L(&L);

  // GetElem_L(&L, 1, e);
  // printf("%d\n", e);
  return 0;
}

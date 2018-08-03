// copyright [2018] <mituh>
// LinkQueue.c

#include <stdlib.h>
#include <stdio.h>


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;      // Status是函数返回的值
typedef int QElemType;   // 链队列储存的元素类型

// = = = = = ADT Queue 的表示与实现  = = = = =

// - - - - - 单链队列-----队列的链式存储结构 - - - - -
typedef struct QNode {
  QElemType       data;
  struct QNode   * next;
} QNode, * QueuePtr;

typedef struct {
  QueuePtr front;    // 队头指针
  QueuePtr rear;     // 队尾指针
}LinkQueue;

// - - - - - 基本操作的函数原型说明 - - - - -
// 构造一个空队列
Status InitQueue(LinkQueue *Q) {
  (*Q).front = (*Q).rear = (QueuePtr) malloc (sizeof(QNode));
  if (!(*Q).front) exit(OVERFLOW);                         // 存储分配失败
  (*Q).front->next = NULL;
  return OK;
}

// 销毁队列Q
Status DestroyQueue(LinkQueue *Q) {
  while ((*Q).front) {
    (*Q).rear = (*Q).front->next;     // 尾指针指向头结点的下一个位置
    free((*Q).front);                 // 释放头指针
    (*Q).front = (*Q).rear;
  }
  return OK;
}

// 队列Q的队尾插入元素e(插入新元素需要分配空间)
Status EnQueue(LinkQueue *Q, QElemType e) {
  QueuePtr p = (QueuePtr) malloc (sizeof(QNode));
  if (!p) exit(OVERFLOW);             // 元素分配失败
  p->data = e; p->next = NULL;        // 先为新分配的元素构造
  (*Q).rear->next = p;                // 尾指针链接p
  (*Q).rear = p;                      // p成为新的尾指针
  return OK;
}

// 队列Q的队首删除元素e(考虑队列空的情况 和 删除最后一个结点的情况)
Status DeQueue(LinkQueue *Q, QElemType *e) {
  if ((*Q).front == (*Q).rear) return ERROR;
  QueuePtr p;                         // 用于保存删除结点
  p = (*Q).front->next;
  *e = p->data;                       // e返回被删除结点的元素值
  (*Q).front->next = p->next;         // 更新头指针的新的链接
  if ((*Q).rear == p) (*Q).rear = (*Q).front;    // rear,front机制本身和next分离
  free(p);
  return OK;
}


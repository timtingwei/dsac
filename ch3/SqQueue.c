// copyright [2018] <mituh>
// SqQueue.c

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

// - - - - - 循环队列---队列的顺序存储结构 - - - - -
#define MAXQSIZE 100     // 最大队列长度
typedef struct {
  QElemType * base;      // 初始化的动态分配存储空间
  int front;             // 头指针, 队列不空, 指向头元素
  int rear;              // 尾指针, 队列不空, 指向队列尾元素的下一位置
}SqQueue;


// - - - - - 循环队列基本操作的算法描述 - - - - -

// 构造一个空队列
Status InitQueue(SqQueue *Q) {
  (*Q).base = (QElemType *) malloc (sizeof(QElemType) * MAXQSIZE);  // 存放元素
  if (!(*Q).base) exit(OVERFLOW);    // 存储分配失败
  (*Q).front = (*Q).rear = 0;
  return OK;
}

// 返回Q的元素个数, 即队列的长度
int QueueLength(SqQueue Q) {
  return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

// 插入元素e作为Q的新队尾(注意队列满的情况)
Status EnQueue(SqQueue *Q, QElemType e) {
  if (((*Q).rear+1) % MAXQSIZE == (*Q).front) return ERROR;  // 队列满
  (*Q).base[(*Q).rear] = e;                // 在base中添加元素, 无需额外分配
  (*Q).rear = ((*Q).rear+1) % MAXQSIZE;    // 尾部指针+1, 计算在环中的索引
  return OK;
}

// 删除Q的队头元素(注意队列为空的情况)
Status DeQueue(SqQueue *Q, QElemType *e) {
  if ((*Q).front == (*Q).rear) return ERROR;    // 队列为空
  *e = (*Q).base[(*Q).front];
  (*Q).front = ((*Q).front + 1) % MAXQSIZE;
  return 0;
}



int main() {
  SqQueue Q; QElemType e;
  printf("aa\n");
  InitQueue(&Q);
  printf("len=%d\n", QueueLength(Q));
  EnQueue(&Q, 1);
  EnQueue(&Q, 2);
  EnQueue(&Q, 3);
  printf("len=%d\n", QueueLength(Q));
  DeQueue(&Q, &e);
  printf("len=%d\n", QueueLength(Q));
  printf("del:e=%d\n", e);
  return 0;
}


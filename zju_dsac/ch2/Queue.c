// Copyright [2018] <mituh>
// Queue.c
// 队列的构造

#include <stdio.h>
#include <stdlib.h>

Queue CreateQueue(int maxSize) {
  // 生成长度为maxSize的空队列
  return queue
}

int IsFullQ(Queue Q, int maxSize) {
  // 判断队列Q是否已经满
  return result
}

void AddQ(Queue PtrQ, ElementType item) {
  // 将数据元素item插入队列Q中
  // 循环队列不放满的情况
  if ((PtrQ->rear+1) % MAXSIZE == PtrQ->front) {
    printf("队列满");
    return ERROR;
  }
  PtrQ->rear = (PtrQ->rear+1) % MAXSIZE;
  PtrQ->Data[PtrQ->rear] = item
}

int IsEmpty(Queue Q) {
  // 判断队列是否为空
  return result
}

ElementType DeleteQ(Queue PtrQ) {
  // 将队头数据删除并返回
  // 非满循环队列的出队操作
  if (PtrQ->front == PtrQ->rear) {
    printf("队列空");
    return ERROR;
  }
  PtrQ->front = (PtrQ->front+1) % MAXSIZE;
  return PtrQ->Data[PtrQ->front]
}

// Copyright [2018] <mituh>
// LinkQueue.c
// 链式队列构造

typedef int ElementType

struct Node {
  ElementType Data;
  struct Node *Next;
};

struct QNode {   /* 链队结构 */
  struct Node *front;   /* 指向队头节点 */
  struct Node *rear;    /* 指向队尾部节点 */
};

typedef struct QNode *Queue;
Queue PtrQ;

int IsEmpty(Queue PtrQ) {
  /* 链式队列判空 */
  if (PtrQ->front == NULL) {
    return 1;  /* 队列空 */
  } else {
    return 0;  /* 队列非空 */
  }
}

ElementType DeleteQ(Queue PtrQ) {
  /* 不带头节点的链式队列的出队操作 */
  if (IsEmpty(PtrQ)) {
    printf("队列空");
    return ERROR;
  }
  QNode *FrontCell = PtrQ->front;
  if (PtrQ->front == PtrQ->rear)      /* 队列只有一个元素 */
    PtrQ->front = PtrQ->rear = NULL;  /* 删除后节点置为空 */
  else
    PtrQ->front = PtrQ->front->Next;
  ElementType FrontElem = FrontCell->Data;
  free(FrontCell);                   /* 释放被删除节点空间 */
  return FrontElem;
}

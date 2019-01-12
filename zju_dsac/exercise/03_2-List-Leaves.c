/* Copyright [2019] <mituh> */
/* 03_2-List-Leaves.c */
/* 训练建树和遍历的基本功 */

#include <stdlib.h>
#include <stdio.h>

#define MaxSize 20
#define Tree int
#define Null -1

struct TNode {
  int Left, Right;
} T[MaxSize];

/* 实现关于队列的判空, 创建, 入队,出队操作 */
typedef struct QNode *PtrToQNode;
struct QNode {
  int front, rear;   /* 队尾和队头的下标 */
  int Elements[MaxSize];
};
typedef PtrToQNode Queue;

Queue CreateQueue() {
  Queue Q;
  Q = (Queue)malloc(sizeof(struct QNode));
  Q->front = 0; Q->rear = 0;
  return Q;
}

int IsEmpty(Queue Q) {
  return Q->front == Q->rear;
}

void EnQueue(int Elem, Queue Q) {
  Q->Elements[Q->rear++] = Elem;
}

int DeQueue(Queue Q) {
  return Q->Elements[Q->front++];
}


int BuildTree() {
  int i, N, Root;
  char cl, cr;
  int check[MaxSize];

  scanf("%d", &N);
  for (i = 0; i < N; i++) check[i] = 0;

  for (i = 0; i < N; i++) {
    getchar();
    scanf("%c %c", &cl, &cr);
    if (cl != '-') {
      T[i].Left = cl - '0';
      check[T[i].Left] = 1;
    } else {
      T[i].Left = Null;
    }
    if (cr != '-') {
      T[i].Right = cr - '0';
      check[T[i].Right] = 1;
    } else {
      T[i].Right = Null;
    }
  }

  for (i = 0; i < N; i++) {   /* 找到根结点位置 */
    if (!check[i]) break;
  }
  Root = i;
  return Root;
}


void LevelTraverseTree(int Root) {
  Queue Q;
  int Tc;
  int ok, flag;
  flag = 0;
  Q = CreateQueue();
  EnQueue(Root, Q);

  while (!IsEmpty(Q)) {
    ok = 1;
    Tc = DeQueue(Q);

    if (T[Tc].Left != Null) {
      ok = 0;
      EnQueue(T[Tc].Left, Q);
    }
    if (T[Tc].Right != Null) {
      ok = 0;
      EnQueue(T[Tc].Right, Q);
    }
    if (ok) {
      /* 无左孩子且无右孩子 */
      if (!flag) {    /* 控制格式 */
        printf("%d", Tc); flag = 1;
      } else {
        printf(" %d", Tc);
      }
    }
  }
  printf("\n");
}


int main() {
  int Root;
  Root = BuildTree();
  LevelTraverseTree(Root);
  return 0;
}

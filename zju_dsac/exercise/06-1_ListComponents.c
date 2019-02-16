/* Copyright [2019] <mituh> */
/* 06-1_ListComponents.c */
/* 列出连通集, DFS和BFS基础训练*/

/*
输入样例:
8 6
0 7
0 1
2 0
4 1
2 4
3 5

输出样例:
{ 0 1 4 2 7 }
{ 3 5 }
{ 6 }
{ 0 1 2 7 4 }
{ 3 5 }
{ 6 }
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize_Q 110
typedef struct QNode *PtrToQNode;
typedef PtrToQNode Queue;
struct QNode {
  int Elements[MaxSize_Q];
  int front, rear;
};

Queue CreateQ() {
  Queue Q;
  Q = (Queue)malloc(sizeof(struct QNode));
  Q->front = Q->rear = 0;
  return Q;
}

void AddQ(Queue Q, int v) {
  Q->Elements[Q->rear++] = v;
}

int DeleteQ(Queue Q) {
  return Q->Elements[Q->front++];
}

int IsEmpty(Queue Q) {
  return (Q->front == Q->rear);
}

#define MaxSize 10
int G[MaxSize][MaxSize];
int N, E;
int visited[MaxSize];

void BuildG() {
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      G[i][j] = 0;
    }
  }
}

void ResetVisited() {
  int i;
  for (i = 0; i < N; i++) {
    visited[i] = 0;
  }
}

void Visit(int V) {
  printf("%d ", V);
}

void DFS(int V) {
  int i;
  Visit(V);
  visited[V] = 1;
  for (i = 0; i < N; i++) {
    if (G[V][i] && !visited[i]) {
      DFS(i);
    }
  }
}

void ListComponents_DFS() {
  int V;
  ResetVisited();
  for (V = 0; V < N; V++) {
    if (!visited[V]) {
      printf("{ ");
      DFS(V);
      printf("}\n");
    }
  }
}

void BFS(int V) {
  int i, temp_V;
  Queue Q;
  Q = CreateQ();
  AddQ(Q, V);
  while (!IsEmpty(Q)) {
    temp_V = DeleteQ(Q);
    if (!visited[temp_V]) {
      Visit(temp_V);
      visited[temp_V] = 1;
      for (i = 0; i < N; i++) {
        if (G[temp_V][i]) AddQ(Q, i);
      }
    }
  }
}

void ListComponents_BFS() {
  int V;
  ResetVisited();
  for (V = 0; V < N; V++) {
    if (!visited[V]) {
      printf("{ ");
      BFS(V);
      printf("}\n");
    }
  }
}

int main() {
  int i, V1, V2;
  scanf("%d %d\n", &N, &E);
  BuildG();
  for (i = 0; i < E; i++) {
    scanf("%d %d", &V1, &V2);    /* ??? scanf是否需要换行 */
    G[V1][V2] = 1;
    G[V2][V1] = 1;
  }
  ListComponents_DFS();
  ListComponents_BFS();
  return 0;
}

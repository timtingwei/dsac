/* Copyright [2019] <mituh> */
/* SDS.c */
/* 六度空间 不要记录层数空间的版本 */

#include <stdio.h>
#define MaxVertexNum 100
#define Vertex int
#define WeightType int
#define DataType char


typedef struct GNode *PtrToGNode;
struct GNode {
  int Nv;
  int Ne;
  WeightType G[MaxVertexNum][MaxVertexNum];
  DataType Data[MaxVertexNum];
  int Layers[MaxVertexNum];
};
typedef PtrToGNode MGraph;


MGraph G;
int visited[MaxVertexNum];

void ResetLayers() {
  int i;
  for (i = 0; i < MaxVertexNum; i++) {
    G->Layers[i] = 0;
  }
}

void SDS() {
  Vertex V;
  int N, count;

  for (V = 0; V < N; V++) {
    count = BFS(V);   /* 宽度优先遍历 */
    printf("%lf", (double)count / N);
  }
}

int BFS(Vertex V) {
  Vertex W;
  int count;
  int level, last, tail;
  level = 0;
  visited[V] = true; count = 1;
  level = 0; last = V;

  EnQueue(V, Q);
  while (!IsEmpty(Q)) {
    V = DeQueue(Q);
    for (W = 0; W < Graph->Nv; W++) {
      if (Graph->G[W] != 0) {
        if (!visited[W]) {
          visited[W] = true;
          EnQueue(W, Q); count++;
          tail = W;
        }
      }
    }
    if (V == last) {
      level++; last = tail;
    }
    if (level == 6) break;
  }
  return count;
}

/*
int BFS(Vertex V) {
  int count; Vertex
  visited[V] = 1;
  count = 1;
  EnQueue(V, Q);
  while (!IsEmpty(Q)) {
    V = DeQueue(Q);
    if (Graph->Layers[V] == 6) break;

    for (W = 0; W < Graph->Nv; W++) {
      if (Graph->G[W] != 0) {
        if (!visited[W]) {
          visited[W] = 1;
          EnQueue(W, Q);
          Graph->Layers[W] = Graph->Layers[V] + 1;
          count++;
        }
      }
    }
  }
  return count;
}
*/

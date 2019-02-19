
/* Copyright [2019] <mituh> */
/* 07-1_HarryPotterExam-Floyd.c */
/* 哈利波特的考试 有权图的多源最短路径 */

/* 建图和调用Floyd算法 */

#include <stdio.h>
#include <stdlib.h>
#define INFINITY 65535
#define MaxSize 100
#define ElementType int
#define WeightType int
#define Vertex int


typedef struct GNode *PtrToGNode;
typedef PtrToGNode *MGraph;
struct GNode {
  int Nv;
  int Ne;
  ElementType G[MaxSize][MaxSize];
};

typedef struct ENode *PtrToENode;
typedef PtrToENode Edge;
struct ENode {
  Vertex V1, V2;
  WeightType Weight;
};

MGraph CreateGraph(int VertexNum) {
  MGraph Graph;
  Vertex V, W;
  Graph = (MGraph)malloc(sizeof(struct GNode));
  Graph->Nv = VertexNum;
  Graph->Ne = 0;
  for (V = 0; V < Graph->Nv; V++) {
    for (W = 0; W < Graph->Nv; W++) {
      Graph->G[V][W] = INFINITY;   /* 跟D有关, 初始化成无穷大 */
    }
  }
  return Graph;
}

void InsertEdge(MGraph Graph, Edge E) {
  Graph->G[E->V1][E->V2] = E->Weight;
  Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph() {
  MGraph Graph;
  Edge E;
  int i, Nv;

  scanf("%d", &Nv);
  CreateGraph(Nv);
  scanf("%d", &(Graph->Ne));
  if (Graph->Ne != 0) {
    for (i = 0; i < Graph->Ne; i++) {
      E = (Edge)malloc(sizeof(struct ENode));
      scanf("%d %d %d", &(E->V1), &(E->V2), &(E->Weight));
      E->V1--; E->V2--;
      InsertEdge(Graph, E);
    }
  }
  return Graph;
}

void Floyd(MGraph Graph, WeightType D[][MaxSize]) {
  Vertex i, j, k;

  for (i = 0; i < Graph->Nv; i++) {
    for (j = 0; j < Graph->Nv; j++) {
      D[i][j] = Graph->G[i][j];
    }
  }

  for (k = 0; k < Graph->Nv; k++) {
    for (i = 0; i < Graph->Nv; i++) {
      for (j = 0; j < Graph->Nv; j++) {
        if (D[i][k] + D[k][j] < D[i][j]) {
          D[i][j] = D[i][k] + D[k][j];
        }
      }
    }
  }
}

WeightType FindMaxDist(WeightType D[][MaxSize], Vertex i, int N) {
  WeightType MaxDist;
  Vertex j;

  MaxDist = 0;
  for (j = 0; j < N; j++) {
    if (i != j && D[i][j] > MaxDist) {
      MaxDist = D[i][j];
    }
  }
  return MaxDist;
}

void FindAnimal(MGraph Graph) {
  WeightType D[MaxSize][MaxSize], MaxDist, MinDist;
  Vertex Animal, i;

  Floyd(Graph, D);
  MinDist = INFINITY;
  for (i = 0; i < Graph->Nv; i++) {
    MaxDist = FindMaxDist(D, i, Graph->Nv);
    if (MaxDist == INFINITY) {
      printf("0\n");
      return;
    } else {
      if (MaxDist < MinDist) {
        MinDist = MaxDist;
        Animal = i+1;
      }
    }
  }
  printf("%d %d\n", Animal, MinDist);
}

int main() {
  MGraph Graph;
  Graph = BuildGraph(Graph);
  FindAnimal(Graph);
  return 0;
}


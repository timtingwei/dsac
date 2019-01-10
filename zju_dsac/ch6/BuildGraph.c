/* Copyright [2019] <mituh> */
/* BuildGraph.c */
/* 图的建立 */


#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100
#define INFINITY 65535
typedef int WeightType;
typedef int DataType;
typedef int Vertex;

typedef struct GNode *PtrToGNode;
struct GNode {
  int Nv;
  int Ne;
  WeightType G[MaxVertexNum][MaxVertexNum];
  DataType Data[MaxVertexNum];
};

typedef PtrToGNode MGraph;

typedef struct ENode *PtrToENode;
struct ENode {
  Vertex V1, V2;
  WeightType Weight;
};
typedef PtrToENode Edge;

MGraph CreateGraph(int VertexNum) {
  MGraph Graph;
  Vertex V, W;

  Graph = malloc(sizeof(struct GNode));
  Graph->Nv = VertexNum;                    /* 顶点数量 */
  Graph->Ne = 0;                            /* 边的条数 */
  for (V = 0; V < Graph->Nv; V++) {
    for (W = 0; W < Graph->Nv; W++) {
      Graph->G[V][W] = INFINITY;            /* 结点的权 */
    }
  }
  return Graph;
}

void InsertEdge(MGraph Graph, Edge E) {
  Graph->G[E->V1][E->V2] = E->Weight;
  /* 如果图是无向图 */
  Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph() {
  MGraph Graph;
  Edge E;
  Vertex V;
  int Nv, i;


  scanf("%d", &Nv);
  Graph = CreateGraph(Nv);
  scanf("%d", &Graph->Ne);
  if (Graph->Ne != 0) {
    E = malloc(sizeof(struct ENode));
    for (i = 0; i < Graph->Ne; i++) {
      scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);     /* 修改E变量的数据 */
      InsertEdge(Graph, E);
    }
  }

  /* 若有顶点数据 */
  for (V = 0; V < Graph->Nv; V++) {
    scanf(" %d", &Graph->Data[V]);
  }

  return Graph;
}

/* Copyright [2019] <mituh> */
/* BuildLGraph.c */
/* 邻接表 图的建立 */

#define MaxVertexNum 100
#define WeightType int
#define DataType int
#define Vertex int

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode {
  int Nv;   /* 顶点数 */
  int Ne;   /* 边数 */
  AdjList G;  /* 邻接表 */
};
typedef PtrToGNode LGraph;

/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode {
  Vertex V1, V2;   /* 有向边 <V1, V2> */
  WeightType Weight;
};
typedef PtrToENode Edge;

/* 顶点表头结点的定义 */
typedef struct Vnode {
  PtrToAdjVNode FirstEdege;
  DataType Data;
}AdjList[MaxVertexNum];



/* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
  Vertex AdjV;   /* 邻接点下标 */
  WeightType Weight;   /* 边权重 */
  PtrToAdjVNode Next;  /* 指向下一个邻接点的指针 */
};


/* 初始化一个包含所有顶点, 无边的图 */
LGraph CreateGraph(int VertexNum) {
  LGraph Graph;
  Vertex V;

  Graph = (LGraph)malloc(sizeof(struct GNode));
  Graph->Nv = VertexNum;
  Graph->Ne = 0;
  for (V = 0; V < Graph->Nv; V++) {
    Graph->G[i].FirstEdge = NULL;    /* 每个表头结点指向空结点 */
  }
  return Graph;
}

/* 插入一条边(差异较大的函数) */
void InsertEdge(LGraph Graph, Edge E) {
  PtrToAdjVNode NewNode;

  /* 插入边<V1, V2> */
  /* 为V2建立新的邻接结点 */
  NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
  NewNode->AdjV = E->V2;
  NewNode->Weight = E->Weight;
  /* 将V2插入V1的表头 */
  NewNode->Next = Graph->G[E->V1].FirstEdge;
  Graph->G[E->V1].FirstEdge = NewNode;

  /* 若是无向图, 还要插入边<V2, V1> */
  /* 为V2建立新的邻接结点 */
  NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));  /* 重新申请 */
  NewNode->AdjV = E->V1;
  NewNode->Weight = E->Weight;
  /* 将V2插入V1的表头 */
  NewNode->Next = Graph->G[E->V2].FirstEdge;
  Graph->G[E->V2].FirstEdge = NewNode;

}


LGraph BuildGraph() {
  LGraph Graph;
  Edge E;
  Vertex V;
  int i, Nv;

  scanf("%d", &Nv);
  Graph = CreateGraph(Nv);

  scanf("%d", &(Graph->Ne));
  if (Graph->Ne != 0) {
    E = (Edge)malloc(sizeof(struct ENode));
    for (i = 0; i < Graph->Ne; i++) {
      scanf("%d %d %d", &(E->V1), &(E->V2), &(E->Weight));
          /* 若权重是其他类型, 替换%d */
      InsertEdge(Graph, E);
    }
  }

  /* 读入表头结点信息 */
  for (V = 0; V < Graph->Nv; V++) {
    scanf("%c", &(Graph->G[V]));
  }
  return Graph;
}

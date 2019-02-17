/* Copyright [2019] <mituh> */
/* FindMinDist-Unweighted.c */
/* 无权图的单源最短路径 */

/* 给出图, 从顶点V出发到各个顶点的最短路径, 以及到W的路径 */


#define MaxSize 10
int dist[MaxSize];
int path[MaxSize];
/* 初始化距离和路径数组 */
void ResetDistAndPath(Vertex V) {
  int i;
  for (i = 0; i < MaxSize; i++) {
    dist[i] = path[i] = -1;
  }
  dist[V] = 0;
}


void Unweighted_FindMinDist(Vertex V) {

  EnQueue(Q, W);
  while (!IsEmpty(Q)) {
    V = Dequeue(Q);
    for (V的每个邻接点W) {
      if (dist[W] == -1) {
        dist[W] = dist[V]+1;
        path[W] = V;
        Enqueue(Q, W);
      }
    }
  }
}

/* 求源点到顶点W的路径 */
void PrintPath(Vertex V, Vertex W) {
  Stack S;  /* 利用栈的特性 顺序压入, 倒序输出 */

  for ( ; path[W] != V; W = path[W]) {
    Push(S, W);
  }
  printf("%d ", V);
  while (!IsEmpty_stack(S)) {
    printf("%d ", Pop(S));
  }
}


int main() {
  /* 读图 */

  int V;
  ResetDistAndPath(V);
  Unweighted_FindMinDist(V);
  
  return 0;
}

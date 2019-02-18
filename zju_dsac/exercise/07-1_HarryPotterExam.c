/* Copyright [2019] <mituh> */
/* 07-1_HarryPotterExam.c */
/* 哈利波特的考试 有权图的多源最短路径 */


#include <stdio.h>
#define MaxSize 110
#define INFINITY 233333
int N, E;
int rst, max_dist;   /* 带去的动物和最长变形魔咒 */
int G[MaxSize][MaxSize];
int dist[MaxSize];
int path[MaxSize];
int collected[MaxSize];

void ReadGraph() {
  int i, j, v1, v2, weight;
  /* 建空图 */
  for (i = 1; i <= N; i++) {
    for (j = 1; j <= N; j++) {
      G[i][j] = -1;
    }
  }

  for (i = 0; i < E; i++) {
    scanf("%d %d %d", &v1, &v2, &weight);
    G[v1][v2] = weight;
    G[v2][v1] = weight;
  }
}

int root[MaxSize];
int GetRoot(int V) {
  while (root[V] >= 0) {
    V = root[V];
  }
  return V;
}

int IsLinked() {
  /* 判断是否为连通图 */
  int v, w, cnt, Root1, Root2;
  for (v = 1; v <= N; v++) {
    root[v] = -1;
  }
  for (v = 1; v <= N; v++) {
    for (w = 1; w <= N; w++) {
      if (G[v][w] != -1) {
        Root1 = GetRoot(v);
        Root2 = GetRoot(w);
        if (Root1 < Root2) {  /* R2小 挂在R1上 */
          root[Root1] += root[Root2];
          root[Root2] = Root1;
        }
      }
    }
  }

  cnt = 0;
  for (v = 1; v <= N; v++) {
    if (root[v] < 0) cnt++;
  }
  if (cnt == 1) {
    return 1;
  } else {
    return 0;
  }
}

void ResetDistAndPathAndCollected(int s) {
  int i, w;
  for (i = 1; i <= N; i++) {
    dist[i] = INFINITY;
    path[i] = -1;
    collected[i] = 0;
  }
  dist[s] = 0;
  collected[s] = 1;
  for (w = 1; w <= N; w++) {
    if (G[s][w] != -1) {
      dist[w] = G[s][w];
      path[w] = s;
    }
  }
}

int FindMin() {
  int v, min, rst_v;
  min = INFINITY; rst_v = -1;
  for (v = 1; v <= N; v++) {
    if (!collected[v] && dist[v] != INFINITY && dist[v] < min) {
      min = dist[v];
      rst_v = v;
    }
  }
  return rst_v;   /* 没找到返回-1, 找到返回顶点编号 */
}

void Dijkstra(int S) {
  /* 已初始化dist, path, collected数组 */
  int V, W;
  while (1) {
    V = FindMin();    /* 找出未被收录的dist最小顶点 */
    if (V == -1) {
      break;          /* 不存在这样的顶点 */
    }
    collected[V] = 1;
    for (W = 1; W <= N; W++) {
      if (G[V][W] != -1 && collected[W] == 0) {
        if (dist[V] + G[V][W] < dist[W]) {
          dist[W] = dist[V] + G[V][W];
          path[W] = V;
        }
      }
    }
  }
}

void FindPathShortest() {
  int i, s;
  int min_length, temp_length, temp_max_dist;
  min_length = INFINITY;
  for (s = 1; s <= N; s++) {
    temp_length = 0;
    temp_max_dist = 0;
    ResetDistAndPathAndCollected(s);
    Dijkstra(s);

    for (i = 1; i <= N; i++) {
      temp_length += dist[i];
      if (dist[i] > temp_max_dist) temp_max_dist = dist[i];
    }
    if (temp_length < min_length) {    /* 找出单源距离最小, 修改全局变量 */
      min_length = temp_length;
      rst = s;
      max_dist = temp_max_dist;
    }
  }
}

int main() {
  scanf("%d %d", &N, &E);
  int i, rst;
  ReadGraph();
  if (!IsLinked()) {
    printf("0\n");
  } else {
    FindPathShortest();
    printf("%d %d\n", rst, max_dist);
  }
  return 0;
}

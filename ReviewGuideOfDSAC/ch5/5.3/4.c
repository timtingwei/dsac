/* Copyright [2019] <mituh> */
/* ch5/4.c */
/* dfs, bfs思想判断是否有vi到vj的路径(邻接表) */

void dfs(LGraph G, int v, int s, int *ans_p) {
  int w;
  if (v == s) *ans_p = 1;    /* 访问到目标结点, 说明路径存在 */
  visited[v] = 1;
  for (w = G->vertices[v]->first; w >= 0; w = G->vertices[w]->next) {
    if (!visited[w]) {
      dfs(G, w, s, ans_p);
    }
  }
}

void bfs(LGraph G, int v, int s, int *ans_p) {
  int w, i;
  InitQueue(Q);       /* 初始化用于bfs记录结点的队列 */
  DeQueue(Q, v);
  while (!IsEmpty(Q)) {
    DeQueue(Q, v);
    visited[v] = 1;
    if (v == s) {
      *ans_p = 1;
      return;
    }
    for (w = G->vertices[v]->first; w >= 0; w = G->vertices[w]->next) {
      if (!visited[w]) {
        EnQueue(Q, w);
      }
    }
  }
}

int Judge(LGraph G, int vi, int vj) {
  int ans, i;
  int visited[MaxSize];
  for (i = 0; i < G->vexnum; i++) {
    visited[i] = 0;
  }
  ans = 0;
  dfs(G, vi, vj, &ans);       /* 在一次dfs中找, 从vi到vj的路径, 存在修改ans */
  /* bfs(G, vi, vj, &ans); */
  return ans;
}

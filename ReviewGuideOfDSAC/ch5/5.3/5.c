/* Copyright [2019] <mituh> */
/* 5.3/5.c */
/* 输出图中从vi到vj的所有简单路径 */

void FindPath(LGraph* G, int u, int v, int d, int path[]) {
  int w;
  ArcNode *p;
  path[d++] = u;                    // 路径长度+1, 记录路径
  if (u == v) {
    Print(path);                    // 找到路径则输出
  }
  p = G->adjlist[u].firstarc;       // p指向第一个邻接结点
  while (p != NULL) {
    w = p->adjvex;
    if (!visited[w]) {
      FindPath(G, w, v, d, path);
    }
    p = p->nextarc;
  }
  visited[u] = 0;                   // 恢复环境, 使结点重新适用
}

// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update
// Update

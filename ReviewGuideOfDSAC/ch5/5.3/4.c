/* Copyright [2019] <mituh> */
/* 5.3/4.c */
/* dfs, bfs思想判断是否有vi到vj的路径(邻接表) */
/*
void dfs(LGraph G, int v, int s, int *ans_p) {
  int w;
  if (v == s) *ans_p = 1;    // 访问到目标结点, 说明路径存在
  visited[v] = 1;
  for (w = G->vertices[v]->first; w >= 0; w = G->vertices[w]->next) {
    if (!visited[w]) {
      dfs(G, w, s, ans_p);
    }
  }
}

void bfs(LGraph G, int v, int s, int *ans_p) {
  int w, i;
  InitQueue(Q);       // 初始化用于bfs记录结点的队列
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
  dfs(G, vi, vj, &ans);       // 在一次dfs中找, 从vi到vj的路径, 存在修改ans
  // bfs(G, vi, vj, &ans);
  return ans;
}


// Update
*/

// 方法二: 思路大致相同, 把dfs和bfs直接改成独立的函数, 该函数又是判断函数

/* 递归判断是否存在vi到vj的路径 */
int Exist_Path_dfs(LGraph G, int i, int j) {
  int w;
  if (i == j) {
    return 1;
  } else {
    visited[i] = 1;
    for (w = FirstNeighbor(G, i); w >= 0; w = NextNeighbor(G, i, w)) {
      if (!visited[w] && Exist_Path_dfs(G, w, j)) {
        return 1;
      }  // if
    }  // for
  }  // else
}  // Exist_Path_dfs

/* bfs宽度遍历判断是否存在vi到vj的路径 */
int Exist_Path_bfs(LGraph G, int i, int j) {
  int v, w;
  InitQueue(Q);
  EnQueue(Q, i);
  while (!IsEmpty(Q)) {
    DeQueue(Q, v);
    visited[v] = 1;
    for (w = FirstNeighbor(G, v); w; w = NextNeighbor(G, v, w)) {
      if (w == j) {
        return 1;
      } else {
        EnQueue(Q, w);
      }  // else
    }  // for
  }  // while
  return 0;
}  // Exist_Path_bfs
